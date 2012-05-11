#ifndef GLQUICKCOLUMN_H
#define GLQUICKCOLUMN_H
#include <GLQuickWidget.h>
#include <QScrollArea>

class QVBoxLayout;

//base class for our quick access "column"
class GLQuickColumn : public QWidget{
	Q_OBJECT
public:
	GLQuickColumn(QWidget* parent = 0);
	QSize sizeHint() const;
	QSize minimumSizeHint() const;

	void addWidget(GLQuickWidget* widget);
	void addHeader(GLQuickWidget* widget);
private:
	QVBoxLayout* boxLayout;
	//QList<GLQuickWidget> items;
	bool hasHeader;

};

#endif