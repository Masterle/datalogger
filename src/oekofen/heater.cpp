#include "heater.h"

namespace oekofen
{
    Heater::Heater(std::string name) :
      Unit(name),
      boiler_(),
      circPump_("unset"),
      modulation_("unset"),
      FRT_("unset"),
      FRTnom_("unset"),
      FRTend_("unset"),
      insertionTime_("unset"),
      pauseTime_("unset"),
      fanSpeed_("unset"),
      suctionSpeed_("unset"),
      negativePressure_("unset"),
      negativePressureNom_("unset"),
      fillLevel_("unset"),
      fillLevelZwb_("unset"),
      status_("unset"),
      motor_es_("unset"),
      motor_ra_("unset"),
      motor_res1_("unset"),
      motor_turbine_("unset"),
      motor_zuend_("unset"),
      motor_uwinpercent_("unset"),
      motor_av_("unset"),
      motor_res2_("unset"),
      motor_ma_("unset"),
      motor_rm_("unset"),
      motor_SM_("unset"),
      cap_RA_("unset"),
      cap_ZB_("unset"),
      ak_("unset"),
      soakInterval_("unset"),
      digIn1_("unset"),
      digIn2_("unset")
    {
    } // Heater::Heater

    Heater::~Heater()
    {
      // nothing to do yet
    } // Heater::~Heater

  std::string Heater::exportLogLine() const
  {
    std::string exportit;
    exportit = std::to_string(this->boiler_.value) + "\t" +
               std::to_string(this->boiler_.nominal) + "\t" +
               this->circPump_ + "\t" +
               this->modulation_ + "\t" +
               this->FRT_ + "\t" +
               this->FRTnom_ + "\t" +
               this->FRTend_ + "\t" +
               this->insertionTime_ + "\t" +
               this->pauseTime_ + "\t" +
               this->fanSpeed_ + "\t" +
               this->suctionSpeed_ + "\t" +
               this->negativePressure_ + "\t" +
               this->negativePressureNom_ + "\t" +
               this->fillLevel_ + "\t" +
               this->fillLevelZwb_ + "\t" +
               this->status_ + "\t" +
               this->motor_es_ + "\t" +
               this->motor_ra_ + "\t" +
               this->motor_res1_ + "\t" +
               this->motor_turbine_ + "\t" +
               this->motor_zuend_ + "\t" +
               this->motor_uwinpercent_ + "\t" +
               this->motor_av_ + "\t" +
               this->motor_res2_ + "\t" +
               this->motor_ma_ + "\t" +
               this->motor_rm_ + "\t" +
               this->motor_SM_ + "\t" +
               this->cap_RA_ + "\t" +
               this->cap_ZB_ + "\t" +
               this->ak_ + "\t" +
               this->soakInterval_ + "\t" +
               this->digIn1_ + "\t" +
               this->digIn2_;

    return exportit;
  } // Heater::exportLogLine


  std::string Heater::getBoilerTemperature() const
  {
    return std::to_string(this->boiler_.value);
  } // Heater::getBoilerTemperature

  std::string Heater::getBoilerTemperatureNominal() const
  {
    return std::to_string(this->boiler_.nominal);
  } // Heater::getBoilerTemperatureNominal

  std::string Heater::getCircPumpEnable() const
  {
    return this->circPump_;
  } // Heater::getCircPump

  std::string Heater::getModulation() const
  {
    return this->modulation_;
  } // Heater::getModulation

  std::string Heater::getFRT() const
  {
    return this->FRT_;
  } // Heater::getFRT

  std::string Heater::getFRTnom() const
  {
    return this->FRTnom_;
  } // Heater::getFRTnom

  std::string Heater::getFRTend() const
  {
    return this->FRTend_;
  } // Heater::getFRTend

  std::string Heater::getInsertionTime() const
  {
    return this->insertionTime_;
  } // Heater::getInsertionTime

  std::string Heater::getPauseTime() const
  {
    return this->pauseTime_;
  } // Heater::getPauseTime

  std::string Heater::getFanSpeed() const
  {
    return this->fanSpeed_;
  } // Heater::getFanSpeed

  std::string Heater::getSuctionSpeed() const
  {
    return this->suctionSpeed_;
  } // Heater::getReturnNominal

  std::string Heater::getNegativePressure() const
  {
    return this->negativePressure_;
  } // Heater::getNegativePressure

  std::string Heater::getNegativePressureNom() const
  {
    return this->negativePressureNom_;
  } // Heater::getNegativePressureNom

  std::string Heater::getFillLevel() const
  {
    return this->fillLevel_;
  } // Heater::getFillLevel

  std::string Heater::getFillLevelZWB() const
  {
    return this->fillLevelZwb_;
  } // Heater::getFillLevelZWB

  std::string Heater::getStatus() const
  {
    return this->status_;
  } // Heater::getStatus

  std::string Heater::getMotor_es() const
  {
    return this->motor_es_;
  }

  std::string Heater::getMotor_ra() const
  {
    return this->motor_ra_;
  }

  std::string Heater::getMotor_res1() const
  {
    return this->motor_res1_;
  }

  std::string Heater::getMotor_turbine() const
  {
    return this->motor_turbine_;
  }

  std::string Heater::getMotor_zuend() const
  {
    return this->motor_zuend_;
  }

  std::string Heater::getMotor_uwinpercent() const
  {
    return this->motor_uwinpercent_;
  }

