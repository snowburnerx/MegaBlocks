//
// Created by matthew on 9/14/16.
//

#ifndef PROJECT_BASEASSEMBLY_H
#define PROJECT_BASEASSEMBLY_H

//#include <class_loader/class_loader.h>
#include <vector>
#include "../AssemblyLayer.h"

class BaseAssembly {

public:
    std::vector<AssemblyLayer*> getLayers() {
        return this->layers;
    }

    virtual void addLayer(AssemblyLayer* toAdd) = 0;
    virtual unsigned long getNumberOfLayers() = 0;
    virtual BuildComponent* getNextComponent() = 0;
    virtual unsigned long getNumberOfComponentsRemaining() = 0;

protected:
    std::vector<AssemblyLayer*> layers;

};

#endif //PROJECT_BASEASSEMBLY_H
