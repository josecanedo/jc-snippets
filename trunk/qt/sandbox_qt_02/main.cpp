#include "sandbox_qt_02.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	sandbox_qt_02 *myClock = new sandbox_qt_02();
	//app->setMainWidget(clock);
	myClock->show();
	return app.exec();
}
