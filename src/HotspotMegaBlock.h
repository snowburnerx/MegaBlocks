//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOTMEGABLOCK_H
#define BAXTER_TESTING_HOTSPOTMEGABLOCK_H

#include "Hotspot.h"
#include <vector>
#include <geometry_msgs/Point.h>

class HotspotMegaBlock: public Hotspot {

    const std::string typeID = "megaBlock";

public:

    HotspotMegaBlock();
    HotspotMegaBlock(double x, double y, double z);
    HotspotMegaBlock(geometry_msgs::Point position);
    HotspotMegaBlock(std::string configData);

    geometry_msgs::Point getPosition();

    //From Hotspot
    virtual bool validConnection(Hotspot* proposedConnection);
    virtual void getRobotMovement();
    virtual geometry_msgs::Vector3 getGoalVector();
    virtual float getRotationAngle();
    virtual void setRotationAngle(float newValue);

private:
    float rotationAngle = 0.0;
    geometry_msgs::Point position;

};

#endif //BAXTER_TESTING_HOTSPOTMEGABLOCK_H
