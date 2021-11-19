#ifndef __ENVIRONMENT_H_
#define __ENVIRONMENT_H_

/* project specific includes */
#include "common/unit.h"
#include "dt/sensor.h"

/* os includes */
#include <string>

namespace oekofen
{
  class Environment : public Unit
  {
  public:
    Environment(const std::string &name);
    virtual ~Environment() {}
    virtual std::string getDate() const { return this->date_;}
    virtual std::string getTime() const { return this->time_;}
    virtual std::string getOutTemp() const { return this->outTemp_; }
    virtual std::string getOutTempCur() const { return this->outTempCur_; }
    virtual std::string getKt() const { return std::to_string(this->kt_.value);}
    virtual std::string getKtNom() const { return std::to_string(this->kt_.nominal);}
    virtual std::string getBr() const { return this->br_;}
    virtual std::string getSperrzeit() const { return std::to_string(this->sperrzeit_);}
    virtual std::string getPe1Br1() const { return this->PE1_BR1_;}
    virtual std::string getError1() const { return this->Fehler1_;}
    virtual std::string getError2() const { return this->Fehler2_;}
    virtual std::string getError3() const { return this->Fehler3_;}
    virtual void setDate(const std::string &value);
    virtual void setTime(const std::string &value);
    virtual void setOutTemp(const std::string &value);
    virtual void setOutTempCur(const std::string &value);
    virtual void setKt(const std::string &value);
    virtual void setKtNom(const std::string &value);
    virtual void setBr(const std::string &value);
    virtual void setSperrzeit(const std::string &value);
    virtual void setPE1_BR1(const std::string &value);
    virtual void setFehler1(const std::string &value);
    virtual void setFehler2(const std::string &value);
    virtual void setFehler3(const std::string &value);
    virtual std::string exportLogLine() const;
  private:
    std::string date_;       ///< Datum - date of log entry
    std::string time_;       ///< Zeit - time of log entry
    std::string outTemp_;    ///< AT [°C] - outside temperature in C
    std::string outTempCur_; ///< AT akt [°C] - current outside temp in C
    dt::Sensor kt_;
    std::string br_;
    uint8_t sperrzeit_;
    std::string PE1_BR1_;
    std::string Fehler1_;
    std::string Fehler2_;
    std::string Fehler3_;
  };
} // namespace oekofen
#endif // __ENVIRONMENT_H_
