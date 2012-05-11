#ifndef GLQUICKWIDGET_H
#define GLQUICKWIDGET_H

#include "qabstractbutton.h"
#include <QListWidgetItem>

class QAction;
class GLQuickWidgetSlots;
class QHBoxLayout;
class QLabel;
class QToolButton;

//base class for our quick access "bar"
class GLQuickWidget : public QAbstractButton, public QListWidgetItem{
	Q_OBJECT
public:
	GLQuickWidget(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view=0, QWidget* parent = 0);
	virtual ~GLQuickWidget(){};
	virtual QSize sizeHint() const;
	virtual QSize minimumSizeHint() const;
	virtual void paintEvent(QPaintEvent* e){};
public slots:
	virtual void clickedSlot();
signals:
	void clicked(const int id);
protected:			
	virtual void contextMenuEvent(QContextMenuEvent *event){};
	QHBoxLayout* boxLayout;
	QLabel *name;
	GLQuickWidgetSlots* m_slots;
	int m_id;
};


class GLQuickWidgetSlots{
//we don't need to declare them as slots here
public:
	virtual void clicked(const int id) = 0;
	virtual void favoriteClicked(const int id) = 0;
	virtual void inChatClicked(const int id) = 0;
	virtual void enterMeetingClicked(const int id) = 0;
};

class GLQuickWidgetMeeting : public GLQuickWidget{
	Q_OBJECT
public:
	GLQuickWidgetMeeting(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view=0, QWidget* parent = 0);
public slots:
	void enterMeetingClickedSlot();
	void inChatClickedSlot();
signals:
	void enterMeetingClicked(const int id);
	void inChatClicked(const int id);
private:
	virtual void contextMenuEvent(QContextMenuEvent *event);
	QLabel *hour;
	QToolButton *inChatButton;
	QAction* enterMeetingAct;
};

class GLQuickWidgetMeetingHeader : public GLQuickWidget{
	Q_OBJECT
public:
	GLQuickWidgetMeetingHeader(GLQuickWidgetSlots* qwSlots, int id, QListWidget* view=0, QWidget* parent = 0);
public slots:
	void addMeetingClickedSlot();
	void expandClickedSlot();
signals:
	void addMeetingClicked(const int id);
	void expandClicked(const int id);
private:
	QLabel *title;
	QToolButton *addMeetingButton;
	QToolButton *expandButton;
};

/*
class GLMeetingListModel : public QAbstractListModel{
public:
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	//headerData
	//insertROws
	//removeRows
	GLMeetingListModel(const QList<int>& meetings, meetings QObject * parent = 0);
	void setMeetingList(const QList<int>& meetings);
};
*/
#endif