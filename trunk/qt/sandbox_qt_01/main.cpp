#include "sandbox_qt_01.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sandbox_qt_01 w;
	w.show();
	return a.exec();
}
