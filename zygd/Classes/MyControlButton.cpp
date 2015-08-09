#include "MyControlButton.h"
MyControlButton::MyControlButton():controlBtn(NULL),isTouch(false)
{
}
MyControlButton::~MyControlButton()
{
 
}
void MyControlButton::CreateButton(const char* name_png,const char* button_title,unsigned int num)
{
    //�õ���ťͼƬ�Ĵ�С 
    Scale9Sprite* btn = Scale9Sprite::create(name_png);  
    CCLOG("%f",btn->getContentSize().width);
    CCLOG("%f",btn->getContentSize().height);
    int  png_height=static_cast<int>(btn->getContentSize().height);
    int  png_width=static_cast<int>( btn->getContentSize().width);
    //btn->release();
 
    //Ҫ��ʾ��ͼƬ��С 
    CCRect rect = CCRectMake(0,0,png_width,png_height);   //ͼƬ�Ĵ�С  
    CCRect rectInsets = CCRectMake(1,1,1,1); //left��right��width��height  
 
    //��ť����,Marker FeltΪ�������ͣ�png_heightΪ����߶�
    CCLabelTTF *title = CCLabelTTF::create(button_title, "Marker Felt",png_height-10);  
    title->setOpacity(num);//���ÿɼ���
 
    //����״̬�µİ�ťͼƬ 
    Scale9Sprite *btnNormal = Scale9Sprite::create(name_png,rect,rectInsets);  
     
    //������ť
    controlBtn = ControlButton::create(title,btnNormal); 
    this->addChild(controlBtn); 
    //���¼�
    BindButtonEven();
     
     
}
void MyControlButton::BindButtonEven()
{
    if(!controlBtn)
        return;
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchDownAction),Control::EventType::TOUCH_DOWN);  
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchDragEnter),Control::EventType::DRAG_ENTER);  
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchDragExit),Control::EventType::DRAG_EXIT);  
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchDragInside),Control::EventType::DRAG_INSIDE);      
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchDragOutside),Control::EventType::DRAG_OUTSIDE);    
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchUpInside),Control::EventType::TOUCH_UP_INSIDE);  
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchUpOutside),Control::EventType::TOUCH_UP_OUTSIDE);  
    controlBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MyControlButton::touchCancel),Control::EventType::TOUCH_CANCEL); 
}
/* ����괦�ڰ��²��������а�ťʱ���򴥷�һ�� */  
void MyControlButton::touchDownAction(Ref* pSender, Control::EventType controlEvent)
{
    isTouch=true;
 
}
/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷�һ�� */  
void MyControlButton::touchDragEnter(Ref* pSender, Control::EventType controlEvent)
{
     
}
/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷�һ�� */  
void MyControlButton::touchDragExit(Ref* pSender, Control::EventType controlEvent)
{
     
}
/* ����괦�ڰ��²��������а�ť��״̬�£������밴ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
void MyControlButton::touchDragInside(Ref* pSender, Control::EventType controlEvent)
{
 
}
/* ����괦�ڰ��²��������а�ť��״̬�£�����뿪��ť��Χ���򴥷���ֻҪ�ﵽ�������Ͳ��ϴ��� */  
void MyControlButton::touchDragOutside(Ref* pSender, Control::EventType controlEvent)
{
 
}
/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�ڣ��򴥷�һ�� */  
void MyControlButton::touchUpInside(Ref* pSender, Control::EventType controlEvent)
{
    isTouch=false;
 
}
 
/* ����괦�ڰ��²��������а�ť��״̬�£�����ɿ����ڰ�ť��Χ�⣬�򴥷�һ�� */  
void MyControlButton::touchUpOutside(Ref* pSender, Control::EventType controlEvent)
{
     
 
}
/* ��ʱû�з���������괥������¼��Ĳ���������ע�ͣ�Ӧ�����������¼��жϰ�ť�¼��������� */ 
void MyControlButton::touchCancel(Ref* pSender, Control::EventType controlEvent)
{
 
}