#include "energy.h"

namespace oekofen
{
  Energy::Energy() :
    Unit("unset"),
    powerConsumption_("unset"),
    powerDelivery_("unset"),
    phase1_("unset"),
    phase2_("unset"),
    phase3_("unset"),
    thyristor_("unset"),
    pv_("unset"),
    demand_("unset"),
    batteryIn_("unset"),
    batteryOut_("unset"),
    batteryChg_("unset"),
    energyState_("unset")
  {

  } // Energy::Energy

  Energy::~Energy()
  {

  } // Energy::~Energy

  std::string Energy::exportLogLine() const
  {
    std::string exportit;
    exportit = this->powerConsumption_ + "\t" +
               this->powerDelivery_ + "\t" +
               this->phase1_ + "\t" +
               this->phase2_ + "\t" +
               this->phase3_ + "\t" +
               this->thyristor_ + "\t" +
               this->pv_ + "\t" +
               this->demand_ + "\t" +
               this->batteryIn_ + "\t" +
               this->batteryOut_ + "\t" +
               this->batteryChg_ + "\t" +
               this->energyState_;

    return exportit;
  } // Energy::exportLogLine


  std::string Energy::getPowerConsumption() const
  {
    return this->powerConsumption_;
  } // Energy::getPowerConsumption

  std::string Energy::getPowerDelivery() const
  {
    return this->powerDelivery_;
  } // Energy::getPowerDelivery

  std::string Energy::getPhase1() const
  {
    return this->phase1_;
  } // Energy::getPhase1

  std::string Energy::getPhase2() const
  {
    return this->phase2_;
  } // Energy::getPhase2

  std::string Energy::getPhase3() const
  {
    return this->phase3_;
  } // Energy::getPhase3

  std::string Energy::getThyristor() const
  {
    return this->thyristor_;
  } // Energy::getThyristor

  std::string Energy::getPv() const
  {
    return this->pv_;
  } // Energy::getPv

  std::string Energy::getDemand() const
  {
    return this->demand_;
  } // Energy::getDemand

  std::string Energy::getBatteryIn() const
  {
    return this->batteryIn_;
  } // Energy::getBatteryIn

  std::string Energy::getBatteryOut() const
  {
    return this->batteryOut_;
  } // Energy::getBatteryOut

  std::string Energy::getBatteryChg() const
  {
    return this->batteryChg_;
  } // Energy::getBatteryChg

  std::string Energy::getEnergyState() const
  {
    return this->energyState_;
  } // Energy::getEnergyState

  void Energy::setPowerConsumption(const std::string &value)
  {
    this->powerConsumption_ = value;
  } // Energy::setPowerConsumption

  void Energy::setPowerDelivery(const std::string &value)
  {
    this->powerDelivery_ = value;
  } // Energy::setPowerDelivery

  void Energy::setPhase1(const std::string &value)
  {
    this->phase1_ = value;
  } // Energy::setPhase1

  void Energy::setPhase2(const std::string &value)
  {
    this->phase2_ = value;
  } // Energy::setPhase2

  void Energy::setPhase3(const std::string &value)
  {
    this->phase3_ = value;
  } // Energy::setPhase3

  void Energy::setThyristor(const std::string &value)
  {
    this->thyristor_ = value;
  } // Energy::setThyristor

  void Energy::setPv(const std::string &value)
  {
    this->pv_ = value;
  } // Energy::setPv

  void Energy::setDemand(const std::string &value)
  {
    this->demand_ = value;
  } // Energy::setDemand

  void Energy::setBatteryIn(const std::string &value)
  {
    this->batteryIn_ = value;
  } // Energy::setBatteryIn

  void Energy::setBatteryOut(const std::string &value)
  {
    this->batteryOut_ = value;
  } // Energy::setBatteryOut

  void Energy::setBatteryChg(const std::string &value)
  {
    this->batteryChg_ = value;
  } // Energy::setBatteryChg

  void Energy::setEnergyState(const std::string &value)
  {
    this->energyState_ = value;
  } // Energy::setEnergyState
} // namespace oekofen
