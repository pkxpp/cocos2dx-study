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
    //动作执行时间
    if(initWithDuration(tm))
    {
        //圆心
        _originCenter = circleCenter;
        //半径
        _radius = sqrt(pow(_originCenter.x,2)+pow(_originCenter.y,2));
        //总共需要转过的弧度数
        _numDegree = -numDegree/360*2*M_PI;
        //每帧需要转过的弧度
        _degree = (Director::getInstance()->getAnimationInterval())*_numDegree/tm;
        //刷新次数
        _times = 1;
        //计算起始弧度数
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

//动作管理器调用update函数，每帧刷新坐标
void CircleBy::update(float t)
{
    //弧度数
    auto degree = _degree*_times+_beginDegree;
	auto testDegree = (_numDegree * t) + _beginDegree;

    auto x = _radius*cos(testDegree);
    auto y = _radius*sin(testDegree);

    _target->setPosition(Point(x+_circleCenter.x,y+_circleCenter.y));

    _times++;

    /*以下的代码将做圆周运动的轨迹绘制了出来，必要的时候可以删除掉*/
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
//    //动作执行时间
//    if(initWithDuration(tm))
//    {
//        //初始化圆心和半径
//        this->_circleCenter = circleCenter;
//        _radius = sqrt(pow(_circleCenter.x,2)+pow(_circleCenter.y,2));
//        //每帧需要转过的弧度
//        this->_radians = (Director::getInstance()->getAnimationInterval())*2*M_PI/tm;
//        //如果第三个参数小于零，代表做的是逆时针的圆周运动
//        if(randiansValue<0)
//            _radians = -_radians;
//        //刷新次数
//        this->_times = 1;
//        //初始弧度数
//        this->_radiansValue = randiansValue/360*2*M_PI;
//        //旋转的角度，默认为360
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
//    //根据执行动作精灵的坐标重新初始化圆心，repeat的时候会多次调用该函数，所以这里判断是否是第一次
//    if(_times == 1)
//        _circleCenter = _circleCenter+target->getPosition();
//}
//
//void CircleBy::setRadians(float radians)
//{
//    auto val = radians/360*2*M_PI;
//    this->_radians = _radians/_radians*(Director::getInstance()->getAnimationInterval())*val/_duration;
//    //如果第三个参数小于零，代表做的是逆时针的圆周运动
//    if(_radiansValue<0)
//        _radians = -_radians;
//}
//
////动作管理器调用update函数，每帧刷新坐标
//void CircleBy::update(float)
//{
//    auto radians = _radiansValue;
//    //如果radians小于零，需要做逆时针的圆周运动
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
//    /*以下的代码将做圆周运动的轨迹绘制了出来，必要的时候可以删除掉*/
//
//    //创建一个drawNode用来绘图
//    auto draw = DrawNode::create();
//    //将DrawNode添加到父节点中，这样绘制的位置就和执行动作的sprite在同一个节点坐标系中
//    _target->getParent()->addChild(draw);
//    //画点
//    draw->drawDot(_target->getPosition(),1,Color4F(1,1,1,1));
//}
//
////反动作，逆时针方向转动
//CircleBy* CircleBy::reverse() const
//{
//    return CircleBy::create(_duration,_circleCenter,-_radiansValue*360/(2*M_PI));
//}
//
////克隆一个相同的动作，init传入的时候转化为角度
//CircleBy* CircleBy::clone() const
//{
//	auto a = new CircleBy();
//	a->init(_duration,_circleCenter,_radiansValue*360/(2*M_PI));
//	a->autorelease();
//	return a;
//}