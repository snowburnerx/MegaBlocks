//
// Created by matthew on 9/14/16.
//

#ifndef PROJECT_BASEASSEMBLERNODE_H
#define PROJECT_BASEASSEMBLERNODE_H

#include <class_loader/class_loader.h>
#include <yaml-cpp/yaml.h>

class BaseAssemblerNode {

public:
    virtual void init(std::string filepath) = 0;
    virtual void init(YAML::Node config) = 0;

protected:
    bool initialized = false;
};

#endif //PROJECT_BASEASSEMBLERNODE_H
