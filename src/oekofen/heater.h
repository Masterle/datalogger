#ifndef __HEATER_H_
#define __HEATER_H_

/* project includes */
#include "common/unit.h"
#include "dt/sensor.h"

/* os includes */
#include <string>

namespace oekofen
{
  class Heater : public Unit
  {
  public:
    Heater(std::string name);
    virtual ~Heater();
    virtual std::string exportLogLine() const;
    virtual std::string getBoilerTemperature() const;
    virtual std::string getBoilerTemperatureNominal() const;
    virtual std::string getCircPumpEnable() const;
    virtual std::string getModulation() const;
    virtual std::string getFRT() const;
    virtual std::string getFRTnom() const;
    virtual std::string getFRTend() const;
    virtual std::string getInsertionTime() const;
    virtual std::string getPauseTime() const;
    virtual std::string getFanSpeed() const;
    virtual std::string getSuctionSpeed() const;
    virtual std::string getNegativePressure() const;
    virtual std::string getNegativePressureNom() const;
    virtual std::string getFillLevel() const;
    virtual std::string getFillLevelZWB() const;
    virtual std::string getStatus() const;
    virtual std::string getMotor_es() const;
    virtual std::string getMotor_ra() const;
    virtual std::string getMotor_res1() const;
    virtual std::string getMotor_turbine() const;
    virtual std::string getMotor_zuend() const;
    virtual std::string getMotor_uwinpercent() const;
    virtual std::string getMotor_av() const;
    virtual std::string getMotor_res2() const;
    virtual std::string getMotor_ma() const;
    virtual std::string getMotor_rm() const;
    virtual std::string getMotor_SM() const;
    virtual std::string getCap_RA() const;
    virtual std::string getCap_ZB() const;
    virtual std::string getAk() const;
    virtual std::string getSoakInterval() const;
    virtual std::string getDigIn1() const;
    virtual std::string getDigIn2() const;
    virtual void setBoilerTemperature(const std::string &value);
    virtual void setBoilerTemperatureNominal(const std::string &value);
    virtual void setCircPumpEnable(const std::string &value);
    virtual void setModulation(const std::string &value);
    virtual void setFRT(const std::string &value);
    virtual void setFRTnom(const std::string &value);
    virtual void setFRTend(const std::string &value);
    virtual void setInsertionTime(const std::string &value);
    virtual void setPauseTime(const std::string &value);
    virtual void setFanSpeed(const std::string &value);
    virtual void setSuctionSpeed(const std::string &value);
    virtual void setNegativePressure(const std::string &value);
    virtual void setNegativePressureNom(const std::string &value);
    virtual void setFillLevel(const std::string &value);
    virtual void setFillLevelZWB(const std::string &value);
    virtual void setStatus(const std::string &value);
    virtual void setMotor_es(const std::string &value);
    virtual void setMotor_ra(const std::string &value);
    virtual void setMotor_res1(const std::string &value);
    virtual void setMotor_turbine(const std::string &value);
    virtual void setMotor_zuend(const std::string &value);
    virtual void setMotor_uwinpercent(const std::string &value);
    virtual void setMotor_av(const std::string &value);
    virtual void setMotor_res2(const std::string &value);
    virtual void setMotor_ma(const std::string &value);
    virtual void setMotor_rm(const std::string &value);
    virtual void setMotor_SM(const std::string &value);
    virtual void setCap_RA(const std::string &value);
    virtual void setCap_ZB(const std::string &value);
    virtual void setAk(const std::string &value);
    virtual void setSoakInterval(const std::string &value);
    virtual void setDigIn1(const std::string &value);
    virtual void setDigIn2(const std::string &value);
  private:
    dt::Sensor boiler_;
    std::string circPump_;
    std::string modulation_;
    std::string FRT_;
    std::string FRTnom_;
    std::string FRTend_;
    std::string insertionTime_;
    std::string pauseTime_;
    std::string fanSpeed_;
    std::string suctionSpeed_;
    std::string negativePressure_;
    std::string negativePressureNom_;
    std::string fillLevel_;
    std::string fillLevelZwb_;
    std::string status_;        ///< Status
    std::string motor_es_;
    std::string motor_ra_;
    std::string motor_res1_;
    std::string motor_turbine_;
    std::string motor_zuend_;
    std::string motor_uwinpercent_;
    std::string motor_av_;
    std::string motor_res2_;
    std::string motor_ma_;
    std::string motor_rm_;
    std::string motor_SM_;
    std::string cap_RA_;
    std::string cap_ZB_;
    std::string ak_;
    std::string soakInterval_;
    std::string digIn1_;
    std::string digIn2_;

  }; // class Hearter
} // namespace oekofen
#endif // __HEATER_H_
