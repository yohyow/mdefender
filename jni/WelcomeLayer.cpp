/*
 * WelcomeLayer.cpp
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#include "WelcomeLayer.h"
#include "SimpleAudioEngine.h"
#include "AboutLayer.h"
#include "GameLayer.h"

USING_NS_CC;
bool WelcomeLayer::init(){
	bool isRet=false;
	do
	{
	CC_BREAK_IF(!MBaseLayer::init());
	CC_BREAK_IF(!setUpdateView());
	isRet=true;
	} while (0);
	return isRet;
}
void WelcomeLayer::onEnter(){
	MBaseLayer::onEnter();
	if(!(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())){
		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",true)){
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/dt.mp3",true);
			// 把 音乐状态设置为播放状态
			CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",true);
		}
	}
}

bool WelcomeLayer::setUpdateView(){
	bool isRet=false;
	do
	{
        // 从缓存中 取出 背景图片
		CCTexture2D* texturebg=  CCTextureCache::sharedTextureCache()->textureForKey("gmbg/welcomebg.png");
		CCSprite* pSpriteBg=CCSprite::createWithTexture(texturebg);
		CC_BREAK_IF(!pSpriteBg);
		pSpriteBg->setPosition(getWinCenterPoint());
		this->addChild(pSpriteBg,1);

		// 添加声音菜单按钮
		CCTexture2D* textureon = CCTextureCache::sharedTextureCache()->textureForKey("gmme/button_sound_on.png");
		CCTexture2D* textureoff = CCTextureCache::sharedTextureCache()->textureForKey("gmme/button_sound_off.png");
		CCMenuItemSprite* pitemVon=CCMenuItemSprite::create(CCSprite::createWithTexture(textureon),CCSprite::createWithTexture(textureon));
		CC_BREAK_IF(!pitemVon);
		CCMenuItemSprite* pitemVoff=CCMenuItemSprite::create(CCSprite::createWithTexture(textureoff),CCSprite::createWithTexture(textureoff));
		CC_BREAK_IF(!pitemVoff);
		CCMenuItemToggle* pVedioTo=NULL;
		// 当现在 音乐是 播放的时候界面上显示的按钮应该是 暂停音乐按钮 反之 则显示播放按钮
		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",false)){
			pVedioTo=CCMenuItemToggle::createWithTarget(this,menu_selector(WelcomeLayer::vedioOnAndOffCallBack),pitemVoff,pitemVon,NULL);
		}else {
			pVedioTo=CCMenuItemToggle::createWithTarget(this,menu_selector(WelcomeLayer::vedioOnAndOffCallBack),pitemVon,pitemVoff,NULL);
		}

		CC_BREAK_IF(!pVedioTo);
		// 注意 里面的 0.15 和0.55 都是 通过PS 定位 看看这个图片放在那里计算出来的
		pVedioTo->setPosition(converToSpritRel(getWinSize().width*0.15f,getWinSize().height*0.55f));

		// 创建开始菜单
		CCTexture2D* texturestar_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/star_up.png");
		CCTexture2D* texturestar_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/star_down.png");
		CCMenuItemSprite* pStar=CCMenuItemSprite::create(CCSprite::createWithTexture(texturestar_up),CCSprite::createWithTexture(texturestar_down),this,menu_selector(WelcomeLayer::menuStarGame));
		CC_BREAK_IF(!pStar);
		pStar->setPosition(ccp(getWinSize().width*0.83f,getWinSize().height*0.75f));

		// 创建升级系统菜单
		CCTexture2D* textureup_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/upup.png");
		CCTexture2D* textureup_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/updwon.png");
		CCMenuItemSprite* pup=CCMenuItemSprite::create(CCSprite::createWithTexture(textureup_up),CCSprite::createWithTexture(textureup_down),this,menu_selector(WelcomeLayer::menuUpGameCallback));
		CC_BREAK_IF(!pup);
		pup->setPosition(ccp(660,275));

		// 创建退出游戏菜单
		CCTexture2D* textureout_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/outup.png");
		CCTexture2D* textureout_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/outdown.png");
		CCMenuItemSprite* pout=CCMenuItemSprite::create(CCSprite::createWithTexture(textureout_up),CCSprite::createWithTexture(textureout_down),this,menu_selector(WelcomeLayer::menuGameOverCallback));
		CC_BREAK_IF(!pout);
		pout->setPosition(ccp(640,190));

		// 创建开发者 菜单按钮
		CCTexture2D* texturecoder_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/coder_up.png");
		CCTexture2D* texturecoder_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/coder_down.png");
		CCMenuItemSprite* pcoder=CCMenuItemSprite::create(CCSprite::createWithTexture(texturecoder_up),CCSprite::createWithTexture(texturecoder_down),this,menu_selector(WelcomeLayer::menuCoderCallback));
		CC_BREAK_IF(!pcoder);
		pcoder->setPosition(converToSpritRel(getWinSize().width*0.78f,getWinSize().height*0.21f));

		CCMenu* pMenu=CCMenu::create(pVedioTo,pStar,pup,pout,pcoder,NULL);
		CC_BREAK_IF(!pMenu);
		pMenu->setPosition(CCPointZero);
		this->addChild(pMenu,2);

	    isRet=true;
	} while (0);
	return isRet;
}

// 升级系统回调方法
void WelcomeLayer::menuUpGameCallback(cocos2d::CCObject* pSend){
//	CCScene* se=UpgradeSystemLayer::scene();
//	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
}
//退出游戏回调方法
void WelcomeLayer::menuGameOverCallback(cocos2d::CCObject* pSend){
	CCDirector::sharedDirector()->end();
}



void WelcomeLayer::vedioOnAndOffCallBack(CCObject* pSend){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",false)){
		if (CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
			CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		}
		CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",false);
	}else {
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		if (!(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())) {
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/dt.mp3",true);
		}
		CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",true);
	}

}
void WelcomeLayer::menuCoderCallback(CCObject* pSend){
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1.0f, AboutLayer::createScene(AboutLayer::create())));
}
void WelcomeLayer::menuStarGame(CCObject* pSend){
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,GameLayer::createScene(GameLayer::create())));
}

