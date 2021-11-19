#include "hotWaterTank.h"

namespace oekofen
{
  HotWaterTank::HotWaterTank(std::string name) :
    Unit(name),
    tempOn_("unset"),
    tempOff_("unset"),
    tempNom_("unset"),
    pump_("unset"),
    status_("unset")
  {

  } // HotWaterTank::HotWaterTank

  HotWaterTank::~HotWaterTank() {}

  std::string HotWaterTank::exportLogLine() const
  {
    std::string exportit;
    exportit = this->tempOn_ + "\t" +
               this->tempOff_ + "\t" +
               this->tempNom_ + "\t" +
               this->pump_ + "\t" +
               this->status_;

    return exportit;
  } // HotWaterTank::exportLogLine


  std::string HotWaterTank::getTempOn() const
  {
    return this->tempOn_;
  }

  std::string HotWaterTank::getTempOff() const
  {
    return this->tempOff_;
  } // HotWaterTank::getTempOff

  std::string HotWaterTank::getTempNom() const
  {
    return this->tempNom_;
  } // HotWaterTank::getTempNom

  std::string HotWaterTank::getPump() const
  {
    return this->pump_;
  } // HotWaterTank::getPump

  std::string HotWaterTank::getStatus() const
  {
    return this->status_;
  } // HotWaterTank::getStatus

  void HotWaterTank::setTempOn(const std::string &value)
  {
    this->tempOn_ = value;
  } // HotWaterTank::setFlow

  void HotWaterTank::setTempOff(const std::string &value)
  {
    this->tempOff_ = value;
  } // HotWaterTank::setFlowNominal

  void HotWaterTank::setTempNom(const std::string &value)
  {
    this->tempNom_ = value;
  } // HotWaterTank::setReturn

  void HotWaterTank::setPump(const std::string &value)
  {
    this->pump_ = value;
  } // HotWaterTank::setPump

  void HotWaterTank::setStatus(const std::string &value)
  {
    this->status_ = value;
  } // HotWaterTank::setStatus
} // namespace oekofen
