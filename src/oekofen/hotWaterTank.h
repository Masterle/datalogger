#ifndef __HOT_WATER_TANK_H_
#define __HOT_WATER_TANK_H_

/* project specific includes */
#include "common/unit.h"

/* os includes */
#include <string>

namespace oekofen
{
  class HotWaterTank : public Unit
  {
  public:
    HotWaterTank(std::string name);
    virtual ~HotWaterTank();
    virtual std::string exportLogLine() const;
    virtual std::string getTempOn() const;
    virtual std::string getTempOff() const;
    virtual std::string getTempNom() const;
    virtual std::string getPump() const;
    virtual std::string getStatus() const;
    virtual void setTempOn(const std::string &value);
    virtual void setTempOff(const std::string &value);
    virtual void setTempNom(const std::string &value);
    virtual void setPump(const std::string &value);
    virtual void setStatus(const std::string &value);
  private:
    std::string tempOn_;
    std::string tempOff_;
    std::string tempNom_;
    std::string pump_;
    std::string status_;
  }; // class HotWaterTank
} // namespace oekofen
#endif // __HOT_WATER_TANK_H_
