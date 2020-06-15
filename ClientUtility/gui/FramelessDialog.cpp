#include "FramelessDialog.h"

FramelessDialog::FramelessDialog(QDialog* parent)
{
	this->setWindowFlags(Qt::FramelessWindowHint);  //�ޱ߿�
	this->setAttribute(Qt::WA_TranslucentBackground); //͸������
}


/*********************************************************************
* @input :
*
*
*
* @output :
*
* @brief :
* ��д��갴���¼�����������걻����ʱ������λ��
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
* ��д����ƶ��¼�������ʵ����갴�²��ƶ�ʱ����������ƶ�
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
