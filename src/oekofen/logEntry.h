#ifndef __LOG_ENTRY_H_
#define __LOG_ENTRY_H_

/* project includes */
#include "bufferTank.h"
#include "energy.h"
#include "environment.h"
#include "heater.h"
#include "heatingCircuit.h"
#include "hotWaterTank.h"

/* os includes */
#include <string>

namespace oekofen
{
  class LogEntry
  {
  public:
    LogEntry(const std::string &header, const std::string &logline);
    virtual ~LogEntry();
    virtual std::string exportLogLine() const;
    virtual Environment getEnv() { return this->glo_;}
  private:
    Environment glo_;
    Heater pe1_;
    BufferTank pU3_;
    HeatingCircuit hC3_;
    HeatingCircuit hC5_;
    HeatingCircuit hC6_;
    HotWaterTank ww2_;
    Energy en_;
  }; // class LogEntry
} // namespace oekofen
#endif // __LOG_ENTRY_H_
