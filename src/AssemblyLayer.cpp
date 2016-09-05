//
// Created by matthew on 9/4/16.
//

#include "AssemblyLayer.h"

AssemblyLayer::AssemblyLayer(float zHeight, int layerIndex) {
    this->layerZHeight = layerZHeight;
    this->layerIndex = layerIndex;

    this->buildComponents = std::vector<BuildComponent>();
}

int AssemblyLayer::getLayerIndex() {
    return this->layerIndex;
}

void AssemblyLayer::setLayerIndex(int newIndex) {
    this->layerIndex = newIndex;
}

float AssemblyLayer::getLayerZHeight() {
    return this->layerZHeight;
}

void AssemblyLayer::setLayerZHeight(float newHeight) {
    this->layerZHeight = newHeight;
}

unsigned long AssemblyLayer::getNumberOfComponents() {
    return this->buildComponents.size();
}

void AssemblyLayer::addBuildComponent(BuildComponent toAdd) {
    this->buildComponents.push_back(toAdd);
}

std::vector<BuildComponent> AssemblyLayer::getBuildComponents() {
    return this->buildComponents;
}