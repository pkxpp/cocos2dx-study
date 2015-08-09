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
    //�õ����ڵĴ�С
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //�޸ı���ͼƬ
    CCSprite* pSprite = CCSprite::create("background_1.jpg");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);//�����0��ʾ������ײ�
    
	//���ҡ��
	rocker = HRocker::createHRocker("Direction_bt.png","Direction_bc.png",ccp(110,60));//���е�һ��ͼƬΪҡ�˵İ�ť���ڶ���Ϊ����
	this->addChild(rocker,2);
	rocker->startRocker(true);


	//������ƾ���
	hero=Hero::create();
	hero->InitHeroSprite("zhoayun.png");
	hero->setPosition(ccp(200,200));
	this->addChild(hero,1);
	//hero->SetAnimation("run_animation.plist","run_animation.png",8,true);//8��ʾplist�е�ͼƬ��Ŀ,false��ʾ������

	// ��ӹ�����ť
	btn = MyControlButton::create();
	btn->CreateButton("bt.png");
	btn->setPosition(ccp(visibleSize.width-50, 50));
	this->addChild(btn, 2);

	//����updata�¼�
	this->scheduleUpdate();
    return true;
}

void HelloWorld::update(float delta)
{
	//�ж��Ƿ���ҡ�˼�������
	switch(rocker->rocketDirection)
	{
	case 1:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x+1,hero->getPosition().y)); //������
		break;
	case  2:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x, hero->getPosition().y+1));   //������
		break;
	case 3:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x-1,hero->getPosition().y));   //������
		break;
	case 4:
		hero->SetAnimation("run_animation.plist","run_animation.png",8,rocker->rocketRun);
		hero->setPosition(ccp(hero->getPosition().x,hero->getPosition().y-1));   //������
		break;
	default:
		hero->StopAnimation();//ֹͣ���ж������˶�
		break;

	}
	if (btn->isTouch)
		hero->AttackAnimation("attack1_animation.plist","attack1_animation.png","attack_",6,rocker->rocketRun);
}

