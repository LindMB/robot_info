#include "robot_info/hydraulic_system_monitor.h"

const std::string &HydraulicSystemMonitor::getHydraulicOilTemperature() const {
  return this->hydraulic_oil_temperature;
}

const std::string &
HydraulicSystemMonitor::getHydraulicOilTankFillLevel() const {
  return this->hydraulic_oil_tank_fill_level;
}

const std::string &HydraulicSystemMonitor::getHydraulicOilPressure() const {
  return this->hydraulic_oil_pressure;
}

void HydraulicSystemMonitor::setHydraulicOilTemperature(
    const std::string &temperature) {
  this->hydraulic_oil_temperature = temperature;
}
void HydraulicSystemMonitor::setHydraulicOilTankFillLevel(
    const std::string &tankFillLevel) {
  this->hydraulic_oil_tank_fill_level = tankFillLevel;
}
void HydraulicSystemMonitor::setHydraulicOilPressure(
    const std::string &pressure) {
  this->hydraulic_oil_pressure = pressure;
}
