#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

RobotInfo::RobotInfo(ros::NodeHandle *nh, std::string robot_description,
                     std::string serial_number, std::string ip_address,
                     std::string firmware_version) {

  this->robot_description = robot_description;
  this->serial_number = serial_number;
  this->ip_address = ip_address;
  this->firmware_version = firmware_version;

  this->robot_info_pub =
      nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
}

void RobotInfo::publish_data() {

  robotinfo_msgs::RobotInfo10Fields fields;
  fields.data_field_01 = "robot_description: " + this->robot_description;
  fields.data_field_02 = "serial_number: " + this->serial_number;
  fields.data_field_03 = "ip_address: " + this->ip_address;
  fields.data_field_04 = "firmware_version: " + this->firmware_version;

  ros::Rate rate(1); // 1 msg per sec

  while (ros::ok()) {
    this->robot_info_pub.publish(fields);
    rate.sleep();
  }
}
