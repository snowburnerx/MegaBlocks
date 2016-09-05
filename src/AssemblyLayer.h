//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_ASSEMBLYLAYER_H
#define PROJECT_ASSEMBLYLAYER_H

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include "BuildComponent.h"
#include <string>
#include <vector>

class AssemblyLayer {

public:
    AssemblyLayer(float zHeight, int layerIndex);

    int getLayerIndex();
    void setLayerIndex(int newIndex);
    float getLayerZHeight();
    void setLayerZHeight(float newHeight);
    void addBuildComponent(BuildComponent toAdd);
    unsigned long getNumberOfComponents();
    std::vector<BuildComponent> getBuildComponents();

private:
    int layerIndex;
    float layerZHeight;
    std::vector<BuildComponent> buildComponents;

};

#endif //PROJECT_ASSEMBLYLAYER_H
