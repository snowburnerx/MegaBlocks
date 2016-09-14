//
// Created by matthew on 9/14/16.
//

#ifndef PROJECT_LAYEREDASSEMBLY_H
#define PROJECT_LAYEREDASSEMBLY_H

#include "BaseAssembly.h"

class LayeredAssembly: public BaseAssembly {

public:
    LayeredAssembly();

    void addLayer(AssemblyLayer* toAdd);
    unsigned long getNumberOfLayers();
    BuildComponent* getNextComponent();
    unsigned long getNumberOfComponentsRemaining();
};

#endif //PROJECT_LAYEREDASSEMBLY_H
