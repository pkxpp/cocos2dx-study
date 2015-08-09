#ifndef __MyControlButton_H__
#define __MyControlButton_H__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT; 
//���ڱ�ʶ��ǰ��ť��״̬
typedef enum{
    touch_begin,
    touch_down,
    touch_up,
}tagForTouch;
class MyControlButton :public CCNode
{
public:
    MyControlButton();
    ~MyControlButton();
    CREATE_FUNC(MyControlButton);
    //������ť,����name_pngΪ��ť�ı���ͼƬ��button_titleΪ��ťͼƬ��Ҫ��ʾ�����֣�numΪ���ֵ�͸����0-100��0Ϊ͸��
     void CreateButton(const char* name_png,const char* button_title="0",unsigned int num=0);
    //��д��ť�¼� 
    void BindButtonEven();
    /* ����괦�ڰ��²��������а�ťʱ���򴥷�һ�� */ 
    void touchDownAction(Ref* pSender, Control::EventType controlEvent); 
    /* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷�һ�� */  
    void touchDragEnter(Ref* pSender, Control::EventType controlEvent);  
    /* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷�һ�� */  
    void touchDragExit(Ref* pSender, Control::EventType controlEvent);  
    /* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
    void touchDragInside(Ref* pSender, Control::EventType controlEvent);  
    /* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */ 
    void touchDragOutside(Ref* pSender, Control::EventType controlEvent);  
    /* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */
    void touchUpInside(Ref* pSender, Control::EventType controlEvent);  
    /* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�⣬�򴥷�һ�� */  
    void touchUpOutside(Ref* pSender, Control::EventType controlEvent);  
    /* ��ʱû�з���������괥������¼��Ĳ���������ע�ͣ�Ӧ�����������¼��жϰ�ť�¼��������� */ 
    void touchCancel(Ref* pSender, Control::EventType controlEvent);
    //�Ƿ��°�ť
    bool isTouch;
private:
    //��ť�ؼ�����
    ControlButton* controlBtn;
};
#endif