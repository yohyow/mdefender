/*
 * AboutLayer.cpp
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#include "AboutLayer.h"
#include "WelcomeLayer.h"

AboutLayer::AboutLayer() {
}

AboutLayer::~AboutLayer() {
}

bool AboutLayer::init() {
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCTexture2D* textureBg = CCTextureCache::sharedTextureCache()->textureForKey("gmbg/coder.png");
		CCSprite* bg = CCSprite::createWithTexture(textureBg);
		bg->setPosition(getWinCenterPoint());
		this->addChild(bg);

		CCTexture2D* normal = CCTextureCache::sharedTextureCache()->textureForKey("gmme/return_up.png");
		CCTexture2D* selector = CCTextureCache::sharedTextureCache()->textureForKey("gmme/return_down.png");
		CCMenuItemSprite* backItem = CCMenuItemSprite::create(CCSprite::createWithTexture(normal), CCSprite::createWithTexture(selector), this, menu_selector(AboutLayer::menuCallBack));
		CCSize winSize = getWinSize();
		backItem->setAnchorPoint(ccp(0.5,0.5));
		backItem->setPosition(ccp(winSize.width - backItem->getContentSize().width / 2 - 15, backItem->getContentSize().height / 2 + 15));

		CCMenu* menu = CCMenu::create(backItem, NULL);
		menu->setPosition(CCPointZero);
		this->addChild(menu, 1);
		bRet = true;
	}while(0);
	return bRet;
}

void AboutLayer::menuCallBack(CCObject* pObj) {
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::create(1.0f, WelcomeLayer::createScene(WelcomeLayer::create())));
}



