//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_COMPONENTMANAGER_H
#define PROJECT_COMPONENTMANAGER_H

#include <ros/ros.h>
#include <string>
#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>
#include "BuildComponent.h"

class ComponentManager {

public:
    static ComponentManager sharedManager = ComponentManager::ComponentManager();
    std::map<std::string, std::string> componentDatabase;
    static std::string getComponentConfigFilename(std::string idString);

private:
    ComponentManager();
    void loadDatabase();
};

#endif //PROJECT_COMPONENTMANAGER_H
