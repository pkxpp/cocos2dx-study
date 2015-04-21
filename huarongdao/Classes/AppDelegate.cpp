#include "AppDelegate.h"

#include <vector>
#include <string>
//#include "HelloWorldScene.h"
#include "data/Role.h"
#include "data/Level.h"
#include "GameLayer.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {
	CCFileUtils::getInstance()->addSearchPath("../Resources");
	Level::initStatic() ;
	Role::initStatic() ;
}

AppDelegate::~AppDelegate() 
{
	Role::finalizeStatic();
	Level::finalizeStatic();
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("HuaRong");
        director->setOpenGLView(glview);
    }

    director->setOpenGLView(glview);

    // Set the design resolution
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    // a bug in DirectX 11 level9-x on the device prevents ResolutionPolicy::NO_BORDER from working correctly
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::SHOW_ALL);
#else
	glview->setDesignResolutionSize(320, 480, ResolutionPolicy::SHOW_ALL);
#endif

	Size frameSize = glview->getFrameSize();
    vector<string> searchPath;
	//page@2015/01/15 add Resources to searchParth
	CCFileUtils::getInstance()->addSearchPath("../Resources");
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = GameLayer::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
