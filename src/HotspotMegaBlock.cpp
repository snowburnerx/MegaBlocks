//
// Created by matt on 8/29/16.
//

#include "include/assembler/HotspotMegablock.h"

HotspotMegaBlock::HotspotMegaBlock() {

}

HotspotMegaBlock::HotspotMegaBlock(float x, float y, float z) {

    geometry_msgs::Point pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;

    this->position = pos;
}

HotspotMegaBlock::HotspotMegaBlock(geometry_msgs::PointPtr position) {

    this->position = position;
}

