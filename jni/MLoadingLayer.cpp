/*
 * MMLoadingLayer.cpp
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#include "MLoadingLayer.h"
#include "SimpleAudioEngine.h"
#include "WelcomeLayer.h"

MLoadingLayer::MLoadingLayer() {
	this->loadingNum = 0;
	this->totalNum = 51;
}

MLoadingLayer::~MLoadingLayer() {
}

bool MLoadingLayer::init() {
	bool bRet = false;
	do{
		CC_BREAK_IF(!MBaseLayer::init());
		this->showProgressBar();
		CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/dt.mp3");
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/welcomebg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 背景图片
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/coder.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 添加关于开发者背景图片

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_on.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 声音开始
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_off.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 声音关闭

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 开发者按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 开发者按钮

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 返回菜单按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 返回菜单按钮


		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 开始菜单按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面


		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gamebg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 欢迎界面 背景图片

		CCTextureCache::sharedTextureCache()->addImageAsync("game/weapon.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 弓弩武器
		CCTextureCache::sharedTextureCache()->addImageAsync("game/wq0.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  弓箭子弹


		CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 血条背景
		CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood_frame.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  血条


		CCTextureCache::sharedTextureCache()->addImageAsync("monster/dutu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 赌徒怪物

		CCTextureCache::sharedTextureCache()->addImageAsync("game/zcblood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 主城血条
		CCTextureCache::sharedTextureCache()->addImageAsync("game/magic.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  主城魔法条
		CCTextureCache::sharedTextureCache()->addImageAsync("game/panelblood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  主城血条和魔法条的背景



		CCTextureCache::sharedTextureCache()->addImageAsync("game/jnl.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 魔法阵背景图片
		CCTextureCache::sharedTextureCache()->addImageAsync("game/jnzt.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 魔法阵CD 亮的图片


		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/pause_button.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏暂停按钮

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏家按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏继续按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_retry_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏重新开始按钮
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_rety_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏暂停按钮


		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/pause_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图是游戏暂停按钮


		CCTextureCache::sharedTextureCache()->addImageAsync("game/MagicMatrix.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图魔法阵的图片

		CCTextureCache::sharedTextureCache()->addImageAsync("specia/ligtht.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图闪电特效图片
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/diyu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图地狱石块特效图片
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/long.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图二龙戏珠特效图片
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/thumbnails.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图特效缩略图片



		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniubj.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图地蜗牛进度条背景图片
		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniujd.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 此图蜗牛进度条图片
		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图蜗牛图片

		CCTextureCache::sharedTextureCache()->addImageAsync("game/stage_title.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图等级的背景图


		CCTextureCache::sharedTextureCache()->addImageAsync("game/gameover.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图游戏结束标题图
		CCTextureCache::sharedTextureCache()->addImageAsync("game/gameovertips.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图游戏结束提示图
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gameoverbg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图游戏结背景图

		CCTextureCache::sharedTextureCache()->addImageAsync("game/coin.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  此图金币图标

		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/stats_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  胜利界面背景图片

		CCTextureCache::sharedTextureCache()->addImageAsync("game/statstip.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  胜利界面提示按钮

		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/research_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  能力提升界面的背景图片
		CCTextureCache::sharedTextureCache()->addImageAsync("game/lvSyspng.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  能力提升界面的按钮图片
		CCTextureCache::sharedTextureCache()->addImageAsync("game/lvinfo.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  能力提升界面的说明文字图片



		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outdown.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  游戏结束按钮图片
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outup.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/updwon.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // 升级系统图片
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/upup.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		bRet = true;
	}while(0);
	return bRet;
}

void MLoadingLayer::loadCallBack(CCObject* pObj) {
	this->loadingNum ++;
	CCProgressTimer* progress = (CCProgressTimer*)this->getChildByTag(1);
	float percent = progress->getPercentage();
	if (this->loadingNum >= this->totalNum) {
		progress->setPercentage(100);
		this->goWelcomeLayer();
	}else {
		progress->setPercentage((100 / totalNum) + percent);
	}
}

void MLoadingLayer::showProgressBar() {
	CCSprite* loadBg = CCSprite::create("gmbg/lodingbg.png");
	CCSize winSize = getWinSize();
	loadBg->setPosition(ccp(winSize.width / 2, winSize.height / 5));
	this->addChild(loadBg, 1);

	CCSprite* loading = CCSprite::create("gmbg/longding.png");
	CCProgressTimer* progress = CCProgressTimer::create(loading);
	progress->setType(kCCProgressTimerTypeBar);//横向
	progress->setBarChangeRate(ccp(1, 0));//左向右
	progress->setMidpoint(ccp(0, 0));//矩形
	progress->setPosition(ccp(winSize.width / 2, winSize.height / 5 - 5));
	progress->setPercentage(0);
	this->addChild(progress, 2, 1);
}

void MLoadingLayer::goWelcomeLayer() {
	CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInB::create(1.0f, WelcomeLayer::createScene(WelcomeLayer::create())));
}

