#include "bufferTank.h"

/* os includes */
#include <algorithm>

namespace oekofen
{
  BufferTank::BufferTank(std::string name) :
    Unit(name),
    up_(),
    mi_(),
    pump_("unset"),
    status_("unset")
  {
  } // BufferTank::BufferTank

  BufferTank::~BufferTank()
  {
    // nothing to do yet
  } // BufferTank::~BufferTank

  std::string BufferTank::exportLogLine() const
  {
    std::string exportit;
    exportit = std::to_string(this->up_.value) + "\t" +
               std::to_string(this->up_.nominal) + "\t" +
               std::to_string(this->mi_.value) + "\t" +
               std::to_string(this->mi_.nominal) + "\t" +
               this->pump_ + "\t" +
               this->status_;

    return exportit;
  } // BufferTank::exportLogLine

  std::string BufferTank::getTempUp() const
  {
    return std::to_string(this->up_.value);
  } // BufferTank::getTempUp

  std::string BufferTank::getTempUpNominal() const
  {
    return std::to_string(this->up_.nominal);
  } // BufferTank::getTempUpNominal

  std::string BufferTank::getTempMid() const
  {
    return std::to_string(this->mi_.value);
  } // BufferTank::getTempMid

  std::string BufferTank::getTempMidNominal() const
  {
    return std::to_string(this->mi_.nominal);
  } // BufferTank::getTempMidNominal

  std::string BufferTank::getPump() const
  {
    return this->pump_;
  } // BufferTank::getPump

  std::string BufferTank::getStatus() const
  {
    return this->status_;
  } // BufferTank::getStatus

  void BufferTank::setTempUp(const std::string &value)
  {
    this->up_.value = stod(value);
    this->up_.unit = dt::Celsius;
    this->up_.type = dt::Temperature;
  } // BufferTank::setTempUp

  void BufferTank::setTempUpNominal(const std::string &value)
  {
    this->up_.nominal = stod(value);
    this->up_.unit = dt::Celsius;
    this->up_.type = dt::Temperature;
  } // BufferTank::setTempUpNorminal

  void BufferTank::setTempMid(const std::string &value)
  {
    this->mi_.value = stod(value);
    this->mi_.unit = dt::Celsius;
    this->mi_.type = dt::Temperature;
  } // BufferTank::setTempMid

  void BufferTank::setTempMidNominal(const std::string &value)
  {
    this->mi_.nominal = stod(value);
    this->mi_.unit = dt::Celsius;
    this->mi_.type = dt::Temperature;
  } // BufferTank::setTempMidNominal

  void BufferTank::setPump(const std::string &value)
  {
    this->pump_ = value;
  } // BufferTank::setPump

  void BufferTank::setStatus(const std::string &value)
  {
    this->status_ = value;
  } // BufferTank::setStatus
} // namespace oekofen
