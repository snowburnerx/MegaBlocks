//
// Created by matthew on 9/4/16.
//

#include "BuildComponent.h"

BuildComponent::BuildComponent(std::string configFilename) {
    // Load basic config data from YAML file
    loadConfigFromYAML(configFilename);

    // Set default value for fields
    this->transform = geometry_msgs::Transform();
    this->transform.translation.x = 0.0;
    this->transform.translation.y = 0.0;
    this->transform.translation.z = 0.0;

    tf::Quaternion quat = tf::createQuaternionFromYaw(0.0);
    this->transform.rotation.x = quat.x();
    this->transform.rotation.y = quat.y();
    this->transform.rotation.z = quat.z();
    this->transform.rotation.w = quat.w();

    this->color = "GRAY";
}

BuildComponent::BuildComponent(std::string configFilename, std::string assemblyData) {

    // Load basic config data from YAML file
    loadConfigFromYAML(configFilename);

    // Initialize remaining fields from assembly data
    YAML::Node data = YAML::Load(assemblyData);

    this->transform = geometry_msgs::Transform();

    this->transform.translation.x = (data["position"][0] != NULL) ? data["position"][0].as<double>() : 0.0;
    this->transform.translation.y = (data["position"][1] != NULL) ? data["position"][1].as<double>() : 0.0;
    this->transform.translation.z = (data["position"][2] != NULL) ? data["position"][2].as<double>() : 0.0;

    double yaw = (data["rotationAngle"] != NULL) ? data["rotationAngle"].as<double>() : 0.0;
    tf::Quaternion quat = tf::createQuaternionFromYaw(yaw);
    this->transform.rotation.x = quat.x();
    this->transform.rotation.y = quat.y();
    this->transform.rotation.z = quat.z();
    this->transform.rotation.w = quat.w();

    this->color = (data["color"] != NULL) ? data["color"].as<std::string>() : "GRAY";
}

void BuildComponent::loadConfigFromYAML(std::string filename) {

    YAML::Node config = YAML::LoadFile(filename);

    if (config["name"] != NULL) {
        this->componentID =config["name"].as<std::string>();
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
    this->bounds.x = bx; this->bounds.y = by; this->bounds.z = bz;

    for (std::size_t i = 0; i < config["hotspots"].size(); i++) {

        // Iterate through each item in the hotspot entry
        char* entryName = {};
        sprintf(entryName, "h%li", i);
        YAML::Node hotspotEntry = config["hotspots"][entryName];

        if (hotspotEntry["type"].as<std::string>() == "megaBlock") {
            double x,y,z;

            x = hotspotEntry["x"].as<double>();
            y = hotspotEntry["y"].as<double>();
            z = hotspotEntry["z"].as<double>();

            this->hotspots.push_back(HotspotMegaBlock(x, y, z));
        }
    }
}