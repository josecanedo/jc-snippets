#ifndef SANDBOX_QT_02_H
#define SANDBOX_QT_02_H

#include <QtGui/QWidget>
#include <QtGui/QLabel>
#include "ui_sandbox_qt_02.h"

class sandbox_qt_02 : public QWidget
{
	Q_OBJECT //macro for signal/slots

public:
	sandbox_qt_02(QWidget *parent = 0, Qt::WFlags flags = 0);
	~sandbox_qt_02();

protected:
	void paintEvent(QPaintEvent *event);
private:
	Ui::sandbox_qt_02Class ui;
	QTimer *timer;
	QLabel *brand;
private slots:
	void pushButtonClicked();
	void fullHourEvent();
signals:
	void fullHour();
};

#endif // SANDBOX_QT_02_H
