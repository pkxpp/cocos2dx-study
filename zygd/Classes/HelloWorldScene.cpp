#include "HelloWorldScene.h"


USING_NS_CC;

CCScene* HelloWorld::scene()
{

    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{

    if ( !CCLayer::init() )
    {
        return false;
    }
    //得到窗口的大小
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //修改背景图片
    CCSprite* pSprite = CCSprite::create("background_1.jpg");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);//这里的0表示放在最底层
    
	//添加摇杆
	rocker = HRocker::createHRocker("Direction_bt.png","Direction_bc.png",ccp(110,60));//其中第一张图片为摇杆的按钮，第二张为背景
	this->addChild(rocker,2);
	rocker->startRocker(true);


	//添加赵云精灵
	hero=Hero::create();
	hero->InitHeroSprite("zhoayun.png");
	hero->setPosition(ccp(200,200));
	this->addChild(hero,1);
	//hero->SetAnimation("run_animation.plist","run_animation.png",8,true);//8表示plist中的图片数目,false表示脸朝右

	// 添加攻击按钮
	btn = MyControlButton::create();
	btn->CreateButton("bt.png");
	btn->setPosition(ccp(visibleSize.width-50, 50));
	this->addChild(btn, 2);

	//启动updata事件
	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
	//判断是否按下摇杆及其类型
	switch(rocker->rocketDirection)
	{
	case 1:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x+1,hero->getPosition().y)); //向右走
		break;
	case  2:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x, hero->getPosition().y+1));   //向上走
		break;
	case 3:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x-1,hero->getPosition().y));   //向左走
		break;
	case 4:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x,hero->getPosition().y-1));   //向下走
		break;
	default:
		hero->StopAnimation();//停止所有动画和运动
		break;

	}
	if (btn->isTouch)
		hero->AttackAnimation("attack1_animation.plist","attack1_animation.png","attack_",6,rocker->rocketRun);
}

