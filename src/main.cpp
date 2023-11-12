#include "oekofen/pelletronic.h"

#if defined(QAPPLICATION)
#  include "oekofen/gui/MainWindow.h"
#endif
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
  #if defined(QAPPLICATION)
    QApplication a(argc, argv);
    gui::MainWindow w;
    w.show();
    return a.exec();
  #else
    (void)argc;
    (void)argv;

    oekofen::Pelletronic pel;
    std::vector<std::string> logfiles = pel.getLogFiles();

    for(const auto& logfile : logfiles)
    {
      pel.setLogFileName(logfile);
      pel.readLogFile();
    }

    const std::string storeFileName = "./logfile.csv";
    pel.storeLogFile(storeFileName);
    return 0;
  #endif
}
