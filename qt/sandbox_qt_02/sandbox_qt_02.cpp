#include <QtGui>
#include <QPushButton>
#include "sandbox_qt_02.h"

sandbox_qt_02::sandbox_qt_02(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(10);
	setWindowTitle(tr("El Clocko"));
	resize(450, 450);
	brand = new QLabel("GAMELOFT", this);
	brand->setAlignment(Qt::AlignCenter);
	brand->setGeometry(width()/2 -60, height()/4 -9, 120, 18);

    QFont font = brand->font();
    font.setPointSize(font.pointSize() + 8);
    brand->setFont(font);

	QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, this);

	QPushButton *button = new QPushButton("Push the button", this);
    connect(button, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
	button->setGeometry(width()/2 - 80, height()-35, 160, 30);
	//ui.setupUi(this);
	connect(this, SIGNAL(fullHour()), this, SLOT(fullHourEvent()));
}

void sandbox_qt_02::pushButtonClicked(){
	if (brand->text() == "GAMELOFT")brand->setText("42");
	else brand->setText("GAMELOFT");
}

void sandbox_qt_02::fullHourEvent(){
	if (brand->text() == "GAMELOFT")brand->setText("42");
	else brand->setText("GAMELOFT");
}

void sandbox_qt_02::paintEvent(QPaintEvent *){
	QTime time = QTime::currentTime();
	if(time.minute() == 33) emit fullHour();
	static const QPoint hourHand[3]={
		QPoint(7,8),
		QPoint(-7,8),
		QPoint(0,-40)
	};
	static const QPoint minuteHand[3]={
		QPoint(7,8),
		QPoint(-7,8),
		QPoint(0,-80)
	};
	static const QPoint secondHand[2]={
		QPoint(0,0),
		QPoint(0,-7) 
	};
	QColor hourColor(127,0,0);
	QColor minuteColor(0,127,0, 191);
	QColor secondColor(0,0,127);
	
	int side = qMin(width(), height());
	QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);
    //hour pointer
	painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    //hours
	painter.setPen(hourColor);
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
	// minute pointer
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    //minutes
	painter.setPen(minuteColor);
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
	// second pointer
	painter.translate(40, -40);
	painter.setPen(secondColor);
	//painter.setBrush(secondColor);
	painter.save();
	painter.rotate(time.second()*6.0);
	painter.drawLine(secondHand[0], secondHand[1]);
	painter.restore();
	//secondes
	painter.setPen(minuteColor);
    for (int j = 0; j < 60; ++j) {
        painter.drawLine(12, 0, 14, 0);
        painter.rotate(6.0);
    }
}

sandbox_qt_02::~sandbox_qt_02()
{
	delete timer;
}
