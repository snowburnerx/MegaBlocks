//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_BUILDCOMPONENT_H
#define PROJECT_BUILDCOMPONENT_H

#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Vector3.h>
#include <tf/tf.h>
#include <yaml-cpp/yaml.h>
#include <vector>
#include <string>
#include "HotspotMegaBlock.h"

/**
 * @todo Change this class to be the abstract base class for all build components and create a MegaBlock class.
 */

class BuildComponent {

public:
    std::string componentID;

protected:
    virtual void loadConfigFromYAML(std::string configFilename);
    geometry_msgs::Transform transform;
    geometry_msgs::Vector3 bounds;
    std::vector<Hotspot> hotspots;
};

#endif //PROJECT_BUILDCOMPONENT_H
