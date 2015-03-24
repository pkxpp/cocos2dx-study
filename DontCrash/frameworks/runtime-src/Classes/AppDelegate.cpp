#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Runtime.h"
#include "ConfigParser.h"
#include "lua_cycle_auto.hpp"

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    
#if (COCOS2D_DEBUG>0)
    initRuntime();
#endif
    
    if (!ConfigParser::getInstance()->isInit()) {
            ConfigParser::getInstance()->readConfig();
        }

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();    
    if(!glview) {
        Size viewSize = ConfigParser::getInstance()->getInitViewSize();
        string title = ConfigParser::getInstance()->getInitViewName();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
        extern void createSimulator(const char* viewName, float width, float height,bool isLandscape = true, float frameZoomFactor = 1.0f);
        bool isLanscape = ConfigParser::getInstance()->isLanscape();
        createSimulator(title.c_str(),viewSize.width,viewSize.height,isLanscape);
#else
        glview = GLView::createWithRect(title.c_str(), Rect(0,0,viewSize.width,viewSize.height));
        director->setOpenGLView(glview);
#endif
    }

   
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
   
    auto engine = LuaEngine::getInstance();

	//register_all_cycle(engine->getLuaStack()->getLuaState());

    ScriptEngineManager::getInstance()->setScriptEngine(engine);

    LuaStack* stack = engine->getLuaStack();
    stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));
    
    //register custom function
    //LuaStack* stack = engine->getLuaStack();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ||CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    //register_all_cycle(stack->getLuaState());

    /*auto L = stack->getLuaState();
    if (L)
    {
        lua_getglobal(L, "_G");
        register_all_cycle(L);
		register_all_custom(L);
        lua_settop(L, 0);
    }*/
#endif
	//2015/03/19: cocos ide can't work
	auto L = stack->getLuaState();
    if (L)
    {
        lua_getglobal(L, "_G");
        register_all_cycle(L);
        lua_settop(L, 0);
    }
	//register_all_cycle(stack->getLuaState());
	//engine->executeScriptFile("DeprecatedEnum.lua");
    //engine->executeScriptFile("DeprecatedClass.lua");
    //engine->executeScriptFile("Deprecated.lua");

#if (COCOS2D_DEBUG>0)
    if (startRuntime())
        return true;
#endif

    engine->executeScriptFile(ConfigParser::getInstance()->getEntryFile().c_str());
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

