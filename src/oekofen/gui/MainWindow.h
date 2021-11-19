#ifndef __MAIN_WINDOW_H_
#define __MAIN_WINDOW_H_

/* project specific includes */
#include "../pelletronic.h"

#include <QMainWindow>
namespace gui
{
  class MainWindow : public QMainWindow
  {
    Q_OBJECT
  public:
    MainWindow(QWidget * parent = nullptr);
  private slots:
	void OnFileNew();
	void OnFileOpen();
	void OnFileSave();
private:
  oekofen::Pelletronic pelletronic_;

  };
}
#endif // __MAIN_WINDOW_H_
