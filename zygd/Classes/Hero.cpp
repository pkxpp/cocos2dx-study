#include "Hero.h"
USING_NS_CC; 
USING_NS_CC_EXT;
Hero::Hero(void)
{
	IsRunning=false;//û�ڷŶ���
	HeroDirecton=false;//�����˶�
	Hero_name=NULL;
	IsAttack = false;
}

Hero::~Hero(void)
{

}
 void Hero::InitHeroSprite(char *hero_name)
 {
	Hero_name=hero_name;
	this->m_HeroSprite=CCSprite::create(hero_name);
	this->addChild(m_HeroSprite);
 }
 //ԭ�ر��ܶ���
 void Hero::SetAnimation(const char *name_plist,const char *name_png,const char *name_each,unsigned int num,bool run_directon)
 {
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;
	 m_HeroSprite->setFlipX(run_directon);
	 }
	 if(IsRunning)
		 return;
	 //��ͼƬ���ص�����֡�����
	SpriteFrameCache *m_frameCache=SpriteFrameCache::sharedSpriteFrameCache();
	 m_frameCache->addSpriteFramesWithFile(name_plist,name_png);
	 //��һ���б������е�CCSpriteFrameCache
	 Vector<SpriteFrame*> frameArray;//= CCArray::createWithCapacity(num);
	 unsigned int i;
	 for(i=1;i<=num;i++)
	 {
		 SpriteFrame* frame=m_frameCache->spriteFrameByName(CCString::createWithFormat("%s%d.png",name_each,i)->getCString());
		 frameArray.pushBack(frame);
	 }
	 //ʹ���б�����������
	 CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;
		 
	 }
	 animation->setLoops(-1);//��ʾ����ѭ������
	animation->setDelayPerUnit(0.1f);//ÿ����ͼƬ��ʱ�����ͼƬ��ĿԽ�٣������С��ԽС

	 //��������װ��һ������
	 CCAnimate* act=CCAnimate::create(animation);
	
	
	 m_HeroSprite->runAction(act);
	 IsRunning=true;

 }
 void Hero::StopAnimation()
 {
	 if(!IsRunning)
		 return;
	m_HeroSprite->stopAllActions();//��ǰ����ֹͣ���ж���

	//�ָ�����ԭ���ĳ�ʼ����ͼ 
	this->removeChild(m_HeroSprite,TRUE);//��ԭ���ľ���ɾ����
	m_HeroSprite=CCSprite::create(Hero_name);//�ָ�����ԭ������ͼ����
	m_HeroSprite->setFlipX(HeroDirecton);
	this->addChild(m_HeroSprite);
	IsRunning=false;
	IsRunning=false;
 }

 void Hero::AttackAnimation(const char *name_plist,const char *name_png,const char *name_each,const unsigned int num,bool run_directon)
  {
      if(IsAttack)
          return;
      //��ͼƬ���ص�����֡�����
     SpriteFrameCache *m_frameCache= SpriteFrameCache::sharedSpriteFrameCache();
      m_frameCache->addSpriteFramesWithFile(name_plist,name_png);
     Vector<SpriteFrame*> frameArray;
      unsigned int i;
      for(i=1;i<=num;i++)
      {
          SpriteFrame* frame=m_frameCache->spriteFrameByName(CCString::createWithFormat("%s%d.png",name_each,i)->getCString());
		  frameArray.pushBack(frame);
      }
      //ʹ���б�����������
      CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
      if(HeroDirecton!=run_directon)
      {   HeroDirecton=run_directon;
 
      }
      animation->setLoops(1);//��ʾѭ�����Ŵ�
      animation->setDelayPerUnit(0.1f);//ÿ����ͼƬ��ʱ�����ͼƬ��ĿԽ�٣������С��ԽС
 
      //��������װ��һ������
      CCAnimate* act=CCAnimate::create(animation);
      //�����ص��������������������AttackEnd()
      CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(Hero::AttackEnd));
      //������������
     CCActionInterval* attackact=CCSequence::create(act,callFunc,NULL);
      IsAttack=true;
      m_HeroSprite->runAction(attackact); 
 
  }
  void Hero::AttackEnd()
  {
      //�ָ�����ԭ���ĳ�ʼ����ͼ 
      this->removeChild(m_HeroSprite,TRUE);//��ԭ���ľ���ɾ����
      m_HeroSprite=CCSprite::create(Hero_name);//�ָ�����ԭ������ͼ����
      m_HeroSprite->setFlipX(HeroDirecton);
      this->addChild(m_HeroSprite);
       IsAttack=false;
  }

bool Hero::JudgePositona (Size visibleSize)  
{  
     if(this->getPositionX()!=visibleSize.width/2)//���鵽�����  
          return false;  
     else  
          return true;//�����м�λ��  
}