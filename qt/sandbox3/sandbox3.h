#ifndef SANDBOX3_H
#define SANDBOX3_H

#include <QtGui/QMainWindow>
#include "ui_sandbox3.h"
#include "GLQuickColumn.h" 
#include "qitemdelegate.h"
#include "qscrollbar.h" 
#include "qpainter.h" 



class sandbox3 : public QMainWindow, GLQuickWidgetSlots
{
	Q_OBJECT

public:
	sandbox3(QWidget *parent = 0, Qt::WFlags flags = 0);
	~sandbox3();

public slots:
	virtual void clicked(const int id);
	virtual void favoriteClicked(const int id);
	virtual void enterMeetingClicked(const int id);
	virtual void inChatClicked(const int id);

private:
	//Ui::sandbox3Class ui;
	QLabel* testMessage;
};


//////////////////////////////////////////////////////////////////////////////////
 class GLMeetingDelegate : public QItemDelegate
 {
     Q_OBJECT

 public:
     GLMeetingDelegate(QWidget *parent = 0) : QItemDelegate(parent) {
		
	 }
	 GLMeetingDelegate(GLQuickWidgetSlots* qwSlots, QWidget *parent = 0) : QItemDelegate(parent) {
		m_qwSlots = qwSlots;
	 }

     void paint(QPainter *painter, const QStyleOptionViewItem &option,
                const QModelIndex &index) const;
     QSize sizeHint(const QStyleOptionViewItem &option,
                    const QModelIndex &index) const;
     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;
     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

 private slots:
     void commitAndCloseEditor();
 private:
	 GLQuickWidgetSlots* m_qwSlots;
 };

 /////////////////////////////////////////////////////////////////

 class GLScrollBar: public QScrollBar{
	Q_OBJECT
 public: 
	GLScrollBar(Qt::Orientation orientation, QWidget* parent=0)
		:QScrollBar(orientation, parent){
	}
 protected:
	virtual void paintEvent(QPaintEvent* ){
		
		QPainter painter(this);
		painter.setBackgroundMode(Qt::TransparentMode);
		painter.setPen(QColor(0x00, 0x00, 0x00, 0x55));
        painter.setBrush(QColor(0x00, 0x00, 0x00, 0x55));
		painter.fillRect(rect(), Qt::white);
		painter.drawEllipse(QPoint(5,sliderPosition()), 3,10);
	}
	virtual void sliderChange(SliderChange change){} 
 };


#endif // SANDBOX3_H
