//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOTMEGABLOCK_H
#define BAXTER_TESTING_HOTSPOTMEGABLOCK_H

#include "Hotspot.h"
#include <vector>
#include <string>
#include <geometry_msgs/Point.h>
#include <yaml-cpp/yaml.h>

class HotspotMegaBlock: public Hotspot {

    const std::string typeID = "megaBlock";

public:

    HotspotMegaBlock();

    HotspotMegaBlock(double x, double y, double z);

    HotspotMegaBlock(geometry_msgs::Point position);

    HotspotMegaBlock(std::string configData);

    geometry_msgs::Point getPosition();

private:
    geometry_msgs::Point position;

};

#endif //BAXTER_TESTING_HOTSPOTMEGABLOCK_H
