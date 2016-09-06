//
// Created by matthew on 9/4/16.
//

#ifndef PROJECT_MEGABLOCK_H
#define PROJECT_MEGABLOCK_H

#include "BuildComponent.h"
#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>

class MegaBlock : public BuildComponent {

public:
    std::string color;
    MegaBlock(std::string assemblyData);

protected:
    virtual void loadConfigFromYAML(std::string filename);
};

#endif //PROJECT_MEGABLOCK_H
