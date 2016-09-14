//
// Created by matthew on 9/13/16.
//

#ifndef PROJECT_LAYEREDASSEMBLERNODE_H
#define PROJECT_LAYEREDASSEMBLERNODE_H

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <queue>
#include "AssemblerNodeFactory.h"
#include "../ComponentManager.h"
#include "../AssemblyLayer.h"
#include "../Hotspot.h"
#include "../MegaBlock.h"

//int main(int argc, char** argv);

class LayeredAssemblerNode: public BaseAssemblerNode {

public:

    LayeredAssemblerNode();
    virtual void init(std::string filepath);
    virtual void init(YAML::Node config);
//    BuildComponent getNextComponent();

private:
    ros::NodeHandle nh;
    ros::ServiceClient placePartClient;
    std::vector<AssemblyLayer> layers;
    std::queue<BuildComponent> buildQueue;

    void buildAssemblyLayerFromConfig(YAML::Node layerConfig);
//    void requestNextComponentCallback(const std_msgs::EmptyConstPtr&);

};

#endif //PROJECT_LAYEREDASSEMBLERNODE_H
