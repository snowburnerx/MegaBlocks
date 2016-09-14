//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_COMPONENTMANAGER_H
#define PROJECT_COMPONENTMANAGER_H

#include <ros/ros.h>
#include <ros/package.h>
#include <string>
#include <vector>
#include <map>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <boost/filesystem.hpp>
#include "BuildComponent.h"

namespace fs = boost::filesystem;

class ComponentManager {

public:
    std::map<std::string, std::string> componentDatabase;
    static std::string getComponentConfigFilename(std::string idString);
    static ComponentManager* getSharedManager();

private:
    ComponentManager();
    void loadDatabase();
    void parseConfigYAMLFile(std::string filepath);
    static ComponentManager* sharedManager;
};

#endif //PROJECT_COMPONENTMANAGER_H
