#include "pelletronic.h"

/* project specific includes */
#include "logEntry.h"

/* os specific includes */
#include <dirent.h>
#include <fcntl.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
namespace oekofen
{
  std::vector<LogEntry> logEntries;

  Pelletronic::Pelletronic() :
    ipAddress_("192.168.178.191"),
    port_("80"),
    fileName_("/home/asm/Dokumente/pelletronic-logs/touch_20211023.csv"),
    logFolder_("/home/asm/Dokumente/pelletronic-logs/")
    {

    };

  Pelletronic::~Pelletronic() {};

  std::vector<std::string> Pelletronic::getLogFiles()
  {
    std::vector<std::string> logFiles;
    struct dirent **namelist;

    int dirnum = ::scandir(this->logFolder_.c_str(), &namelist, NULL, alphasort);
    for(int i = 0; i < dirnum ; i++)
    {
      std::string fileName(namelist[i]->d_name);
      if((fileName.find("touch") != std::string::npos) && (fileName.find(".csv") != std::string::npos))
      {
        logFiles.push_back(fileName);
      }
      free(namelist[i]);
    }
    free (namelist);

    return logFiles;
  }

  void Pelletronic::printLogFiles()
  {
    // iterate over log entries
    for (std::vector<LogEntry>::iterator it = logEntries.begin(); it != logEntries.end(); ++it)
    {
      printf("%s", (*it).exportLogLine().c_str() );
    }
  }

  void Pelletronic::setLogFileName(std::string filename)
  {
    this->fileName_ = this->logFolder_ + filename;
  } // Pelletronic::setLogFileName

  void Pelletronic::readLogFile()
  {
    FILE *fd;
    int filesize(0);
    std::vector<unsigned char> data;
    fd = fopen(this->fileName_.c_str(), "r");
    if(fd)
    {
      fseek(fd, 0, SEEK_END);
      filesize = ftell(fd);
      if(0 > filesize)
      {
        fclose(fd);
        return;
      } // 0 > filesize
      fseek(fd, 0, SEEK_SET);
      data.resize(filesize * sizeof(unsigned char));
      memset(&data[0], 0, data.size());
      filesize = fread(&data[0], sizeof(unsigned char), (size_t)filesize, fd);
      fclose(fd);
    }
    std::string logFile(data.begin(), data.end());
    std::string delimiter = "\n";
    std::string header;
    for(unsigned long pos, pre = 0;(pos = logFile.find(delimiter, pre)) != std::string::npos;)
    {
      if(0 == pre)
      {
        header = logFile.substr(0, pos);
      }
      else
      {
        std::string line = logFile.substr(pre, pos - pre);
        if(line.size() > 1)
        {
          LogEntry entry(header, line);
          logEntries.push_back(entry);
        }
      }
      pre = pos + 1;
    }
  } // Pelletronic::readLogFile

  void Pelletronic::storeLogFile(const std::string &filename)
  {
    std::fstream file;

    file.open(filename, std::ios_base::app);
    if (file.is_open())
    {
      // iterate over log entries
      for (std::vector<LogEntry>::iterator it = logEntries.begin(); it != logEntries.end(); ++it)
      {
        std::string env = (*it).exportLogLine();
        file.write(env.data(), env.size());
      }
    }
  } // Pelletronic::storeLogFile
}
