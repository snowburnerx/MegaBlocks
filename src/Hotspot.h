//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOT_H
#define BAXTER_TESTING_HOTSPOT_H

#include <geometry_msgs/Transform.h>
#include <yaml-cpp/yaml.h>

class Hotspot {

public:
    virtual bool validConnection(Hotspot* proposedConnection) = 0;
    virtual void getRobotMovement() = 0;
    virtual geometry_msgs::Vector3 getGoalVector() = 0;
    virtual float getRotationAngle() = 0;
    virtual void setRotationAngle(float newValue) = 0;

protected:
    float rotationAngle;
};

#endif //BAXTER_TESTING_HOTSPOT_H
