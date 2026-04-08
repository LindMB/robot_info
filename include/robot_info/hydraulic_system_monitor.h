#pragma once
#include <string>

class HydraulicSystemMonitor {
public:
  const std::string &getHydraulicOilTemperature() const;
  const std::string &getHydraulicOilTankFillLevel() const;
  const std::string &getHydraulicOilPressure() const;

  void setHydraulicOilTemperature(const std::string temperature);
  void setHydraulicOilTankFillLevel(const std::string tankFillLevel);
  void setHydraulicOilPressure(const std::string pressure);

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};