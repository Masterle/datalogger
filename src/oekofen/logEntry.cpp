#include "logEntry.h"

#include <vector>
namespace oekofen
{
  std::vector<std::string> splitData(const std::string &data, const std::string &delimiter)
  {
    std::vector<std::string> dataEntries;
    for(unsigned long pos, pre = 0;(pos = data.find(delimiter, pre)) != std::string::npos;)
    {
      dataEntries.push_back(data.substr(pre, pos - pre));
      pre = pos + 1;
    }

    return dataEntries;
  } // splitData

  LogEntry::LogEntry(const std::string &header, const std::string &logLine) :
    glo_("Pension Schmidt"),
    pe1_("PE1"),
    pU3_("PU3"),
    hC3_("HK3"),
    hC5_("HK5"),
    hC6_("HK6"),
    ww2_("WW2"),
    en_()
  {
    std::vector<std::string> headerSplitted(splitData(header, ";"));
    std::vector<std::string> dataSplitted(splitData(logLine, ";"));
    for(size_t i = 0; i < headerSplitted.size(); i++)
    {
      // global measurement values
      if (headerSplitted[i].find("Datum") != std::string::npos)          this->glo_.setDate(dataSplitted[i]);
      else if (headerSplitted[i].find("Zeit") != std::string::npos)      this->glo_.setTime(dataSplitted[i]);
      else if (headerSplitted[i].find("AT [") != std::string::npos)      this->glo_.setOutTemp(dataSplitted[i]);
      else if (headerSplitted[i].find("ATakt [") != std::string::npos)   this->glo_.setOutTempCur(dataSplitted[i]);
      else if (headerSplitted[i].find("KT Ist [") != std::string::npos)  this->glo_.setKt(dataSplitted[i]);
      else if (headerSplitted[i].find("KT Soll [") != std::string::npos) this->glo_.setKtNom(dataSplitted[i]);
      else if (headerSplitted[i].find("BR ") != std::string::npos)       this->glo_.setBr(dataSplitted[i]);
      else if (headerSplitted[i].find("Sperrzeit") != std::string::npos) this->glo_.setSperrzeit(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1_BR1") != std::string::npos)   this->glo_.setPE1_BR1(dataSplitted[i]);
      // heating circuit 3
      else if (headerSplitted[i].find("HK3 VL Ist[") != std::string::npos)  this->hC3_.setFlow(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 VL Soll[") != std::string::npos) this->hC3_.setFlowNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 RT Ist[") != std::string::npos)  this->hC3_.setReturn(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 RT Soll[") != std::string::npos) this->hC3_.setReturnNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 Pumpe") != std::string::npos)    this->hC3_.setPump(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 Mischer") != std::string::npos)  this->hC3_.setMixer(dataSplitted[i]);
      else if (headerSplitted[i].find("HK3 Status") != std::string::npos)   this->hC3_.setStatus(dataSplitted[i]);
      // heating circuit 5
      else if (headerSplitted[i].find("HK5 VL Ist[") != std::string::npos)  this->hC5_.setFlow(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 VL Soll[") != std::string::npos) this->hC5_.setFlowNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 RT Ist[") != std::string::npos)  this->hC5_.setReturn(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 RT Soll[") != std::string::npos) this->hC5_.setReturnNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 Pumpe") != std::string::npos)    this->hC5_.setPump(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 Mischer") != std::string::npos)  this->hC5_.setMixer(dataSplitted[i]);
      else if (headerSplitted[i].find("HK5 Status") != std::string::npos)  this->hC5_.setStatus(dataSplitted[i]);
      // heating circuit 6
      else if (headerSplitted[i].find("HK6 VL Ist[") != std::string::npos)  this->hC6_.setFlow(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 VL Soll[") != std::string::npos) this->hC6_.setFlowNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 RT Ist[") != std::string::npos)  this->hC6_.setReturn(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 RT Soll[") != std::string::npos) this->hC6_.setReturnNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 Pumpe") != std::string::npos)    this->hC6_.setPump(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 Mischer") != std::string::npos)  this->hC6_.setMixer(dataSplitted[i]);
      else if (headerSplitted[i].find("HK6 Status") != std::string::npos)  this->hC6_.setStatus(dataSplitted[i]);
      // warm water 2
      else if (headerSplitted[i].find("WW2 EinT Ist[") != std::string::npos) this->ww2_.setTempOn(dataSplitted[i]);
      else if (headerSplitted[i].find("WW2 AusT Ist[") != std::string::npos) this->ww2_.setTempOff(dataSplitted[i]);
      else if (headerSplitted[i].find("WW2 Soll[") != std::string::npos)     this->ww2_.setTempNom(dataSplitted[i]);
      else if (headerSplitted[i].find("WW2 Pumpe") != std::string::npos)     this->ww2_.setPump(dataSplitted[i]);
      else if (headerSplitted[i].find("WW2 Status") != std::string::npos)    this->ww2_.setStatus(dataSplitted[i]);
      // buffer tank 3
      else if (headerSplitted[i].find("PU3 TPO Ist[") != std::string::npos)  this->pU3_.setTempUp(dataSplitted[i]);
      else if (headerSplitted[i].find("PU3 TPO Soll[") != std::string::npos) this->pU3_.setTempUpNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("PU3 TPM Ist[") != std::string::npos)  this->pU3_.setTempMid(dataSplitted[i]);
      else if (headerSplitted[i].find("PU3 TPM Soll[") != std::string::npos) this->pU3_.setTempMidNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("PU3 Pumpe[%]") != std::string::npos)  this->pU3_.setPump(dataSplitted[i]);
      else if (headerSplitted[i].find("PU3 Status") != std::string::npos)    this->pU3_.setStatus(dataSplitted[i]);
      // energy related
      else if (headerSplitted[i].find("Netzbezug [W]") != std::string::npos)       this->en_.setPowerConsumption(dataSplitted[i]);
      else if (headerSplitted[i].find("Netzeinspeisung [W]") != std::string::npos) this->en_.setPowerDelivery(dataSplitted[i]);
      else if (headerSplitted[i].find("Phase 1 [W]") != std::string::npos)         this->en_.setPhase1(dataSplitted[i]);
      else if (headerSplitted[i].find("Phase 2 [W]") != std::string::npos)         this->en_.setPhase2(dataSplitted[i]);
      else if (headerSplitted[i].find("Phase 3 [W]") != std::string::npos)         this->en_.setPhase3(dataSplitted[i]);
      else if (headerSplitted[i].find("Thyristor [W]") != std::string::npos)       this->en_.setThyristor(dataSplitted[i]);
      else if (headerSplitted[i].find("PV [W]") != std::string::npos)              this->en_.setPv(dataSplitted[i]);
      else if (headerSplitted[i].find("Bedarf [W]") != std::string::npos)          this->en_.setDemand(dataSplitted[i]);
      else if (headerSplitted[i].find("BattIn [W]") != std::string::npos)          this->en_.setBatteryIn(dataSplitted[i]);
      else if (headerSplitted[i].find("BattOut [W]") != std::string::npos)         this->en_.setBatteryOut(dataSplitted[i]);
      else if (headerSplitted[i].find("BattChg [%]") != std::string::npos)         this->en_.setBatteryChg(dataSplitted[i]);
      else if (headerSplitted[i].find("EnergyState [%]") != std::string::npos)     this->en_.setEnergyState(dataSplitted[i]);
      // heater pe 1
      else if (headerSplitted[i].find("PE1 KT[") != std::string::npos)                  this->pe1_.setBoilerTemperature(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 KT_SOLL[") != std::string::npos)             this->pe1_.setBoilerTemperatureNominal(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 UW Freigabe[") != std::string::npos)         this->pe1_.setCircPumpEnable(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Modulation[%]") != std::string::npos)        this->pe1_.setModulation(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 FRT Ist[") != std::string::npos)             this->pe1_.setFRT(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 FRT Soll[") != std::string::npos)            this->pe1_.setFRTnom(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 FRT End[") != std::string::npos)             this->pe1_.setFRTend(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Einschublaufzeit[zs]") != std::string::npos) this->pe1_.setInsertionTime(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Pausenzeit[zs]") != std::string::npos)       this->pe1_.setPauseTime(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Luefterdrehzahl[%]") != std::string::npos)   this->pe1_.setFanSpeed(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Saugzugdrehzahl[%]") != std::string::npos)   this->pe1_.setSuctionSpeed(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Unterdruck Ist[EH]") != std::string::npos)   this->pe1_.setNegativePressure(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Unterdruck Soll[EH]") != std::string::npos)  this->pe1_.setNegativePressureNom(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Fuellstand[kg]") != std::string::npos)       this->pe1_.setFillLevel(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Fuellstand ZWB[kg]") != std::string::npos)   this->pe1_.setFillLevelZWB(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Status") != std::string::npos)               this->pe1_.setStatus(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor ES") != std::string::npos)             this->pe1_.setMotor_es(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor RA") != std::string::npos)             this->pe1_.setMotor_ra(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor RES1") != std::string::npos)           this->pe1_.setMotor_res1(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor TURBINE") != std::string::npos)        this->pe1_.setMotor_turbine(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor ZUEND") != std::string::npos)          this->pe1_.setMotor_zuend(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor UW[%]") != std::string::npos)          this->pe1_.setMotor_uwinpercent(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor AV") != std::string::npos)             this->pe1_.setMotor_av(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor RES2") != std::string::npos)           this->pe1_.setMotor_res2(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor MA") != std::string::npos)             this->pe1_.setMotor_ma(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor RM") != std::string::npos)             this->pe1_.setMotor_rm(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Motor SM") != std::string::npos)             this->pe1_.setMotor_SM(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 CAP RA") != std::string::npos)               this->pe1_.setCap_RA(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 CAP ZB") != std::string::npos)               this->pe1_.setCap_ZB(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 AK") != std::string::npos)                   this->pe1_.setAk(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 Saug-Int[min]") != std::string::npos)        this->pe1_.setSoakInterval(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 DigIn1") != std::string::npos)               this->pe1_.setDigIn1(dataSplitted[i]);
      else if (headerSplitted[i].find("PE1 DigIn2") != std::string::npos)               this->pe1_.setDigIn2(dataSplitted[i]);
      // general errors
      else if (headerSplitted[i].find("Fehler1") != std::string::npos) this->glo_.setFehler1(dataSplitted[i]);
      else if (headerSplitted[i].find("Fehler2") != std::string::npos) this->glo_.setFehler2(dataSplitted[i]);
      else if (headerSplitted[i].find("Fehler3") != std::string::npos) this->glo_.setFehler3(dataSplitted[i]);
    }
  } // LogEnry::LogEntry

  LogEntry::~LogEntry() {} // LogEntry::~LogEntry

  std::string LogEntry::exportLogLine() const
  {
    std::string exportit;
    exportit = this->glo_.exportLogLine() + "\t" +
               this->pe1_.exportLogLine() + "\t" +
               this->pU3_.exportLogLine() + "\t" +
               this->hC3_.exportLogLine() + "\t" +
               this->hC5_.exportLogLine() + "\t" +
               this->hC6_.exportLogLine() + "\t" +
               this->ww2_.exportLogLine() + "\t" +
               this->en_.exportLogLine() + "\n";
    return exportit;
  } // LogEntry::exportLogLine
}
