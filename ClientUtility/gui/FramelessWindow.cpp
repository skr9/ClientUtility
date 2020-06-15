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

//虚函数，无实体，只是为了给子类在接收到语言切换事件时，提供一个处理接口
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
* 重写了鼠标按下事件，用于记录在鼠标
* 按下时光标在窗体中的坐标
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
		QMessageBox::warning(this, tr(u8"错误"), e, QMessageBox::Ok);
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
* 重写了鼠标移动事件，用以实现在鼠标
* 按下并移动时，移动窗体
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
		QMessageBox::warning(this, tr(u8"错误"), e, QMessageBox::Ok);
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
* 捕捉语言切换事件
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
		QMessageBox::warning(this, tr(u8"错误"), e, QMessageBox::Ok);
	}
}
