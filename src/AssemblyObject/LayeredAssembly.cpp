//
// Created by matthew on 9/14/16.
//

#include "LayeredAssembly.h"

//CLASS_LOADER_REGISTER_CLASS(LayeredAssembly, BaseAssembly)

LayeredAssembly::LayeredAssembly() {

}

void LayeredAssembly::addLayer(AssemblyLayer *toAdd) {
    this->layers.push_back(toAdd);
}

unsigned long LayeredAssembly::getNumberOfLayers() {
    return this->layers.size();
}

/// TODO: Actually implement this...
BuildComponent* LayeredAssembly::getNextComponent() {
    return NULL;
}

/// TODO: Actually implement this too...
unsigned long LayeredAssembly::getNumberOfComponentsRemaining() {
    return 0;
}