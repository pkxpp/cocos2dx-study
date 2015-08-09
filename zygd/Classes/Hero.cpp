#include "Hero.h"
USING_NS_CC; 
USING_NS_CC_EXT;
Hero::Hero(void)
{
	IsRunning=false;//没在放动画
	HeroDirecton=false;//向右运动
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
 //原地奔跑动画
 void Hero::SetAnimation(const char *name_plist,const char *name_png,const char *name_each,unsigned int num,bool run_directon)
 {
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;
	 m_HeroSprite->setFlipX(run_directon);
	 }
	 if(IsRunning)
		 return;
	 //将图片加载到精灵帧缓存池
	SpriteFrameCache *m_frameCache=SpriteFrameCache::sharedSpriteFrameCache();
	 m_frameCache->addSpriteFramesWithFile(name_plist,name_png);
	 //用一个列表保存所有的CCSpriteFrameCache
	 Vector<SpriteFrame*> frameArray;//= CCArray::createWithCapacity(num);
	 unsigned int i;
	 for(i=1;i<=num;i++)
	 {
		 SpriteFrame* frame=m_frameCache->spriteFrameByName(CCString::createWithFormat("%s%d.png",name_each,i)->getCString());
		 frameArray.pushBack(frame);
	 }
	 //使用列表创建动画对象
	 CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
	 if(HeroDirecton!=run_directon)
	 {   HeroDirecton=run_directon;
		 
	 }
	 animation->setLoops(-1);//表示无限循环播放
	animation->setDelayPerUnit(0.1f);//每两张图片的时间隔，图片数目越少，间隔最小就越小

	 //将动画包装成一个动作
	 CCAnimate* act=CCAnimate::create(animation);
	
	
	 m_HeroSprite->runAction(act);
	 IsRunning=true;

 }
 void Hero::StopAnimation()
 {
	 if(!IsRunning)
		 return;
	m_HeroSprite->stopAllActions();//当前精灵停止所有动画

	//恢复精灵原来的初始化贴图 
	this->removeChild(m_HeroSprite,TRUE);//把原来的精灵删除掉
	m_HeroSprite=CCSprite::create(Hero_name);//恢复精灵原来的贴图样子
	m_HeroSprite->setFlipX(HeroDirecton);
	this->addChild(m_HeroSprite);
	IsRunning=false;
	IsRunning=false;
 }

 void Hero::AttackAnimation(const char *name_plist,const char *name_png,const char *name_each,const unsigned int num,bool run_directon)
  {
      if(IsAttack)
          return;
      //将图片加载到精灵帧缓存池
     SpriteFrameCache *m_frameCache= SpriteFrameCache::sharedSpriteFrameCache();
      m_frameCache->addSpriteFramesWithFile(name_plist,name_png);
     Vector<SpriteFrame*> frameArray;
      unsigned int i;
      for(i=1;i<=num;i++)
      {
          SpriteFrame* frame=m_frameCache->spriteFrameByName(CCString::createWithFormat("%s%d.png",name_each,i)->getCString());
		  frameArray.pushBack(frame);
      }
      //使用列表创建动画对象
      CCAnimation* animation=CCAnimation::createWithSpriteFrames(frameArray);
      if(HeroDirecton!=run_directon)
      {   HeroDirecton=run_directon;
 
      }
      animation->setLoops(1);//表示循环播放次
      animation->setDelayPerUnit(0.1f);//每两张图片的时间隔，图片数目越少，间隔最小就越小
 
      //将动画包装成一个动作
      CCAnimate* act=CCAnimate::create(animation);
      //创建回调动作，攻击结束后调用AttackEnd()
      CCCallFunc* callFunc=CCCallFunc::create(this,callfunc_selector(Hero::AttackEnd));
      //创建连续动作
     CCActionInterval* attackact=CCSequence::create(act,callFunc,NULL);
      IsAttack=true;
      m_HeroSprite->runAction(attackact); 
 
  }
  void Hero::AttackEnd()
  {
      //恢复精灵原来的初始化贴图 
      this->removeChild(m_HeroSprite,TRUE);//把原来的精灵删除掉
      m_HeroSprite=CCSprite::create(Hero_name);//恢复精灵原来的贴图样子
      m_HeroSprite->setFlipX(HeroDirecton);
      this->addChild(m_HeroSprite);
       IsAttack=false;
  }

bool Hero::JudgePositona (Size visibleSize)  
{  
     if(this->getPositionX()!=visibleSize.width/2)//精灵到达左边  
          return false;  
     else  
          return true;//到达中间位置  
}