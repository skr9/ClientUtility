
/************************************************************************************
* @author : zhuyuejiang
* @date : 2020-04-17
* @brief :
* ����һ���ޱ������Ĵ�����࣬������Ҫ�Ի������������Ҫ���Ի����ƶ��Ĵ��壬������
* �������������
* ���಻�ṩ�Ի����������������Ҫ�̳и��������Լ��ı�����������ֻ�ǰѱ�׼�ı���
* �����������أ�����ʵ���˴�����ƶ�����
* ���⣬�����������д��mousePressEvent��mouseMoveEvent,����������¼������������Ӧ
* �Ļ����¼���������������д��mousePressEvent����Ӧ���ڸú���β������FramelessWindow
* ��mousePressEvent�� �������ƶ����ܿ��Ի�ʧЧ�����߱�ú����

* 2020-04-28: 
* ������changeEvent�¼�����д����������updateLanguage()�麯��,����Ϊ��ʹ�̳��Ա���
* �����д����ܹ���Ӧ�������Ե��л�������͵���Ӣ�л�            
*************************************************************************************/
#ifndef _FRAMELESS_WINDOW_H_
#define _FRAMELESS_WINDOW_H_

#include <qmainwindow.h>
#include <qevent.h>
#include <qtranslator.h>
#include "clientutility_global.h"

class CLIENTUTILITY_EXPORT FramelessWindow:public QMainWindow
{
public:
	explicit FramelessWindow(QWidget* parent = nullptr);
	virtual ~FramelessWindow();

	void setTranslator(QTranslator* tr) { _translator = tr; };

protected:
	virtual void updateLanguage();

	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);

	void changeEvent(QEvent* event);

	bool _movable;
	QPoint _pressPos;
	QTranslator* _translator;
};

#endif // !1

