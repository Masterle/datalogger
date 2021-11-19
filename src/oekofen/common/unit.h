#ifndef __UNIT_H_
#define __UNIT_H_

/* os includes */
#include <string>

namespace oekofen
{
  /**
   * Unit represents an element in the heater control
   */
  class Unit
  {
  public:
    /**
     * default constructor
     * \param[in] name - name of the unit tank
     */
    Unit(std::string name) : name_(name) { }

    /** default destructor */
    virtual ~Unit() { }

    /**
     * get name of buffer tank
     * @return name of buffer tank
     */
    virtual std::string getName() const { return this->name_; }

    /**
     * set name of buffer tank
     * \param[in] value name of buffer tank
     */
    virtual void setName(const std::string &value) { this->name_ = value; }
  private:
    std::string name_; ///< name of the unit
  };
}

#endif // __UNIT_H_
