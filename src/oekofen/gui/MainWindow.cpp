#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QStatusBar>

namespace gui
{
  MainWindow::MainWindow(QWidget * parent)
  	: QMainWindow(parent),
    pelletronic_()
  {
  	// == WINDOW SETTINGS ==
  	setWindowTitle("DataLogger");

  	setMinimumSize(800, 450);

  	// == MENU BAR ==
  	QMenuBar * menuBar = new QMenuBar(this);
  	setMenuBar(menuBar);

  	// -- File menu --
  	QMenu * menu = menuBar->addMenu("&File");

  	// New
  	QAction * action = new QAction("&New", this);
  	connect(action, &QAction::triggered, this, &MainWindow::OnFileNew);
  	menu->addAction(action);

  	// Open
  	action = new QAction("&Open", this);
  	connect(action, &QAction::triggered, this, &MainWindow::OnFileOpen);
  	menu->addAction(action);

  	// Save
  	action = new QAction("&Save", this);
  	connect(action, &QAction::triggered, this, &MainWindow::OnFileSave);
  	menu->addAction(action);

  	// separator
  	menu->addSeparator();

  	// Exit
  	action = new QAction("&Exit", this);
  	connect(action, &QAction::triggered, this, &MainWindow::close);
  	menu->addAction(action);

  	// == STATUS BAR ==
  	QStatusBar * statusBar = new QStatusBar(this);
  	setStatusBar(statusBar);


  }

  // == PRIVATE SLOTS ==
  void MainWindow::OnFileNew()
  {
  	statusBar()->showMessage("File -> New");
  }

  void MainWindow::OnFileOpen()
  {
    std::vector<std::string> logfiles = pelletronic_.getLogFiles();

    // load logfiles
    for (std::vector<std::string>::iterator it = logfiles.begin(); it != logfiles.end(); ++it)
    {
      pelletronic_.setLogFileName(*it);
      pelletronic_.readLogFile();
    }
  	statusBar()->showMessage("File -> Open");
  }

  void MainWindow::OnFileSave()
  {
  	statusBar()->showMessage("File -> Save");

    std::string storeFileName="./logfile.csv";
    pelletronic_.storeLogFile(storeFileName);
  }
} // namespace gui
