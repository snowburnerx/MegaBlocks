//
// Created by Matthew Atkins on 9/4/16.
//

#ifndef PROJECT_BUILDCOMPONENT_H
#define PROJECT_BUILDCOMPONENT_H

#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Vector3.h>
#include <tf/tf.h>
#include <yaml-cpp/yaml.h>
#include <vector>
#include "HotspotMegaBlock.h"

/**
 * Abstract base class for all BuildComponent objects. Provides the minimum fields required for
 * a generic Assembler object. Subclass this to create custom components for use in Assebmlies.
 */
class BuildComponent {

public:
    std::string componentID; ///< A unique identifier indicating what kind of component this is.

protected:
    virtual void loadConfigFromYAML(std::string configFilename) = 0;
    geometry_msgs::Transform transform;
    geometry_msgs::Vector3 bounds;
    std::vector<Hotspot*> hotspots; ///< Vector of Hotspot objects for this objects. Each component must have at least one.
};

#endif //PROJECT_BUILDCOMPONENT_H
