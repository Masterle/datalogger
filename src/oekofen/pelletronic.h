#ifndef __PELLETRONIC_H_
#define __PELLETRONIC_H_

#include <string>
#include <vector>

namespace oekofen
{
  class Pelletronic
  {
  public:
    Pelletronic();
    virtual ~Pelletronic();
    virtual std::vector<std::string> getLogFiles();
    virtual void setLogFileName(std::string filename);
    virtual void readLogFile();
    virtual void printLogFiles();
    virtual void storeLogFile(const std::string &filename);
  private:
    std::string ipAddress_;
    std::string port_;
    std::string fileName_;
    std::string logFolder_;
  };
}
#endif // __PELLETRONIC_H_
