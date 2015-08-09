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
	//ÿ֡����ʱ���õ��¼�
	virtual void update(float delta);
private:
	HRocker* rocker;//ҡ��
	Hero*    hero;///����
	MyControlButton *btn;	// ��ť�ؼ�����
};

#endif // __HELLOWORLD_SCENE_H__
