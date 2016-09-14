//
// Created by matthew on 9/14/16.
//

#include "AssemblerNodeFactory.h"

AssemblerNodeFactory* AssemblerNodeFactory::sharedFactory = NULL;
class_loader::ClassLoader* AssemblerNodeFactory::assemblerLoader = NULL;
std::vector<std::string> AssemblerNodeFactory::availableAssemblers;

AssemblerNodeFactory::AssemblerNodeFactory() {}

AssemblerNodeFactory* AssemblerNodeFactory::getSharedFactory() {

    if (sharedFactory == NULL) {

        try {
            sharedFactory = new AssemblerNodeFactory();
            assemblerLoader = new class_loader::ClassLoader("libassembler.so");
            availableAssemblers = assemblerLoader->getAvailableClasses<BaseAssemblerNode>();
        } catch (std::exception e) {
            std::cout << "Oops! " << e.what() << '\n';
            return NULL;
        }
    }

    return sharedFactory;
}

boost::shared_ptr<BaseAssemblerNode> AssemblerNodeFactory::getAssemblerWithType(std::string typeID) {

    // Check if typeID is available
    auto it = std::find(availableAssemblers.begin(), availableAssemblers.end(), typeID);

    if (it == availableAssemblers.end()) {
        std::cerr << "[WARNING - AssemblerNodeFactory]: No assembler with class '" << typeID << "'!\n";
        return NULL;
    }

    // Get this index for typeID
    int index = it - availableAssemblers.begin();

    boost::shared_ptr<BaseAssemblerNode> toReturn;

    try {
       toReturn = assemblerLoader->createInstance<BaseAssemblerNode>(availableAssemblers[index]);
    } catch (std::exception e) {
        std::cout << "Oops! " << e.what() << '\n';
    }

    return toReturn;
}