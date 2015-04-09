#include "SGCommon.h"

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;

void getJsonFromFile(const char* fileName, rapidjson::Document &jsonDict)
{
	unsigned char *pBytes = NULL; 
    std::string jsonpath; 
    jsonpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName); 
    ssize_t size = 0; 
    pBytes = CCFileUtils::sharedFileUtils()->getFileData(jsonpath.c_str(), "r" , &size); 
    CCData *data = new CCData(); 
	data->copy(pBytes, size);
    std::string load_str = std::string((const char *)data->getBytes(), data->getSize() ); 
    CC_SAFE_DELETE(data); 
    jsonDict.Parse<0>(load_str.c_str()); 
}

int roleToIndex(string roleName)
{
	return atoi(roleName.substr(0, 3).c_str()) - 2;
}

float randHurtPercent()
{
	return CCRANDOM_0_1() * 2.0 + 2.0;
}