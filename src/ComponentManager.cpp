//
// Created by matthew on 9/4/16.
//

#include "ComponentManager.h"

ComponentManager::ComponentManager() {
    this->componentDatabase = std::map<std::string, std::string>();

    loadDatabase();
}

void ComponentManager::loadDatabase() {

    // Read all the files in the directories listed in the config file

    std::vector<std::string> filenames = std::vector<std::string>();

    for (int i = 0; i < filenames.size(); i++) {
        // Create and store the entry

        YAML::Node configData = YAML::Load(filenames[i]);

        if (configData["name"] != NULL) {

            std::pair<std::string, std::string> entry = std::pair<std::string, std::string> (
                    configData["name"].as<std::string>(), filenames[i]
            );

        } else {
            ROS_WARN("%s does not contain a entry for \'name\'. It will be ignored.", filenames[i].c_str());
        }

    }
}

static std::string ComponentManager::getComponentConfigFilename(std::string idString) {

    std::string toReturn;

    if (ComponentManager::sharedManager.componentDatabase[idString] != NULL) {
        toReturn = ComponentManager::sharedManager.componentDatabase[idString];
    } else {
        toReturn = NULL;
    }

    return toReturn;
}