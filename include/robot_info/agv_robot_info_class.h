#pragma once
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <string>

class AGVRobotInfo : public RobotInfo {

public:
  AGVRobotInfo(ros::NodeHandle *nh, std::string maximum_payload);
  void publish_data() override;

  ~AGVRobotInfo() = default;

private:
  std::string maximum_payload;
};