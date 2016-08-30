//
// Created by matt on 8/29/16.
//

#ifndef BAXTER_TESTING_HOTSPOT_H
#define BAXTER_TESTING_HOTSPOT_H

#include <ros/ros.h>

class Hotspot {

public:
    virtual bool validConnection(Hotspot proposedConnection) = false;
    virtual void getRobotMovement();
    virtual void getGoalVector();

    virtual double getRotationAngle();
    virtual void setRotationAngle(double newValue);

protected:
    double rotationAngle = 0.0;
};

#endif //BAXTER_TESTING_HOTSPOT_H
