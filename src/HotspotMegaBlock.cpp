//
// Created by matt on 8/29/16.
//

#include "HotspotMegaBlock.h"

HotspotMegaBlock::HotspotMegaBlock() {

}

HotspotMegaBlock::HotspotMegaBlock(double x, double y, double z) {

    geometry_msgs::Point pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;

    this->position = pos;
}

HotspotMegaBlock::HotspotMegaBlock(geometry_msgs::Point position) {
    this->position = position;
}

HotspotMegaBlock::HotspotMegaBlock(std::string configData) {

    YAML::Node data = YAML::Load(configData);

    geometry_msgs::Point pos;
    pos.x = data["x"].as<double>();
    pos.y = data["y"].as<double>();
    pos.z = data["z"].as<double>();

    this->position = pos;
}

geometry_msgs::Point HotspotMegaBlock::getPosition() {
    return  this->position;
}

