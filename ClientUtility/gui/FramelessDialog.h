
/************************************************************************************
* @author : zhuyuejiang
* @date : 2020-5-20
* @brief :
*  这是一个无边框可移动的对话框基类，所有需要实现无边框效果，且可移动的对话框，
*  均可从该类派生以获得上述特性
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

