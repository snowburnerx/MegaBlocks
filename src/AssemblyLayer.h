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
    AssemblyLayer(float zHeight);
    AssemblyLayer(float zHeight, int layerIndex);

    long getLayerIndex();
    void setLayerIndex(int newIndex);
    float getLayerZHeight();
    void setLayerZHeight(float newHeight);
    void addBuildComponent(BuildComponent* toAdd);
    unsigned long getNumberOfComponents();
    std::vector<BuildComponent*> getBuildComponents();

private:
    long layerIndex;
    float layerZHeight;
    std::vector<BuildComponent*> buildComponents;

};

#endif //PROJECT_ASSEMBLYLAYER_H
