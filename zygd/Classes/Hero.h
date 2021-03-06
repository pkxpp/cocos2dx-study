#ifndef __HERO_H__
#define __HERO_H__
#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
USING_NS_CC_EXT; 
 class Hero:public cocos2d::CCNode
 {
 public:
	   Hero(void);
	  ~Hero(void);
	 //根据图片名创建英雄
	 void InitHeroSprite(char *hero_name);
	 //设置动画,num为图片数目，run_directon为精灵脸朝向，false朝右
	 void SetAnimation(const char *name_plist,const char *name_png,const char *name_each,const unsigned int num,bool run_directon);
	//停止动画
	 void StopAnimation();
	//判断是否在跑动画
	 bool IsRunning;
	 //英雄运动的方向
	 bool HeroDirecton;
	 // 攻击动画
	 void AttackAnimation(const char *name_plist,const char *name_png,const char *name_each,const unsigned int num,bool run_directon);
 
	//攻击动画结束
	void AttackEnd();

	//判断英雄是否运动到了窗口的中间位置,visibleSize为当前窗口的大小  
	bool JudgePositona(Size visibleSize); 

	 CREATE_FUNC(Hero);
 private:
	 CCSprite* m_HeroSprite;//精灵
	 char *Hero_name;//用来保存初始状态的精灵图片名称
	 bool IsAttack;
 };
#endif // __HERO_H__