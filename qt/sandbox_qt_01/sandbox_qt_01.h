#ifndef SANDBOX_QT_01_H
#define SANDBOX_QT_01_H

#include <QtGui/QMainWindow>
#include "ui_sandbox_qt_01.h"

class sandbox_qt_01 : public QMainWindow
{
	Q_OBJECT

public:
	sandbox_qt_01(QWidget *parent = 0, Qt::WFlags flags = 0);
	~sandbox_qt_01();

private:
	Ui::sandbox_qt_01Class ui;
};

#endif // SANDBOX_QT_01_H
