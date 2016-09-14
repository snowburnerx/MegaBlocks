//
// Created by matthew on 9/13/16.
//

#include <vector>
#include <yaml-cpp/yaml.h>

void buildComponent(YAML::Node componentData) {

    std::cout << "typeID: " << componentData["typeID"].as<std::string>() << '\n' \
              << "rotationAngle: " << componentData["rotationAngle"].as<std::string>() << '\n' \
              << "color: " << componentData["color"].as<std::string>() << '\n';

    YAML::Node pos = componentData["position"];

    for (int count = 0; count < 3; count++) {

        switch (count) {
            case 0:
                std::cout << "x: ";
                break;
            case 1:
                std::cout << "y: ";
                break;
            case 2:
                std::cout << "z: ";
                break;
            default:
                break;
        }

        std::cout << pos[count].as<float>() << '\n';
    }
}

void buildLayer(YAML::Node layerData) {

    std::cout << "zheight" << layerData["zheight"].as<float>() << '\n';

    YAML::Node components = layerData["components"];

    for (YAML::const_iterator it = components.begin(); it != components.end(); ++it) {

        std::cout << "Creating part: " << YAML::Dump(it->first) << '\n';
        buildComponent(it->second);
    }
}

int main(int argc, char** argv) {

    YAML::Node configRoot = YAML::LoadFile("/home/matthew/Documents/Projects/baxter_testing/src/MegaBlocks/include/Example Assembly.yml");

    std::cout << "name: " << configRoot["name"].as<std::string>().c_str() << '\n';

    YAML::Node layers = configRoot["layers"];

    for (YAML::const_iterator it = layers.begin(); it != layers.end(); ++it) {

        std::string yamlDump = YAML::Dump(it->first);
        std::cout << "Creating layer: " << yamlDump.c_str() << ": \n";
        buildLayer(it->second);
    }

    return 0;
}