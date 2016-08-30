//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOTMEGABLOCK_H
#define BAXTER_TESTING_HOTSPOTMEGABLOCK_H

#include "Hotspot.h"
#include <vector>
#include <string>
#include <geometry_msgs/Point.h>

class HotspotMegablock: public Hotspot {

public:
    static const std::string typeID = "Megablock";

    HotspotMegablock();

    HotspotMegablock(float x, float y, float z);

    HotspotMegablock(geometry_msgs::PointPtr position);

    geometry_msgs::Point getPosition();

private:
    geometry_msgs::Point position;

};

#endif //BAXTER_TESTING_HOTSPOTMEGABLOCK_H
