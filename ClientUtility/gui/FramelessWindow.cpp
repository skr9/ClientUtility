#include "FramelessWindow.h"
#include <qmessagebox.h>

//ctor
FramelessWindow::FramelessWindow(QWidget* parent):QMainWindow(parent),  _movable(false), _pressPos(0,0), _translator(nullptr)
{
	this->setWindowFlags(Qt::FramelessWindowHint);
}

//dtor
FramelessWindow::~FramelessWindow()
{
}

//�麯������ʵ�壬ֻ��Ϊ�˸������ڽ��յ������л��¼�ʱ���ṩһ������ӿ�
void FramelessWindow::updateLanguage()
{
}


/************************************
* @input :
*
*
*
* @output :
*
* @brief :
* ��д����갴���¼������ڼ�¼�����
* ����ʱ����ڴ����е�����
*
*************************************/
void FramelessWindow::mousePressEvent(QMouseEvent* event)
{
	try
	{
		_movable = true;
		_pressPos = event->globalPos() - this->pos();
	}
	catch (const QString e)
	{
		QMessageBox::warning(this, tr(u8"����"), e, QMessageBox::Ok);
	}
}


/************************************
* @input :
*
*
*
* @output :
*
* @brief :
* ��д������ƶ��¼�������ʵ�������
* ���²��ƶ�ʱ���ƶ�����
*
*************************************/
void FramelessWindow::mouseMoveEvent(QMouseEvent* event)
{
	try
	{
		if (!_movable) return;

		auto dpos = event->globalPos() - _pressPos;
		if (dpos.x() > 100 || dpos.y() > 100)
		{
			this->move(dpos);
			_pressPos = event->globalPos() - this->pos();
		}
	}
	catch (QString e)
	{
		QMessageBox::warning(this, tr(u8"����"), e, QMessageBox::Ok);
	}
}


/************************************
* @input :
*
*
*
* @output :
*
* @brief :
* ��׽�����л��¼�
*
*
*************************************/
void FramelessWindow::changeEvent(QEvent* event)
{
	try
	{
		if (event->type() == QEvent::LanguageChange)
			updateLanguage();
		else
			QMainWindow::changeEvent(event);
	}
	catch (QString e)
	{
		QMessageBox::warning(this, tr(u8"����"), e, QMessageBox::Ok);
	}
}
