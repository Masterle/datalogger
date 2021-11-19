#ifndef __HEATING_CIRCUIT_H_
#define __HEATING_CIRCUIT_H_

/* project specific includes */
#include "common/unit.h"
#include "dt/sensor.h"

/* os includes */
#include <string>

namespace oekofen
{
  class HeatingCircuit : public Unit
  {
  public:
    HeatingCircuit(std::string name);
    virtual ~HeatingCircuit();
    virtual std::string exportLogLine() const;
    virtual std::string getFlow() const;
    virtual std::string getFlowNominal() const;
    virtual std::string getReturn() const;
    virtual std::string getReturnNominal() const;
    virtual std::string getPump() const;
    virtual std::string getMixer() const;
    virtual std::string getStatus() const;
    virtual void setFlow(const std::string &value);
    virtual void setFlowNominal(const std::string &value);
    virtual void setReturn(const std::string &value);
    virtual void setReturnNominal(const std::string &value);
    virtual void setPump(const std::string &value);
    virtual void setMixer(const std::string &value);
    virtual void setStatus(const std::string &value);
  private:
    dt::Sensor flow_;    ///< Vorlauf
    dt::Sensor return_;  ///< Rücklauf
    std::string pump_;   ///< Pumpe
    std::string mixer_;  ///< Mischer
    std::string status_; ///< Status
  }; // class Hearting Circuit
} // namespace oekofen
#endif // __HEATING_CIRCUIT_H_
