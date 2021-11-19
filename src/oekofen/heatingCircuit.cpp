#include "heatingCircuit.h"

/* os includes */

namespace oekofen
{
  HeatingCircuit::HeatingCircuit(std::string name) :
    Unit(name),
    flow_(),
    return_(),
    pump_("unset"),
    mixer_("unset"),
    status_("unset")
  {
  } // HeatingCircuit::HeatingCircuit

  HeatingCircuit::~HeatingCircuit()
  {
    // nothing to do yet
  } // HeatingCircuit::~HeatingCircuit

  std::string HeatingCircuit::exportLogLine() const
  {
    std::string exportit;
    exportit = std::to_string(this->flow_.value) + "\t" +
               std::to_string(this->flow_.nominal) + "\t" +
               std::to_string(this->return_.value) + "\t" +
               std::to_string(this->return_.nominal) + "\t" +
               this->pump_ + "\t" +
               this->mixer_ + "\t" +
               this->status_;

    return exportit;
  } // HeatingCircuit::exportLogLine

  std::string HeatingCircuit::getFlow() const
  {
    return std::to_string(this->flow_.value);
  }

  std::string HeatingCircuit::getFlowNominal() const
  {
    return std::to_string(this->flow_.nominal);
  } // HeatingCircuit::getFlowNominal

  std::string HeatingCircuit::getReturn() const
  {
    return std::to_string(this->return_.value);
  } // HeatingCircuit::getReturn

  std::string HeatingCircuit::getReturnNominal() const
  {
    return std::to_string(this->return_.nominal);
  } // HeatingCircuit::getReturnNominal

  std::string HeatingCircuit::getPump() const
  {
    return this->pump_;
  } // HeatingCircuit::getPump

  std::string HeatingCircuit::getMixer() const
  {
    return this->mixer_;
  } // HeatingCircuit::getMixer

  std::string HeatingCircuit::getStatus() const
  {
    return this->status_;
  } // HeatingCircuit::getStatus

  void HeatingCircuit::setFlow(const std::string &value)
  {
    this->flow_.value = stod(value);
    this->flow_.unit = dt::Celsius;
    this->flow_.type = dt::Temperature;
  } // HeatingCircuit::setFlow

  void HeatingCircuit::setFlowNominal(const std::string &value)
  {
    this->flow_.nominal = stod(value);
    this->flow_.unit = dt::Celsius;
    this->flow_.type = dt::Temperature;
  } // HeatingCircuit::setFlowNominal

  void HeatingCircuit::setReturn(const std::string &value)
  {
    this->return_.value = stod(value);
    this->return_.unit = dt::Celsius;
    this->return_.type = dt::Temperature;
  } // HeatingCircuit::setReturn

  void HeatingCircuit::setReturnNominal(const std::string &value)
  {
    this->return_.nominal = stod(value);
    this->return_.unit = dt::Celsius;
    this->return_.type = dt::Temperature;
  } // HeatingCircuit::setReturnNominal

  void HeatingCircuit::setPump(const std::string &value)
  {
    this->pump_ = value;
  } // HeatingCircuit::setPump

  void HeatingCircuit::setMixer(const std::string &value)
  {
    this->mixer_ = value;
  } // HeatingCircuit::setMixer

  void HeatingCircuit::setStatus(const std::string &value)
  {
    this->status_ = value;
  } // HeatingCircuit::setStatus
} // namespace oekofen
