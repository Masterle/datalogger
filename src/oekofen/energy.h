#ifndef __ENERGY_H_
#define __ENERGY_H_

/* project includes */
#include "common/unit.h"

/* os includes */
#include <string>

namespace oekofen
{
  class Energy : public Unit
  {
  public:
    Energy();
    virtual ~Energy();
    virtual std::string getPowerConsumption() const;
    virtual std::string getPowerDelivery() const;
    virtual std::string getPhase1() const;
    virtual std::string getPhase2() const;
    virtual std::string getPhase3() const;
    virtual std::string getThyristor() const;
    virtual std::string getPv() const;
    virtual std::string getDemand() const;
    virtual std::string getBatteryIn() const;
    virtual std::string getBatteryOut() const;
    virtual std::string getBatteryChg() const;
    virtual std::string getEnergyState() const;
    virtual void setPowerConsumption(const std::string &value);
    virtual void setPowerDelivery(const std::string &value);
    virtual void setPhase1(const std::string &value);
    virtual void setPhase2(const std::string &value);
    virtual void setPhase3(const std::string &value);
    virtual void setThyristor(const std::string &value);
    virtual void setPv(const std::string &value);
    virtual void setDemand(const std::string &value);
    virtual void setBatteryIn(const std::string &value);
    virtual void setBatteryOut(const std::string &value);
    virtual void setBatteryChg(const std::string &value);
    virtual void setEnergyState(const std::string &value);
    virtual std::string exportLogLine() const;
  private:
    std::string powerConsumption_;
    std::string powerDelivery_;
    std::string phase1_;
    std::string phase2_;
    std::string phase3_;
    std::string thyristor_;
    std::string pv_;
    std::string demand_;
    std::string batteryIn_;
    std::string batteryOut_;
    std::string batteryChg_;
    std::string energyState_;
  }; // class Energy
} // namespace oekofen
#endif // __ENERGY_H_
