#ifndef __SENSOR_H_
#define __SENSOR_H_

#include <string>

namespace oekofen
{
  namespace dt
  {
    enum Unit
    {
      UndefinedU,
      Celsius,
      Voltage,
      Ampere,
      Pascal
    };

    enum Type
    {
      UndefinedT = 0,
      Temperature = 1,
      Power = 2,
      Current = 3,
      Speed = 4,
      Pressure = 5
    };

    struct Sensor
    {
      double value;
      double nominal;
      Unit unit;
      Type type;
      Sensor() :
        value(0.0),
        nominal(0.0),
        unit(UndefinedU),
        type(UndefinedT)
      {

      }
      
      Sensor(const std::string &current, const std::string &nominal, Unit sensorunit, Type sensortype) :
        value(stod(current)),
        nominal(stod(nominal)),
        unit(sensorunit),
        type(sensortype)
      {
        // nothing to do yet
      }
    };
  } // namespace dt
} // namespace oekofen

#endif // __SENSOR_H_
