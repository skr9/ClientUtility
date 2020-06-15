#include "FramelessDialog.h"

FramelessDialog::FramelessDialog(QDialog* parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint);  //无边框
	this->setAttribute(Qt::WA_TranslucentBackground); //透明背景
}


/*********************************************************************
* @input :
*
*
*
* @output :
*
* @brief :
* 重写鼠标按下事件，用于在鼠标被按下时的坐标位置
*
*
**********************************************************************/
void FramelessDialog::mousePressEvent(QMouseEvent* event)
{
	_pressPos = event->globalPos() - this->pos();
}


/*********************************************************************
* @input :
*
*
*
* @output :
*
* @brief :
* 重写鼠标移动事件，用以实现鼠标按下并移动时，窗体跟随移动
*
*
**********************************************************************/
void FramelessDialog::mouseMoveEvent(QMouseEvent* event)
{
	auto dpos = event->globalPos() - _pressPos;
	if (dpos.x() > 100 || dpos.y() > 100)
	{
		this->move(dpos);
		_pressPos = event->globalPos() - pos();
	}
}
