#ifndef __MAP_H__  
#define __MAP_H__  
#include "cocos2d.h"  
USING_NS_CC;   
class MyMap:public Node  
{  
    public:  
         MyMap();  
        ~MyMap();  
        //初始化地图,window_sizeo为控制台大小  
        void InitMap(const char *map_name,const Size &window_size);  
        //根据精灵的位置移动地图，visibleSize为当前窗口的大小  
        void MoveMap(Node *hero,CCSize visibleSize);  
        //判断地图是否到达边缘  
        bool JudgeMap(Node *hero,CCSize visibleSize);  
        //virtual void update(float delta);  
        CREATE_FUNC(MyMap);  
           
    private:  
        Sprite *m_map;//地图精灵  
   
};  
#endif // __MAP_H__