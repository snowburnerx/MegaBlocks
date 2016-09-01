//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOTMEGABLOCK_H
#define BAXTER_TESTING_HOTSPOTMEGABLOCK_H

#include "Hotspot.h"
#include <vector>
#include <string>
#include <geometry_msgs/Point.h>

class HotspotMegaBlock: public Hotspot {

    const std::string typeID = "MegaBlock";

public:

    HotspotMegaBlock();

    HotspotMegaBlock(float x, float y, float z);

    HotspotMegaBlock(geometry_msgs::Point position);

    geometry_msgs::Point getPosition();

private:
    geometry_msgs::Point position;

};

#endif //BAXTER_TESTING_HOTSPOTMEGABLOCK_H
