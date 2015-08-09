#ifndef __MAP_H__  
#define __MAP_H__  
#include "cocos2d.h"  
USING_NS_CC;   
class MyMap:public Node  
{  
    public:  
         MyMap();  
        ~MyMap();  
        //��ʼ����ͼ,window_sizeoΪ����̨��С  
        void InitMap(const char *map_name,const Size &window_size);  
        //���ݾ����λ���ƶ���ͼ��visibleSizeΪ��ǰ���ڵĴ�С  
        void MoveMap(Node *hero,CCSize visibleSize);  
        //�жϵ�ͼ�Ƿ񵽴��Ե  
        bool JudgeMap(Node *hero,CCSize visibleSize);  
        //virtual void update(float delta);  
        CREATE_FUNC(MyMap);  
           
    private:  
        Sprite *m_map;//��ͼ����  
   
};  
#endif // __MAP_H__