#include <QtGui/QApplication>
#include "sandbox3.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	sandbox3 w;
	w.show();
	return a.exec();
}
