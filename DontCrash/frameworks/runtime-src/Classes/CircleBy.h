//#ifndef __Test2__CircleBy__
//#define __Test2__CircleBy__
//
//#include "cocos2d.h"
//
//USING_NS_CC;
//
////圆周运动
//class CircleBy : public ActionInterval
//{
//public:
//    //tm代表圆周运动的时间，circleCenter代表圆心，半径是根据精灵当前的位置和圆心的距离计算出来的，不需要作为参数传递进去，第三个参数代表角度数，来确定当前节点在圆周运动中的位置
//    static CircleBy * create(float tm,Point circleCenter,float randiansValue);
//    //初始化参数
//    bool init(float tm,Point circleCenter,float randiansValue);
//    //从父类继承需要覆写的方法
//    virtual void update(float);
//    //确定执行动作的节点以后调用的方法
//    virtual void startWithTarget(Node *target);
//    //动作翻转
//    virtual CircleBy * reverse() const;
//    //克隆一个相同的动作
//    virtual CircleBy * clone() const;
//    //设置旋转多少度，默认做的圆周运动是一个整圆
//    void setRadians(float radians);
//private:
//    //圆心
//    Point _circleCenter;
//    //半径
//    float _radius;
//    //每帧需要转过的弧度数
//    float _radians;
//    //初始的角度数
//    float _radiansValue;
//    //旋转角度，默认是360，也就是做一个完整的圆周运动
//    float _maxRadians;
//    //刷新次数
//    int _times;
//};
//
//#endif /* defined(__Test2__CircleBy__) */

#ifndef __Test2__CircleBy__
#define __Test2__CircleBy__

#include "cocos2d.h"

USING_NS_CC;

//圆周运动
class CircleBy : public ActionInterval
{
public:
    //时间，圆心，一共需要旋转的角度
    static CircleBy * create(float tm,Point circleCenter,float numDegree);
    bool init(float tm,Point circleCenter,float degree);
    virtual void update(float);
    virtual void startWithTarget(Node *target);
    virtual CircleBy * reverse() const;
    virtual CircleBy * clone() const;
private:
    //圆心
    Point _circleCenter;
    Point _originCenter;
    //半径
    float _radius;
    //一共需要转的弧度
    float _numDegree;
    //每帧需要转过的弧度数
    float _degree;
    //起始弧度数
    float _beginDegree;
    //刷新次数
    int _times;
};

#endif /* defined(__Test2__CircleBy__) */