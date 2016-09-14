//
// Created by matthew on 9/4/16.
//

#include "ComponentManager.h"

ComponentManager* ComponentManager::sharedManager = NULL;

ComponentManager::ComponentManager() {

    this->componentDatabase = std::map<std::string, std::string>();
    loadDatabase();
}


ComponentManager* ComponentManager::getSharedManager() {

    if (sharedManager == NULL) {
        sharedManager = new ComponentManager();
    }

    return sharedManager;
}


void ComponentManager::loadDatabase() {

    ROS_INFO("Loading component configuration files...");

    // Read all the files in the include/componentConfigs directory
    fs::path path("/home/matthew/Documents/Projects/baxter_testing/src/MegaBlocks/include/componentConfigs");
    fs::recursive_directory_iterator begin(path), end;
    std::vector<fs::directory_entry> fileList(begin, end);

    for (fs::directory_entry& f : fileList) {

        if (fs::is_directory(f)) {
        } else if (f.path().extension() == ".yml") {
            parseConfigYAMLFile(f.path().string());
        }
    }

    ROS_INFO("Finished loading component configuration files: %li components found.", this->componentDatabase.size());
}


void ComponentManager::parseConfigYAMLFile(std::string filepath) {

    YAML::Node configData = YAML::LoadFile(filepath);

    if (configData["name"]) {

        std::string name = configData["name"].as<std::string>();
        ROS_INFO("Found component config for %s", name.c_str());
        this->componentDatabase[name] = filepath;

    } else {
        ROS_WARN("%s does not contain a entry for \'name\'. It will be ignored.", filepath.c_str());
    }

}


std::string ComponentManager::getComponentConfigFilename(std::string idString) {

//    std::cout << "file for id '" << idString << "' requested.\n";
    std::string toReturn;

    if (sharedManager->componentDatabase.count(idString)) {
        toReturn = sharedManager->componentDatabase[idString];
    } else {
        toReturn = "";
    }

//    std::cout << "returning path: " << toReturn << " for that id.\n";

    return toReturn;
}