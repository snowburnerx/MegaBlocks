//
// Created by matthew on 9/14/16.
//

#ifndef PROJECT_ASSEMBLERNODEFACTORY_H
#define PROJECT_ASSEMBLERNODEFACTORY_H

#include <class_loader/class_loader.h>
#include "BaseAssemblerNode.h"

class AssemblerNodeFactory {

public:
    static AssemblerNodeFactory* getSharedFactory();
    static boost::shared_ptr<BaseAssemblerNode> getAssemblerWithType(std::string typeID);

private:
    static class_loader::ClassLoader* assemblerLoader;
    static std::vector<std::string> availableAssemblers;
    static AssemblerNodeFactory* sharedFactory;
    AssemblerNodeFactory();

};

#endif //PROJECT_ASSEMBLERNODEFACTORY_H
