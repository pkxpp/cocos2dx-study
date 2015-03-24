
require "Cocos2d"

-- cclog
local cclog = function(...)
    print(string.format(...))
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
    
    cc.FileUtils:getInstance():addSearchPath("src")
    cc.FileUtils:getInstance():addSearchPath("res")
    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(480, 320, 0)
    
	--�Ҳ������µ����䷽��
    local pEGLView = cc.Director:getInstance():getOpenGLView()
    local frameSize = pEGLView:getFrameSize()
    --����ĳߴ�д����ͼƬ�Ĵ�С
    local winSize = {width=1280,height=720}
 
    local widthRate = frameSize.width/winSize.width
    local heightRate = frameSize.height/winSize.height
 
    if widthRate > heightRate then
        pEGLView:setDesignResolutionSize(winSize.width,
            winSize.height*heightRate/widthRate, 1)
    else
        pEGLView:setDesignResolutionSize(winSize.width*widthRate/heightRate, winSize.height,
            1)
    end
	
    --create scene 
    -- local scene = require("GameScene")
    -- local gameScene = scene.create()
    -- gameScene:playBgMusic()
	
	--ʹ��ģ��FlashScene
    --local scene = require("FlashScene")
    --ʹ��ģ���еĽӿں���create������һ������
    --local gameScene = scene.create()
    
    --MainScene
    local scene = require("MainScene")
    local gameScene = scene.create()

    if cc.Director:getInstance():getRunningScene() then
        cc.Director:getInstance():replaceScene(gameScene)
    else
        cc.Director:getInstance():runWithScene(gameScene)
    end

end


local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    error(msg)
end
