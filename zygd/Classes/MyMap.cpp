#include "MyMap.h"  
MyMap::MyMap():m_map(NULL)  
{  
   
}  
MyMap::~MyMap()  
{  
   
}  
void MyMap::InitMap(const char *map_name,const Size &window_size)  
{  
    this->m_map=Sprite::create(map_name);  
    m_map->setAnchorPoint(ccp(0,0));//����ê��  
    this->setAnchorPoint(ccp(0,0));//����ê��  
    this->addChild(m_map);   
   
}  
void MyMap::MoveMap(Node *hero,Size visibleSize)//  
{  
    if(hero->getPositionX()==visibleSize.width/2)//�����˶����м䣬��ͼ���ƶ�  
    {  
        if(this->getPositionX()!=-(m_map->getContentSize().width-visibleSize.width))//��ֹ��ͼ����˶��󳬳���Ե  
        this->setPosition(this->getPositionX()-1,this->getPositionY());  
    }  
}  
bool MyMap::JudgeMap(Node *hero,Size visibleSize)  
{  
    if(this->getPositionX()!=-(m_map->getContentSize().width-visibleSize.width))//��ֹ��ͼ����˶��󳬳���Ե  
        return false;  
    else //��ͼ�Ѿ��ƶ������Ե  
    return true;  
}