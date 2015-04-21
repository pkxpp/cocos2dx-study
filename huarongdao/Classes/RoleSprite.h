#ifndef _ROLE_SPRITE_H_
#define _ROLE_SPRITE_H_

#include "cocos2d.h"

class Role ;
class RoleSprite : public cocos2d::Node
{
public:
	static RoleSprite* create(Role * pRole ,int row,int col,const cocos2d::Rect & bounds,cocos2d::Node * pParent ,int zOrder);
public:
	RoleSprite(Role * role,int row,int col);
	~RoleSprite();

	virtual bool init() ;
private:
	CC_SYNTHESIZE(Role * ,m_pRole,Role);
	CC_SYNTHESIZE(int ,m_row ,Row);//<������
	CC_SYNTHESIZE(int ,m_col ,Col);//<������
	CC_SYNTHESIZE_READONLY(int ,m_width ,Width);//<ˮƽ������ռ�ĸ�����
	CC_SYNTHESIZE_READONLY(int ,m_height ,Height);//<��ֱ������ռ�ĸ�����
};

#endif