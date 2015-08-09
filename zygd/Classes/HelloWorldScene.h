#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "HRocker.h"
#include "Hero.h"
#include "MyControlButton.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    CREATE_FUNC(HelloWorld);
	//每帧更新时调用的事件
	virtual void update(float delta);
private:
	HRocker* rocker;//摇杆
	Hero*    hero;///精灵
	MyControlButton *btn;	// 按钮控件变量
};

#endif // __HELLOWORLD_SCENE_H__
