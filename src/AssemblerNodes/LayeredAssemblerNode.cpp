//
// Created by Matthew Atkins on 9/13/16.
//

#include "LayeredAssemblerNode.h"

CLASS_LOADER_REGISTER_CLASS(LayeredAssemblerNode, BaseAssemblerNode)

int main(int argc, char** argv) {

    ros::init(argc, argv, "LayeredAssemblerNode", ros::init_options::AnonymousName);

    // Initialize componentManager
    ComponentManager::getSharedManager();

    LayeredAssemblerNode assemblerNode = LayeredAssemblerNode();

    while (ros::ok()) {
        ros::Rate rate = ros::Rate(1.0);
        rate.sleep();
        ros::spin();
    }

    return 0;
}

LayeredAssemblerNode::LayeredAssemblerNode() {

    this->nh = ros::NodeHandle();

    // Initialize data structures
    this->layers = std::vector<AssemblyLayer>();

    // TODO: This is for testing only. Change this to some other kind of input. A topic or service call?
    //init("/home/matthew/Documents/Projects/baxter_testing/src/MegaBlocks/include/Example Assembly.yml");
}

void LayeredAssemblerNode::init(std::string configFilepath) {

    if (initialized) {
        ROS_WARN("AssemblerNode already initialized.");
        return;
    }

    ROS_INFO("Parsing assembly configuration file: %s", configFilepath.c_str());
    YAML::Node configRoot = YAML::LoadFile(configFilepath);
    init(configRoot);
}

void LayeredAssemblerNode::init(YAML::Node configRoot) {

    if (initialized) {
        ROS_WARN("AssemblerNode already initialized.");
        return;
    }

    YAML::Node layers = configRoot["layers"];
    std::cout << "Found " << layers.size() << " layers.\n";
    // Iterate over the layers, building them and the BuildComponents needed to complete the assembly
    for (YAML::const_iterator it = layers.begin(); it != layers.end(); ++it) {

        std::string yamlDump = YAML::Dump(it->first);
        std::cout << "Creating layer: " << yamlDump.c_str() << ": \n";
        buildAssemblyLayerFromConfig(it->second);
    }

    long compCount = 0;

    for (AssemblyLayer& l : this->layers) {
        compCount += l.getNumberOfComponents();
    }

    ROS_INFO("Finished reading assembly config.\n\tLayers: %li\n\tComponents: %li", this->layers.size(), compCount);

    initialized = true;
}

void LayeredAssemblerNode::buildAssemblyLayerFromConfig(YAML::Node layerConfig) {

    float zheight = layerConfig["zheight"].as<float>();

    // Create and add the new layer
    AssemblyLayer newLayer = AssemblyLayer(zheight);

    YAML::Node components = layerConfig["components"];

    for (YAML::const_iterator it = components.begin(); it != components.end(); ++it) {

        std::cout << "Creating part: " << YAML::Dump(it->first) << '\n';
        newLayer.addBuildComponent(new MegaBlock(it->second));
    }

    this->layers.push_back(newLayer);
}
