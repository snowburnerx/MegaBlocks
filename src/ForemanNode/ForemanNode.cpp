//
// Created by matthew on 9/14/16.
//

#include "ForemanNode.h"

int main(int argc, char** argv) {

    // Initialize the node
    ros::init(argc, argv, "", ros::init_options::AnonymousName);

    // Initialize AssemblerFactory
    AssemblerNodeFactory::getSharedFactory();

    ForemanNode node = ForemanNode();

    ros::Rate rate = ros::Rate(1.0);

    while (ros::ok()) {
        rate.sleep();
        ros::spin();
    }

    return 0;
}

ForemanNode::ForemanNode() {

    this->nh = ros::NodeHandle();
    this->newJobRequestService = nh.advertiseService("foreman/SubmitJobRequest", &ForemanNode::newJobRequestServiceCallback, this);
}

JobStatus ForemanNode::getJobStatues() {
    return this->jobStatus;
}

bool ForemanNode::newJobRequestServiceCallback(assembler::NewJobRequestRequest& request,
                                               assembler::NewJobRequestResponse& response) {

    YAML::Node assemblyConfig;

    std::cout << "Request data: " << request.requestData << '\n';

    if (request.isFilepath) {

        if (fs::exists(request.requestData)
            && (fs::extension(request.requestData) == ".yml" || fs::extension(request.requestData) == ".yaml")) {

            assemblyConfig = YAML::LoadFile(request.requestData);

        } else {
            response.confirmation = 0;
            return true;
        }

    } else {

        assemblyConfig = YAML::Load(request.requestData);
    }

    // Check for valid YAML
    if (!assemblyConfig.IsDefined()) {
        response.confirmation = 0;
        return true;
    }

    std::string typeID = assemblyConfig["assemblerTypeID"].as<std::string>();

    boost::shared_ptr<BaseAssemblerNode> node = AssemblerNodeFactory::getAssemblerWithType(typeID);

    node.get()->init(assemblyConfig);

    response.confirmation = 1;

    return true;
}