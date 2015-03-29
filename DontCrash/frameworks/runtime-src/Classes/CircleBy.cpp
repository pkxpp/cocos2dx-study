#include "CircleBy.h"
#include <iostream>

CircleBy * CircleBy::create(float tm,Point circleCenter,float randiansValue)
{
    CircleBy * _circle = new CircleBy();
    _circle->init(tm,circleCenter,randiansValue);
    _circle->autorelease();

    return _circle;
}

bool CircleBy::init(float tm,Point circleCenter,float numDegree)
{
    //����ִ��ʱ��
    if(initWithDuration(tm))
    {
        //Բ��
        _originCenter = circleCenter;
        //�뾶
        _radius = sqrt(pow(_originCenter.x,2)+pow(_originCenter.y,2));
        //�ܹ���Ҫת���Ļ�����
        _numDegree = -numDegree/360*2*M_PI;
        //ÿ֡��Ҫת���Ļ���
        _degree = (Director::getInstance()->getAnimationInterval())*_numDegree/tm;
        //ˢ�´���
        _times = 1;
        //������ʼ������
        _beginDegree = M_PI+atan2f(_originCenter.y,_originCenter.x);

        return true;
    }

    return false;
}

void CircleBy::startWithTarget(Node * target)
{
    ActionInterval::startWithTarget(target);

    if(_times == 1 && (int)_numDegree%360 == 0)
        _circleCenter = _originCenter+target->getPosition();
    else
        _circleCenter = _originCenter+target->getPosition();
    _times = 1;
}

//��������������update������ÿ֡ˢ������
void CircleBy::update(float t)
{
    //������
    auto degree = _degree*_times+_beginDegree;
	auto testDegree = (_numDegree * t) + _beginDegree;

    auto x = _radius*cos(testDegree);
    auto y = _radius*sin(testDegree);

    _target->setPosition(Point(x+_circleCenter.x,y+_circleCenter.y));

    _times++;

    /*���µĴ��뽫��Բ���˶��Ĺ켣�����˳�������Ҫ��ʱ�����ɾ����*/
    auto draw = DrawNode::create();
    _target->getParent()->addChild(draw);
    draw->drawDot(_target->getPosition(),1,Color4F(1,1,1,1));
}

CircleBy* CircleBy::reverse() const
{
    return CircleBy::create(_duration,_originCenter,_numDegree*360/(2*M_PI));
}

CircleBy* CircleBy::clone() const
{
	CircleBy * _circle = new CircleBy();
    _circle->init(_duration,_originCenter,-_numDegree*360/(2*M_PI));
    _circle->autorelease();
    return _circle;
}
//#include "CircleBy.h"
//
//CircleBy * CircleBy::create(float tm,Point circleCenter,float randiansValue)
//{
//    CircleBy * _circle = new CircleBy();
//    _circle->init(tm,circleCenter,randiansValue);
//    _circle->autorelease();
//
//    return _circle;
//}
//
//bool CircleBy::init(float tm,Point circleCenter,float randiansValue)
//{
//    //����ִ��ʱ��
//    if(initWithDuration(tm))
//    {
//        //��ʼ��Բ�ĺͰ뾶
//        this->_circleCenter = circleCenter;
//        _radius = sqrt(pow(_circleCenter.x,2)+pow(_circleCenter.y,2));
//        //ÿ֡��Ҫת���Ļ���
//        this->_radians = (Director::getInstance()->getAnimationInterval())*2*M_PI/tm;
//        //�������������С���㣬������������ʱ���Բ���˶�
//        if(randiansValue<0)
//            _radians = -_radians;
//        //ˢ�´���
//        this->_times = 1;
//        //��ʼ������
//        this->_radiansValue = randiansValue/360*2*M_PI;
//        //��ת�ĽǶȣ�Ĭ��Ϊ360
//        this->_maxRadians = 2*M_PI;
//
//        return true;
//    }
//
//    return false;
//}
//
//void CircleBy::startWithTarget(Node * target)
//{
//    ActionInterval::startWithTarget(target);
//    //����ִ�ж���������������³�ʼ��Բ�ģ�repeat��ʱ����ε��øú��������������ж��Ƿ��ǵ�һ��
//    if(_times == 1)
//        _circleCenter = _circleCenter+target->getPosition();
//}
//
//void CircleBy::setRadians(float radians)
//{
//    auto val = radians/360*2*M_PI;
//    this->_radians = _radians/_radians*(Director::getInstance()->getAnimationInterval())*val/_duration;
//    //�������������С���㣬������������ʱ���Բ���˶�
//    if(_radiansValue<0)
//        _radians = -_radians;
//}
//
////��������������update������ÿ֡ˢ������
//void CircleBy::update(float)
//{
//    auto radians = _radiansValue;
//    //���radiansС���㣬��Ҫ����ʱ���Բ���˶�
//    if(radians<0)
//        radians = -radians;
//    radians = _radians*_times+radians;
//
//    auto x = _radius*sin(radians);
//    auto y = _radius*cos(radians);
//
//    _target->setPosition(Point(x+_circleCenter.x,y+_circleCenter.y));
//
//    _times++;
//
//    /*���µĴ��뽫��Բ���˶��Ĺ켣�����˳�������Ҫ��ʱ�����ɾ����*/
//
//    //����һ��drawNode������ͼ
//    auto draw = DrawNode::create();
//    //��DrawNode��ӵ����ڵ��У��������Ƶ�λ�þͺ�ִ�ж�����sprite��ͬһ���ڵ�����ϵ��
//    _target->getParent()->addChild(draw);
//    //����
//    draw->drawDot(_target->getPosition(),1,Color4F(1,1,1,1));
//}
//
////����������ʱ�뷽��ת��
//CircleBy* CircleBy::reverse() const
//{
//    return CircleBy::create(_duration,_circleCenter,-_radiansValue*360/(2*M_PI));
//}
//
////��¡һ����ͬ�Ķ�����init�����ʱ��ת��Ϊ�Ƕ�
//CircleBy* CircleBy::clone() const
//{
//	auto a = new CircleBy();
//	a->init(_duration,_circleCenter,_radiansValue*360/(2*M_PI));
//	a->autorelease();
//	return a;
//}