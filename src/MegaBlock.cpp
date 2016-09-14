//
// Created by matthew on 9/4/16.
//

#include "MegaBlock.h"


MegaBlock::MegaBlock(std::string assemblyData) {

    this->hotspots = std::vector<Hotspot*>();

    // Initialize remaining fields from assembly data
    YAML::Node data = YAML::Load(assemblyData);
    init(data);
}

MegaBlock::MegaBlock(YAML::Node assemblyData) {

    this->hotspots = std::vector<Hotspot*>();

    init(assemblyData);
}

void MegaBlock::init(YAML::Node assemblyData) {

    YAML::Node baseConfigData;

    if (assemblyData["typeID"]) {
        std::string filename = ComponentManager::getSharedManager()->getComponentConfigFilename(assemblyData["typeID"].as<std::string>());
//        std::cout << "Filename for component id '" << assemblyData["typeID"].as<std::string>() << "' is " << filename << "\n";
        baseConfigData = YAML::LoadFile(filename);
    }

    this->transform = geometry_msgs::Transform();

    this->transform.translation.x = (assemblyData["position"][0] != NULL) ? assemblyData["position"][0].as<double>() : 0.0;
    this->transform.translation.y = (assemblyData["position"][1] != NULL) ? assemblyData["position"][1].as<double>() : 0.0;
    this->transform.translation.z = (assemblyData["position"][2] != NULL) ? assemblyData["position"][2].as<double>() : 0.0;

    double yaw = (assemblyData["rotationAngle"] != NULL) ? assemblyData["rotationAngle"].as<double>() : 0.0;
    tf::Quaternion quat = tf::createQuaternionFromYaw(yaw);
    this->transform.rotation.x = quat.x();
    this->transform.rotation.y = quat.y();
    this->transform.rotation.z = quat.z();
    this->transform.rotation.w = quat.w();

    this->color = (assemblyData["color"] != NULL) ? assemblyData["color"].as<std::string>() : "GRAY";
}

void MegaBlock::loadConfigFromYAML(std::string filename) {

    YAML::Node config = YAML::LoadFile(filename);

    if (config["name"] != NULL) {
        this->componentID = config["name"].as<std::string>();
    }

    double bx, by, bz;

    if (config["bx"] != NULL) {
        bx = config["bx"].as<double>();
    }

    if (config["by"] != NULL) {
        by = config["by"].as<double>();
    }

    if (config["bz"] != NULL) {
        bz = config["bz"].as<double>();
    }

    this->bounds = geometry_msgs::Vector3();
    this->bounds.x = bx;
    this->bounds.y = by;
    this->bounds.z = bz;

    for (std::size_t i = 0; i < config["hotspots"].size(); i++) {

        // Iterate through each item in the hotspot entry
        char *entryName = {};
        sprintf(entryName, "h%li", i);
        YAML::Node hotspotEntry = config["hotspots"][entryName];

        if (hotspotEntry["type"].as<std::string>() == "megaBlock") {
            double x, y, z;

            x = hotspotEntry["x"].as<double>();
            y = hotspotEntry["y"].as<double>();
            z = hotspotEntry["z"].as<double>();

            this->hotspots.push_back(new HotspotMegaBlock(x, y, z));
        }
    }
}