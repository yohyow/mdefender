/*
 * MBaseLayer.cpp
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#include "MBaseLayer.h"

MBaseLayer::MBaseLayer() {
}

MBaseLayer::~MBaseLayer() {
}

CCScene* MBaseLayer::createScene(CCLayer* pCCLayer) {
	CCScene* scene = CCScene::create();
	scene->addChild(pCCLayer);
	return scene;
}

bool MBaseLayer::init() {
	bool bRet = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		bRet = true;
	}while(0);
	return bRet;
}

CCSize MBaseLayer::getWinSize() {
	return CCDirector::sharedDirector()->getVisibleSize();
}

CCPoint MBaseLayer::getWinSizeWithOrign() {
	return CCDirector::sharedDirector()->getVisibleOrigin();
}
CCPoint MBaseLayer::getWinCenterPoint() {
	CCSize size = getWinSize();
	CCPoint orign = getWinSizeWithOrign();
	return ccp(size.width / 2 + orign.x, size.height / 2 + orign.y);
}
CCPoint MBaseLayer::converToSpritRel(float x, float y){
	CCPoint orign = getWinSizeWithOrign();
	return ccp(orign.x + x, orign.y + y);
}