  std::string Heater::getMotor_av() const
  {
    return this->motor_av_;
  }

  std::string Heater::getMotor_res2() const
  {
    return this->motor_res2_;
  }

  std::string Heater::getMotor_ma() const
  {
    return this->motor_ma_;
  }

  std::string Heater::getMotor_rm() const
  {
    return this->motor_rm_;
  }

  std::string Heater::getMotor_SM() const
  {
    return this->motor_SM_;
  }

  std::string Heater::getCap_RA() const
  {
    return this->cap_RA_;
  }

  std::string Heater::getCap_ZB() const
  {
    return this->cap_ZB_;
  }

  std::string Heater::getAk() const
  {
    return this->ak_;
  }

  std::string Heater::getSoakInterval() const
  {
    return this->soakInterval_;
  }

  std::string Heater::getDigIn1() const
  {
    return this->digIn1_;
  }

  std::string Heater::getDigIn2() const
  {
    return this->digIn2_;
  }

  void Heater::setBoilerTemperature(const std::string &value)
  {
    this->boiler_.value = stod(value);
    this->boiler_.unit = dt::Celsius;
    this->boiler_.type = dt::Temperature;
  } // Heater::setBoilerTemperature

  void Heater::setBoilerTemperatureNominal(const std::string &value)
  {
    this->boiler_.nominal = stod(value);
    this->boiler_.unit = dt::Celsius;
    this->boiler_.type = dt::Temperature;
  } // Heater::setBoilerTemperatureNominal

  void Heater::setCircPumpEnable(const std::string &value)
  {
    this->circPump_ = value;
  } // Heater::setCircPump

  void Heater::setModulation(const std::string &value)
  {
    this->modulation_ = value;
  } // Heater::setModulation

  void Heater::setFRT(const std::string &value)
  {
    this->FRT_ = value;
  } // Heater::setFRT

  void Heater::setFRTnom(const std::string &value)
  {
    this->FRTnom_ = value;
  } // Heater::setFRTnom

  void Heater::setFRTend(const std::string &value)
  {
    this->FRTend_ = value;
  } // Heater::setCircPump

  void Heater::setInsertionTime(const std::string &value)
  {
    this->insertionTime_ = value;
  } // Heater::setInsertionTime

  void Heater::setPauseTime(const std::string &value)
  {
    this->pauseTime_ = value;
  } // Heater::setPauseTime

  void Heater::setFanSpeed(const std::string &value)
  {
    this->fanSpeed_ = value;
  } // Heater::setFanSpeed

  void Heater::setSuctionSpeed(const std::string &value)
  {
    this->suctionSpeed_ = value;
  } // Heater::setSuctionSpeed

  void Heater::setNegativePressure(const std::string &value)
  {
    this->negativePressure_ = value;
  } // Heater::setNegativePressure

  void Heater::setNegativePressureNom(const std::string &value)
  {
    this->negativePressureNom_ = value;
  } // Heater::setNegativePressureNom

  void Heater::setFillLevel(const std::string &value)
  {
    this->fillLevel_ = value;
  } // Heater::setFillLevel

  void Heater::setFillLevelZWB(const std::string &value)
  {
    this->fillLevelZwb_ = value;
  } // Heater::setFillLevelZWB

  void Heater::setStatus(const std::string &value)
  {
    this->status_ = value;
  } // Heater::setStatus

  void Heater::setMotor_es(const std::string &value)
  {
    this->motor_es_ = value;
  } // Heater::set

  void Heater::setMotor_ra(const std::string &value)
  {
    this->motor_ra_ = value;
  } // Heater::set

  void Heater::setMotor_res1(const std::string &value)
  {
    this->motor_res1_ = value;
  } // Heater::set

  void Heater::setMotor_turbine(const std::string &value)
  {
    this->motor_turbine_ = value;
  } // Heater::set

  void Heater::setMotor_zuend(const std::string &value)
  {
    this->motor_zuend_ = value;
  } // Heater::set

  void Heater::setMotor_uwinpercent(const std::string &value)
  {
    this->motor_uwinpercent_ = value;
  } // Heater::set

  void Heater::setMotor_av(const std::string &value)
  {
    this->motor_av_ = value;
  } // Heater::set

  void Heater::setMotor_res2(const std::string &value)
  {
    this->motor_res2_ = value;
  } // Heater::set

  void Heater::setMotor_ma(const std::string &value)
  {
    this->motor_ma_ = value;
  } // Heater::set

  void Heater::setMotor_rm(const std::string &value)
  {
    this->motor_rm_ = value;
  } // Heater::set

  void Heater::setMotor_SM(const std::string &value)
  {
    this->motor_SM_ = value;
  } // Heater::set

  void Heater::setCap_RA(const std::string &value)
  {
    this->cap_RA_ = value;
  } // Heater::set

  void Heater::setCap_ZB(const std::string &value)
  {
    this->cap_ZB_ = value;
  } // Heater::set

  void Heater::setAk(const std::string &value)
  {
    this->ak_ = value;
  } // Heater::set

  void Heater::setSoakInterval(const std::string &value)
  {
    this->soakInterval_ = value;
  } // Heater::set

  void Heater::setDigIn1(const std::string &value)
  {
    this->digIn1_ = value;
  } // Heater::setDigIn1

  void Heater::setDigIn2(const std::string &value)
  {
    this->digIn2_ = value;
  } // Heater::setDigIn2
} // namespace oekofen
