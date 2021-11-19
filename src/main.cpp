#include "oekofen/pelletronic.h"

#if ! defined(SHELL)
#  include "oekofen/gui/MainWindow.h"
#else
#  include "oekofen/pelletronic.h"
#endif

#include <string>
#include <vector>

#if ! defined(SHELL)
#include <QApplication>
#endif
int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
#if ! defined(SHELL)
  QApplication a(argc, argv);

  gui::MainWindow w;
	w.show();

	return a.exec();
#else
  oekofen::Pelletronic pel;
  std::vector<std::string> logfiles = pel.getLogFiles();

  // load logfiles
  for (std::vector<std::string>::iterator it = logfiles.begin(); it != logfiles.end(); ++it)
  {
    pel.setLogFileName(*it);
    pel.readLogFile();
  }

  // save logfiles
  std::string storeFileName="./logfile.csv";
  pel.storeLogFile(storeFileName);
  return 0;
#endif
}
