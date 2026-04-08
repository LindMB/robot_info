#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, std::string maximum_payload)
    : RobotInfo(nh, "Cooper100", "567A359", "169.254.5.180", "3.5.8") {

  this->maximum_payload = maximum_payload;

  this->hsm.setHydraulicOilTemperature("45");
  this->hsm.setHydraulicOilTankFillLevel("100");
  this->hsm.setHydraulicOilPressure("250");
}

void AGVRobotInfo::publish_data() {

  robotinfo_msgs::RobotInfo10Fields fields;
  fields.data_field_01 = "robot_description: " + this->robot_description;
  fields.data_field_02 = "serial_number: " + this->serial_number;
  fields.data_field_03 = "ip_address: " + this->ip_address;
  fields.data_field_04 = "firmware_version: " + this->firmware_version;
  fields.data_field_05 = "maximum_payload: " + this->maximum_payload + " Kg";
  fields.data_field_06 =
      "hydraulic_oil_temperature: " + this->hsm.getHydraulicOilTemperature() +
      "C";
  fields.data_field_07 = "hydraulic_oil_tank_fill_level: " +
                         this->hsm.getHydraulicOilTankFillLevel() + "%";
  fields.data_field_08 =
      "hydraulic_oil_pressure: " + this->hsm.getHydraulicOilPressure() + " bar";

  ros::Rate rate(1); // 1 msg per sec

  while (ros::ok()) {
    this->robot_info_pub.publish(fields);
    rate.sleep();
  }
}