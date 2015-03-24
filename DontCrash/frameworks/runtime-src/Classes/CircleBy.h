//#ifndef __Test2__CircleBy__
//#define __Test2__CircleBy__
//
//#include "cocos2d.h"
//
//USING_NS_CC;
//
////Բ���˶�
//class CircleBy : public ActionInterval
//{
//public:
//    //tm����Բ���˶���ʱ�䣬circleCenter����Բ�ģ��뾶�Ǹ��ݾ��鵱ǰ��λ�ú�Բ�ĵľ����������ģ�����Ҫ��Ϊ�������ݽ�ȥ����������������Ƕ�������ȷ����ǰ�ڵ���Բ���˶��е�λ��
//    static CircleBy * create(float tm,Point circleCenter,float randiansValue);
//    //��ʼ������
//    bool init(float tm,Point circleCenter,float randiansValue);
//    //�Ӹ���̳���Ҫ��д�ķ���
//    virtual void update(float);
//    //ȷ��ִ�ж����Ľڵ��Ժ���õķ���
//    virtual void startWithTarget(Node *target);
//    //������ת
//    virtual CircleBy * reverse() const;
//    //��¡һ����ͬ�Ķ���
//    virtual CircleBy * clone() const;
//    //������ת���ٶȣ�Ĭ������Բ���˶���һ����Բ
//    void setRadians(float radians);
//private:
//    //Բ��
//    Point _circleCenter;
//    //�뾶
//    float _radius;
//    //ÿ֡��Ҫת���Ļ�����
//    float _radians;
//    //��ʼ�ĽǶ���
//    float _radiansValue;
//    //��ת�Ƕȣ�Ĭ����360��Ҳ������һ��������Բ���˶�
//    float _maxRadians;
//    //ˢ�´���
//    int _times;
//};
//
//#endif /* defined(__Test2__CircleBy__) */

#ifndef __Test2__CircleBy__
#define __Test2__CircleBy__

#include "cocos2d.h"

USING_NS_CC;

//Բ���˶�
class CircleBy : public ActionInterval
{
public:
    //ʱ�䣬Բ�ģ�һ����Ҫ��ת�ĽǶ�
    static CircleBy * create(float tm,Point circleCenter,float numDegree);
    bool init(float tm,Point circleCenter,float degree);
    virtual void update(float);
    virtual void startWithTarget(Node *target);
    virtual CircleBy * reverse() const;
    virtual CircleBy * clone() const;
private:
    //Բ��
    Point _circleCenter;
    Point _originCenter;
    //�뾶
    float _radius;
    //һ����Ҫת�Ļ���
    float _numDegree;
    //ÿ֡��Ҫת���Ļ�����
    float _degree;
    //��ʼ������
    float _beginDegree;
    //ˢ�´���
    int _times;
};

#endif /* defined(__Test2__CircleBy__) */