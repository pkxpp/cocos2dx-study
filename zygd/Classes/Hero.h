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
	 //����ͼƬ������Ӣ��
	 void InitHeroSprite(char *hero_name);
	 //���ö���,numΪͼƬ��Ŀ��run_directonΪ����������false����
	 void SetAnimation(const char *name_plist,const char *name_png,const unsigned int num,bool run_directon);
	//ֹͣ����
	 void StopAnimation();
	//�ж��Ƿ����ܶ���
	 bool IsRunning;
	 //Ӣ���˶��ķ���
	 bool HeroDirecton;
	 // ��������
	 void AttackAnimation(const char *name_plist,const char *name_png,const char *name_each,const unsigned int num,bool run_directon);
 
	//������������
	void AttackEnd();

	 CREATE_FUNC(Hero);
 private:
	 CCSprite* m_HeroSprite;//����
	 char *Hero_name;//���������ʼ״̬�ľ���ͼƬ����
	 bool IsAttack;
 };
#endif // __HERO_H__