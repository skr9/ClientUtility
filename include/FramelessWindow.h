
/************************************************************************************
* @author : zhuyuejiang
* @date : 2020-04-17
* @brief :
* 这是一个无标题栏的窗体基类，所有想要自绘标题栏，并且要求自绘后可移动的窗体，都可以
* 从这个基类派生
* 该类不提供自绘标题栏，调用者需要继承该类后，设计自己的标题栏，该类只是把标准的标题
* 栏进行了隐藏，并且实现了窗体可移动功能
* 另外，如果派生类重写了mousePressEvent和mouseMoveEvent,请在自身的事件函数里调用相应
* 的基类事件，例如派生类重写了mousePressEvent，就应该在该函数尾部调用FramelessWindow
* 的mousePressEvent， 否则窗体移动功能可以会失效，或者变得很奇怪

* 2020-04-28: 
* 加入了changeEvent事件得重写，并增加了updateLanguage()虚函数,都是为了使继承自本类
* 的所有窗体能够相应界面语言的切换，如典型的中英切换            
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

