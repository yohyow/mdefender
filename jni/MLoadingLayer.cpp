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
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/welcomebg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� ����ͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/coder.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӹ��ڿ����߱���ͼƬ

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_on.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� ������ʼ
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_off.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� �����ر�

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� �����߰�ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� �����߰�ť

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ���ز˵���ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ���ز˵���ť


		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� ��ʼ�˵���ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ����


		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gamebg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ӭ���� ����ͼƬ

		CCTextureCache::sharedTextureCache()->addImageAsync("game/weapon.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��������
		CCTextureCache::sharedTextureCache()->addImageAsync("game/wq0.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  �����ӵ�


		CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // Ѫ������
		CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood_frame.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  Ѫ��


		CCTextureCache::sharedTextureCache()->addImageAsync("monster/dutu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͽ����

		CCTextureCache::sharedTextureCache()->addImageAsync("game/zcblood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ����Ѫ��
		CCTextureCache::sharedTextureCache()->addImageAsync("game/magic.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ����ħ����
		CCTextureCache::sharedTextureCache()->addImageAsync("game/panelblood.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ����Ѫ����ħ�����ı���



		CCTextureCache::sharedTextureCache()->addImageAsync("game/jnl.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ħ���󱳾�ͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/jnzt.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ħ����CD ����ͼƬ


		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/pause_button.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť

		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ�Ұ�ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ������ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_retry_down.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ���¿�ʼ��ť
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_rety_up.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť


		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/pause_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť


		CCTextureCache::sharedTextureCache()->addImageAsync("game/MagicMatrix.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼħ�����ͼƬ

		CCTextureCache::sharedTextureCache()->addImageAsync("specia/ligtht.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ������ЧͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/diyu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����ʯ����ЧͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/long.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����Ϸ����ЧͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("specia/thumbnails.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ��Ч����ͼƬ



		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniubj.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ����ţ����������ͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniujd.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ��ͼ��ţ������ͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/woniu.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ��ţͼƬ

		CCTextureCache::sharedTextureCache()->addImageAsync("game/stage_title.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ�ȼ��ı���ͼ


		CCTextureCache::sharedTextureCache()->addImageAsync("game/gameover.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ��Ϸ��������ͼ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/gameovertips.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ��Ϸ������ʾͼ
		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gameoverbg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ��Ϸ�ᱳ��ͼ

		CCTextureCache::sharedTextureCache()->addImageAsync("game/coin.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��ͼ���ͼ��

		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/stats_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ʤ�����汳��ͼƬ

		CCTextureCache::sharedTextureCache()->addImageAsync("game/statstip.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ʤ��������ʾ��ť

		CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/research_bg.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ������������ı���ͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/lvSyspng.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ������������İ�ťͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("game/lvinfo.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  �������������˵������ͼƬ



		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outdown.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); //  ��Ϸ������ťͼƬ
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outup.png",this,callfuncO_selector(MLoadingLayer::loadCallBack));
		CCTextureCache::sharedTextureCache()->addImageAsync("gmme/updwon.png",this,callfuncO_selector(MLoadingLayer::loadCallBack)); // ����ϵͳͼƬ
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
	progress->setType(kCCProgressTimerTypeBar);//����
	progress->setBarChangeRate(ccp(1, 0));//������
	progress->setMidpoint(ccp(0, 0));//����
	progress->setPosition(ccp(winSize.width / 2, winSize.height / 5 - 5));
	progress->setPercentage(0);
	this->addChild(progress, 2, 1);
}

void MLoadingLayer::goWelcomeLayer() {
	CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInB::create(1.0f, WelcomeLayer::createScene(WelcomeLayer::create())));
}

