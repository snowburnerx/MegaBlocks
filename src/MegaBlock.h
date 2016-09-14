//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_MEGABLOCK_H
#define PROJECT_MEGABLOCK_H

#include "BuildComponent.h"
#include "ComponentManager.h"

class MegaBlock : public BuildComponent {

public:
    std::string color;
    MegaBlock(std::string assemblyData);
    MegaBlock(YAML::Node assemblyData);

protected:
    virtual void loadConfigFromYAML(std::string filename);
    void init(YAML::Node assemblyData);
};

#endif //PROJECT_MEGABLOCK_H
