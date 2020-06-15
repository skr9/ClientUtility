
/************************************************************************************
* @author : zhuyuejiang
* @date : 2020-5-20
* @brief :
*  ����һ���ޱ߿���ƶ��ĶԻ�����࣬������Ҫʵ���ޱ߿�Ч�����ҿ��ƶ��ĶԻ���
*  ���ɴӸ��������Ի����������
*
*
*
*************************************************************************************/
#ifndef  FRAMELESS_DAILOG_H_
#define FRAMELESS_DAILOG_H_

#include <qdialog.h>
#include <qevent.h>
#include "clientutility_global.h"

class CLIENTUTILITY_EXPORT FramelessDialog:public QDialog
{
public:
	explicit FramelessDialog(QDialog* parent = nullptr);
	virtual ~FramelessDialog() {};

protected:
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

	QPoint _pressPos;
};

#endif // !FRAMELESS_DAILOG_H_

