#ifndef _ROLE_H_
#define _ROLE_H_

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"

#define  IF_NULL_RETURN_FALSE(_x_) if(_x_ == nullptr) return false 

using namespace tinyxml2 ;
USING_NS_CC ;
typedef enum 
{
	kRoleTypeNone = 0,
	kRoleTypeBoss,//<�ܲ�
	kRoleTypeArmyGeneralHorizontal,//<����Ľ���
	kRoleTypeArmyGeneralVertical,//<��ֱ�Ľ���
	kRoleTypeSoldier,//<ʿ��
}RoleType;
class Role : public Ref
{
public:
	static  cocos2d::Vector<Role*> s_roleVec ;
	static const char * XML_FILE_NAME ;
	static bool initStatic();
	static bool parseData(XMLElement * pElement) ;
	static void finalizeStatic();
public:
	Role();
	~Role();

	bool init(XMLElement * pElement);
	RoleType getTypeByChar(const char * pType);
private:
	CC_SYNTHESIZE_READONLY(int ,m_id,ID) ;
	CC_SYNTHESIZE_READONLY(int ,m_width,Width) ;
	CC_SYNTHESIZE_READONLY(int ,m_height,Height) ;
	CC_SYNTHESIZE_READONLY(RoleType,m_type,Type);
	CC_SYNTHESIZE_READONLY(cocos2d::__String *,m_pImageName,ImageName) ;
};

#endif