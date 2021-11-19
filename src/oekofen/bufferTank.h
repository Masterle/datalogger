/**
* @brief file describes buffer tank
* @author Axel Schmidt
* @copyright 2021 - ITSS
*/
#ifndef __BUFFER_TANK_H_
#define __BUFFER_TANK_H_

/* project includes */
#include "common/unit.h"
#include "dt/sensor.h"

/* os includes */
#include <string>

namespace oekofen
{
  /**
   * class buffer tank containing all measurement values of buffer tanks
   * possible values:
   * - upper temperature sensor
   * - middle temperature sensor
   * - pump
   * - status of the buffer tank control
   */
  class BufferTank : public Unit
  {
  public:
    /**
     * default constructor
     * \param[in] name - name of the buffer tank
     */
    BufferTank(std::string name);

    /** default destructor */
    virtual ~BufferTank();

    /**
     * get current temperature of upper sensor
     * @return temperature of upper sensor
     */
    virtual std::string getTempUp() const;

    /**
     * get nominal temperature of upper sensor
     * @return nominal temperature of upper sensor
     */
    virtual std::string getTempUpNominal() const;

    /**
     * get current temperature of middle sensor
     * @return temperature of middle sensor
     */
    virtual std::string getTempMid() const;

    /**
     * get nominal temperature of middle sensor
     * @return nominal temperature of middle sensor
     */
    virtual std::string getTempMidNominal() const;

    /**
     * get state of circulation pump
     * @return state of circulation pump
     */
    virtual std::string getPump() const;

    /**
     * get state of buffer tank
     * @return state of buffer tank
     */
    virtual std::string getStatus() const;

    /**
     * set current upper sensor temperature of buffer tank
     * \param[in] value cuurent upper sensor temperature of buffer tank
     */
    virtual void setTempUp(const std::string &value);

    /**
     * set nominal upper sensor temperature of buffer tank
     * \param[in] value nominal upper sensor temperature of buffer tank
     */
    virtual void setTempUpNominal(const std::string &value);

    /**
     * set current middle sensor temperature of buffer tank
     * \param[in] value current middle sensor temperature of buffer tank
     */
    virtual void setTempMid(const std::string &value);

    /**
     * set sensor temperature nominal of buffer tank
     * \param[in] value nominal temperature of buffer tank
     */
    virtual void setTempMidNominal(const std::string &value);

    /**
     * set pump state of buffer tank
     * \param[in] value pump state of buffer tank
     */
    virtual void setPump(const std::string &value);

    /**
     * set status of buffer tank
     * \param[in] value name of buffer tank
     */
    virtual void setStatus(const std::string &value);

    /**
     * set name of buffer tank
     * @return log line as string tab separated
     */
    virtual std::string exportLogLine() const;
  private:
    dt::Sensor up_;      ///< upper sensor
    dt::Sensor mi_;      ///< middle sensor
    std::string pump_;   ///< Pumpe
    std::string status_; ///< Status
  }; // class BufferTank
} // namespace oekofen
#endif // __BUFFER_TANK_H_
