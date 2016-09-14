//
// Created by matthew on 9/14/16.
//

#ifndef PROJECT_FOREMANNODE_H
#define PROJECT_FOREMANNODE_H

#include <ros/ros.h>
#include <class_loader/class_loader.h>
#include <assembler/NewJobRequest.h>
#include <yaml-cpp/yaml.h>
#include <boost/filesystem.hpp>
#include "../AssemblerNodes/AssemblerNodeFactory.h"

namespace fs = boost::filesystem;

enum class JobStatus {
    IDLE,
    BUILDING,
    FINISHED,
    COMPLETE
};

class ForemanNode {

public:
    ForemanNode();
    JobStatus getJobStatues();

private:
    JobStatus jobStatus = JobStatus::IDLE;
    ros::NodeHandle nh;
    ros::ServiceServer newJobRequestService;

    bool newJobRequestServiceCallback(assembler::NewJobRequestRequest& request,
                                      assembler::NewJobRequestResponse& response);

};
#endif //PROJECT_FOREMANNODE_H
