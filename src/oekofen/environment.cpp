#include "environment.h"

namespace oekofen
{
  Environment::Environment(const std::string &name) :
    Unit(name),
    date_("unset"),
    time_("unset"),
    outTemp_("unset"),
    outTempCur_("unset"),
    kt_(),
    br_("unset"),
    sperrzeit_(0),
    PE1_BR1_("unset"),
    Fehler1_("unset"),
    Fehler2_("unset"),
    Fehler3_("unset")
  {
    // not used yet
  }

  std::string Environment::exportLogLine() const
  {
    std::string exportit;
    exportit = this->date_ + "\t" +
             this->time_ + "\t" +
             this->outTemp_ + "\t" +
             this->outTempCur_ + "\t" +
             std::to_string(this->kt_.value) + "\t" +
             std::to_string(this->kt_.nominal) + "\t" +
             this->br_ + "\t" +
             std::to_string(this->sperrzeit_) + "\t" +
             this->PE1_BR1_ + "\t" +
             this->Fehler1_ + "\t" +
             this->Fehler2_ + "\t" +
             this->Fehler3_;

    return exportit;
  }

  void Environment::setDate(const std::string &value)
  {
    this->date_ = value;
  } // Environment::setDate

  void Environment::setTime(const std::string &value)
  {
    this->time_ = value;
  } // Environment::setTime

  void Environment::setOutTemp(const std::string &value)
  {
    this->outTemp_ = value;
  } // Environment::setOutTemp

  void Environment::setOutTempCur(const std::string &value)
  {
    this->outTempCur_ = value;
  } // Environment::setOutTempCur

  void Environment::setKt(const std::string &value)
  {
    this->kt_.value = stod(value);
    this->kt_.unit = dt::Celsius;
    this->kt_.type = dt::Temperature;
  } // Environment::setKt

  void Environment::setKtNom(const std::string &value)
  {
    this->kt_.nominal= stod(value);
    this->kt_.unit = dt::Celsius;
    this->kt_.type = dt::Temperature;
  } // Environment::setKtNom

  void Environment::setBr(const std::string &value)
  {
    this->br_ = value;
  } // Environment::setBr

  void Environment::setSperrzeit(const std::string &value)
  {
    this->sperrzeit_ = stoi(value);
  } // Environment::setSperrzeit

  void Environment::setPE1_BR1(const std::string &value)
  {
    this->PE1_BR1_ = value;
  } // Environment::setPE1_BR1

  void Environment::setFehler1(const std::string &value)
  {
    this->Fehler1_ = value;
  } // Environment::setFehler1

  void Environment::setFehler2(const std::string &value)
  {
    this->Fehler2_ = value;
  } // Environment::setFehler2

  void Environment::setFehler3(const std::string &value)
  {
    this->Fehler3_ = value;
  } // Environment::setFehler3
} // namespace oekofen
