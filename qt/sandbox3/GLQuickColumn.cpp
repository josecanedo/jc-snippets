#include <QtGui>
#include "GLQuickColumn.h"

GLQuickColumn::GLQuickColumn(QWidget * parent)
	: QWidget(parent){
		setBackgroundRole(QPalette::Shadow);
		setAutoFillBackground(true);
		setFocusPolicy(Qt::StrongFocus);
		//setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
		setMinimumSize(200, 20);
		//setMaximumWidth(250);
		boxLayout = new QVBoxLayout(this);
		boxLayout->insertStretch(-1000);
		boxLayout->setContentsMargins(0,0,0,0);
		boxLayout->setSpacing(2);
		hasHeader = false;
		
}

QSize GLQuickColumn::sizeHint() const{
	//return QSize(250, 30);
	return QWidget::sizeHint();
}
QSize GLQuickColumn::minimumSizeHint() const{
	//return QSize(200, 20);
	return QWidget::minimumSizeHint();
}

void GLQuickColumn::addWidget(GLQuickWidget* widget){
	//items.push_back(widget);
	if(hasHeader)
		boxLayout->insertWidget(1, widget);
	else
		boxLayout->insertWidget(0, widget);
	adjustSize();
}
void GLQuickColumn::addHeader(GLQuickWidget* widget){
	//items.push_back(widget);
	boxLayout->insertWidget(0, widget);
	adjustSize();
	hasHeader = true;
}