//
// Created by matthew on 9/4/16.
//

#include "BuildComponent.h"

void BuildComponent::loadConfigFromYAML(std::string filename) {

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

            this->hotspots.push_back(HotspotMegaBlock(x, y, z));
        }
    }
}