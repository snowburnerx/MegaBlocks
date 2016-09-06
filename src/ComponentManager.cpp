//
// Created by matthew on 9/4/16.
//

#include "ComponentManager.h"

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

    // Read all the files in the directories listed in the config file

    std::vector<std::string> filenames = std::vector<std::string>();

    for (int i = 0; i < filenames.size(); i++) {
        // Create and store the entry

        YAML::Node configData = YAML::Load(filenames[i]);

        if (configData["name"]) {

            for (YAML::const_iterator it=configData.begin(); it != configData.end(); ++it) {

                std::string key = it->first.as<std::string>();
                std::string filename = it->as<std::string>();

                sharedManager->componentDatabase.insert(std::pair<std::string, std::string>(key, filename));
            }

        } else {
            ROS_WARN("%s does not contain a entry for \'name\'. It will be ignored.", filenames[i].c_str());
        }

    }
}

std::string ComponentManager::getComponentConfigFilename(std::string idString) {

    std::string toReturn;

    if (sharedManager->componentDatabase.count(idString)) {
        toReturn = sharedManager->componentDatabase[idString];
    } else {
        toReturn = "";
    }

    return toReturn;
}