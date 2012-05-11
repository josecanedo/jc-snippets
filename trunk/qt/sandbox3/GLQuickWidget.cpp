#include <QtGui>
#include "GLQuickWidget.h"

GLQuickWidget::GLQuickWidget(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view, QWidget * parent )
	: QAbstractButton(parent), QListWidgetItem("widget",view,0){
		m_slots = qwSlots;
		m_id = id;
		setBackgroundRole(QPalette::Mid);
		setAutoFillBackground(true);
		setFocusPolicy(Qt::StrongFocus);
		setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
		setMinimumSize(200, 20);
		QObject::connect(this, SIGNAL(clicked()), this, SLOT(clickedSlot()));
		//QObject::connect(this, SIGNAL(clicked(int)), m_slots) SLOT(clicked(int)));
}

QSize GLQuickWidget::sizeHint() const{
	return QSize(250, 20);
}
QSize GLQuickWidget::minimumSizeHint() const{
	return QSize(200, 20);
}

void GLQuickWidget::clickedSlot(){
	//emit clicked(m_id);
	m_slots->clicked(m_id);
}

GLQuickWidgetMeeting::GLQuickWidgetMeeting(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view, QWidget* parent)
	:GLQuickWidget(qwSlots, id, view, parent){

	inChatButton = new QToolButton();
	inChatButton->setIcon(QIcon());

	name = new QLabel("Meeting: " + QString::number(id));
	hour = new QLabel("16:30h - 17:30h"); 

	boxLayout = new QHBoxLayout(this);
	boxLayout->setContentsMargins(5,2,5,2);
	boxLayout->addWidget(name);
	boxLayout->addWidget(hour);
	boxLayout->addWidget(inChatButton);

	enterMeetingAct = new QAction(tr("&Enter Meeting"), this);
	enterMeetingAct->setShortcuts(QKeySequence::Open);
	enterMeetingAct->setStatusTip(tr("Enter Meeting"));
	QObject::connect(enterMeetingAct, SIGNAL(triggered()), this, SLOT(enterMeetingClickedSlot()));
	QObject::connect(inChatButton, SIGNAL(clicked()), this, SLOT(inChatClickedSlot()));
	//QObject::connect(this, SIGNAL(enterMeetingClicked(int)), m_slots, SLOT(enterMeetingClicked(int)));
	//QObject::connect(this, SIGNAL(inChatClicked(int)), m_slots, SLOT(inChatClicked(int)));
}

void GLQuickWidgetMeeting::contextMenuEvent(QContextMenuEvent *event){
	QMenu menu(this);
	menu.addAction(enterMeetingAct);
	menu.exec(event->globalPos());
}


void GLQuickWidgetMeeting::enterMeetingClickedSlot(){
	//emit enterMeetingClicked(m_id);
	m_slots->enterMeetingClicked(m_id);
}

void GLQuickWidgetMeeting::inChatClickedSlot(){
	//emit inChatClicked(m_id);
	m_slots->inChatClicked(m_id);
}

GLQuickWidgetMeetingHeader::GLQuickWidgetMeetingHeader(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view, QWidget* parent)
	:GLQuickWidget(qwSlots, id, view, parent){
	setBackgroundRole(QPalette::Shadow);
	title = new QLabel(tr("MEETINGS"));
	addMeetingButton = new QToolButton();
	addMeetingButton->setText("+");
	expandButton = new QToolButton();
	


	boxLayout = new QHBoxLayout(this);
	boxLayout->setContentsMargins(5,2,5,2);
	boxLayout->addWidget(addMeetingButton);
	boxLayout->addWidget(title, 0, Qt::AlignHCenter);
	boxLayout->addWidget(expandButton);
}

void GLQuickWidgetMeetingHeader::addMeetingClickedSlot(){}
void GLQuickWidgetMeetingHeader::expandClickedSlot(){}