#include <QtGui>
#include "sandbox3.h"

sandbox3::sandbox3(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	QGraphicsView* view = new QGraphicsView();
	view->setBackgroundRole(QPalette::Midlight);
	view->setAutoFillBackground(true);
	setCentralWidget(view);
	//view->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
	//setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

	QBoxLayout *mainGroup = new QHBoxLayout(view);
	QBoxLayout *startLayout = new QVBoxLayout();
	QBoxLayout *quickColumnLayout = new QVBoxLayout();
	QBoxLayout *finishLayout = new QHBoxLayout();
	mainGroup->addLayout(startLayout);
	mainGroup->addLayout(quickColumnLayout);
	mainGroup->addLayout(finishLayout);
	

	//QPushButton *openMenuButton = new QPushButton("Start", this);
	//QPushButton *btn2 = new QPushButton("btn2", this);
	//QPushButton *btn3 = new QPushButton("btn3", this);
	QToolButton* btn1 = new QToolButton();
	QToolButton* btn2 = new QToolButton();
	QToolButton* btn3 = new QToolButton();
	startLayout->addWidget(btn1);
	startLayout->addWidget(btn2);
	startLayout->addWidget(btn3);
	startLayout->addStretch();

	GLQuickColumn* quickColumn1 = new GLQuickColumn(this);
	GLQuickColumn* quickColumn2 = new GLQuickColumn(this);
	GLQuickColumn* quickColumn3 = new GLQuickColumn(this);
	GLQuickWidget* meetingHeader = new GLQuickWidgetMeetingHeader(this, 0);
	GLQuickWidget* qw1 = new GLQuickWidgetMeeting(this, 1);
	GLQuickWidget* qw2 = new GLQuickWidgetMeeting(this, 2);
	GLQuickWidget* qw3 = new GLQuickWidgetMeeting(this, 3);

	QScrollArea* scrollArea1 =  new QScrollArea();
	scrollArea1->setMaximumWidth(250);
	scrollArea1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	scrollArea1->setWidget(quickColumn1);

	quickColumn1->addHeader(meetingHeader);
	quickColumn1->addWidget(qw1);
	quickColumn1->addWidget(qw2);
	quickColumn1->addWidget(qw3);



	quickColumnLayout->addWidget(scrollArea1);
	quickColumnLayout->addWidget(quickColumn2);
	quickColumnLayout->addWidget(quickColumn3);
	quickColumnLayout->addStretch();

	testMessage = new QLabel("No message");
	finishLayout->addWidget(testMessage);
	finishLayout->addStretch();
	//view->setMinimumSize(700,500/*mainGroup->minimumSize()*/);
	mainGroup->setContentsMargins(3,3,3,3);
	//setLayout(mainGroup);
	//adjustSize();
	//ui.setupUi(this);
}

void sandbox3::clicked(const int id){
	testMessage->setText("Meeting: " + QString::number(id)+ " clicked!");
}
void sandbox3::favoriteClicked(const int id){
	testMessage->setText("Meeting: " + QString::number(id)+ " favorite clicked!");
}
void sandbox3::enterMeetingClicked(const int id){
	testMessage->setText("Meeting: " + QString::number(id)+ " enter meeting clicked!");
}

void sandbox3::inChatClicked(const int id){
	testMessage->setText("Meeting: " + QString::number(id)+ " in Chat clicked!");
}

sandbox3::~sandbox3()
{

}

//////////////////////////////////////////////////////////////////////////
const int PaintingScaleFactor = 20;
void GLMeetingDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
 {
     if (index.data().canConvert<QString>()) {
         QString str = qvariant_cast<QString>(index.data());

         if (option.state & QStyle::State_Selected)
             painter->fillRect(option.rect, option.palette.highlight());

         //add code here
		 GLQuickWidget* qw1 = new GLQuickWidgetMeeting(m_qwSlots, 1);
		 qw1->render(painter, QPoint(100,100));
		 //painter->dra
		 QItemDelegate::paint(painter, option, index);

     } else {
         QItemDelegate::paint(painter, option, index);
     }
 }

 QSize GLMeetingDelegate::sizeHint(const QStyleOptionViewItem &option,
                              const QModelIndex &index) const
 {
     if (index.data().canConvert<QString>()) {
         QString str = qvariant_cast<QString>(index.data());
         //return str.sizeHint();
		 return PaintingScaleFactor * QSize(2, 1);
     } else {
         return QItemDelegate::sizeHint(option, index);
     }
 }

 QWidget *GLMeetingDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const

 {
     return QItemDelegate::createEditor(parent, option, index);
 }

 void GLMeetingDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const
 {
     QItemDelegate::setEditorData(editor, index);
 }

 void GLMeetingDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const
 {
     QItemDelegate::setModelData(editor, model, index);
 }

 void GLMeetingDelegate::commitAndCloseEditor()
 {
	 QWidget *editor = qobject_cast<QWidget*>(sender());
     emit commitData(editor);
     emit closeEditor(editor);
 }
