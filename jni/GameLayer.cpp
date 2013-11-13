/*
 * GameLayer.cpp
 *
 *  Created on: 2013-11-13
 *      Author: Administrator
 */

#include "GameLayer.h"

GameLayer::GameLayer() {
}

GameLayer::~GameLayer() {
}

bool GameLayer::init() {
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());

		// ±³¾°²ã
		CCSprite* bgSprite = CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("gamebg.png"));
		bgSprite->setPosition(getWinCenterPoint());
		this->addChild(bgSprite);
		bRet = true;
	}while(0);
	return bRet;
}

