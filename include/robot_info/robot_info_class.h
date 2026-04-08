#pragma once
#include <ros/ros.h>
#include <string>

class RobotInfo {

public:
  RobotInfo(ros::NodeHandle *nh, std::string robot_description,
            std::string serial_number, std::string ip_address,
            std::string firmware_version);
  virtual void publish_data();

  ~RobotInfo() = default;

protected:
  std::string robot_description, serial_number;
  std::string ip_address, firmware_version;
  ros::Publisher robot_info_pub;
};