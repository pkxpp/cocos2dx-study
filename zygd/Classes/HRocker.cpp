#include "HRocker.h"
const double PI=3.1415;
HRocker::HRocker(void)
{
	rocketRun=false;
}

HRocker::~HRocker(void)
{
}

//����ҡ��(ҡ�˵Ĳ�����ͼƬ��Դ����ҡ�˱���ͼƬ��Դ������ʼ����)
HRocker* HRocker::createHRocker(const char *rockerImageName,const char *rockerBGImageName,CCPoint position)
{
	HRocker *layer = HRocker::create();
	if (layer)
	{
		layer->rockerInit(rockerImageName,rockerBGImageName,position);
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return NULL;
}

//�Զ����ʼ������
void HRocker::rockerInit(const char* rockerImageName,const char* rockerBGImageName,CCPoint position)
{
	CCSprite *spRockerBG = CCSprite::create(rockerBGImageName);
	spRockerBG->setPosition(position);
	spRockerBG->setVisible(false);
	addChild(spRockerBG,0,tag_rockerBG);

	CCSprite *spRocker = CCSprite::create(rockerImageName);
	spRocker->setPosition(position);
	spRocker->setVisible(false);
	addChild(spRocker,1,tag_rocker);

	rockerBGPosition = position;
	rockerBGR = spRockerBG->getContentSize().width*0.5;//
	rocketDirection=-1;//��ʾҡ�˷��򲻱�

	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}

//����ҡ��(��ʾҡ�ˡ�����ҡ�˴����¼�)
void HRocker::startRocker(bool _isStopOther)
{
	Sprite *rocker = (Sprite*)this->getChildByTag(tag_rocker);
	rocker->setVisible(true);

	Sprite *rockerBG = (Sprite *)this->getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);

	//CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-1,_isStopOther);
	//EventDispatcher *_dispatcher = Director::getInstance()->getEventDispatcher();
	//EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	//listener->onTouchBegan = CC_CALLBACK_2(this->onTouchBegan, this);
	//listener->onTouchMoved = CC_CALLBACK_2(this->onTouchMoved, this);
	//listener->onTouchEnded = CC_CALLBACK_2(this->onTouchEnded, this);
	//_dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	setTouchEnabled(true);
}

//ֹͣҡ��(����ҡ�ˣ�ȡ��ҡ�˵Ĵ�������)
void HRocker::stopRocker()
{
	CCSprite *rocker = (CCSprite *)this->getChildByTag(tag_rocker);
	rocker->setVisible(false);

	CCSprite * rockerBG = (CCSprite *)this->getChildByTag(tag_rockerBG);
	rockerBG->setVisible(false);

	//CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	setTouchEnabled(false);
}


//��ȡ��ǰҡ�����û�������ĽǶ�
float HRocker::getRad(CCPoint pos1,CCPoint pos2)
{
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;

	//�õ�����x�ľ���
	float x = px2 - px1;
	//�õ�����y�ľ���
	float y = py1 - py2;
	//���б�߳���
	float xie = sqrt(pow(x,2) + pow(y,2));
	//�õ�����Ƕȵ�����ֵ(ͨ�����Ǻ����еĵ���Ƕ�����ֵ=б��/б��)
	float cosAngle = x / xie;
	//ͨ�������Ҷ����ȡ���ڽǶȵĻ���
	float rad = acos(cosAngle);
	//ע�⣺��������λ��Y����<ҡ�˵�Y���꣬����Ҫȥ��ֵ-0~-180
	if (py2 < py1)
	{
		rad = -rad;
	}
	return rad;
}

CCPoint getAngelePosition(float r,float angle){
	return ccp(r*cos(angle),r*sin(angle));
}

//̧���¼�
bool HRocker::onTouchBegan(Touch *touch, Event *unused_event)
{
	CCPoint point = touch->getLocation();
	CCSprite *rocker = (CCSprite *)this->getChildByTag(tag_rocker);
	if (rocker->boundingBox().containsPoint(point))
		isCanMove = true;
	return true;
}
//�ƶ��¼�
void HRocker::onTouchMoved(Touch *touch, Event *unused_event)
{
	if (!isCanMove)
	{
		return;
	}
	CCPoint point = touch->getLocation();
	CCSprite *rocker = (CCSprite *)this->getChildByTag(tag_rocker);
	//�õ�ҡ���봥�������γɵĽǶ�
	float angle = getRad(rockerBGPosition,point);
	//�ж�����Բ��Բ�ľ��Ƿ����ҡ�˱����İ뾶
	if (sqrt(pow((rockerBGPosition.x - point.x),2) + pow((rockerBGPosition.y - point.y),2)) >= rockerBGR)
	{
	
		//��֤�ڲ�СԲ�˶��ĳ�������
		rocker->setPosition(ccpAdd(getAngelePosition(rockerBGR,angle),ccp(rockerBGPosition.x,rockerBGPosition.y)));
	}
	else
		rocker->setPosition(point);
	//�жϷ���
	if(angle>=-PI/4&&angle<PI/4)
	{
		rocketDirection=rocker_right;
		rocketRun=false;
	}
	else if(angle>=PI/4&&angle<3*PI/4)
	{
		rocketDirection=rocker_up;
	}
	else if((angle>=3*PI/4&&angle<=PI)||(angle>=-PI&&angle<-3*PI/4))
	{
		rocketDirection=rocker_left;
		rocketRun=true;
	}
	else if(angle>=-3*PI/4&&angle<-PI/4)
	{
		rocketDirection=rocker_down;
	}
}
//�뿪�¼�
void HRocker::onTouchEnded(Touch *touch, Event *unused_event)
{
	if (!isCanMove)
	{
		return;
	}
	CCSprite *rockerBG = (CCSprite*)this->getChildByTag(tag_rockerBG);
	CCSprite *rocker = (CCSprite*)this->getChildByTag(tag_rocker);
	rocker->stopAllActions();
	rocker->runAction(CCMoveTo::create(0.08f,rockerBG->getPosition()));
	isCanMove = false;
	rocketDirection=rocker_stay;
}
