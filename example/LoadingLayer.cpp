#include "LoadingLayer.h"
#include "WelComeGameLayer.h"
USING_NS_CC;
LoadingLayer::LoadingLayer(){
	this->loadingNum=0;
	this->totalNum=51;
}
bool LoadingLayer::init(){
	bool isRet=false;
	do 
	{
	CC_BREAK_IF(!BaseLayer::init());
	CC_BREAK_IF(!this->setUpdateView());
	
	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/welcomebg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� ����ͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/coder.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӹ��ڿ����߱���ͼƬ
  
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_on.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� ������ʼ
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/button_sound_off.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� �����ر�

	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� �����߰�ť
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/coder_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� �����߰�ť

	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ���ز˵���ť
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/return_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ���ز˵���ť


	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� ��ʼ�˵���ť
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/star_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ����  


	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gamebg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ӭ���� ����ͼƬ

    CCTextureCache::sharedTextureCache()->addImageAsync("game/weapon.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��������
	CCTextureCache::sharedTextureCache()->addImageAsync("game/wq0.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  �����ӵ�


	CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // Ѫ������
	CCTextureCache::sharedTextureCache()->addImageAsync("game/monster_blood_frame.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  Ѫ��


	CCTextureCache::sharedTextureCache()->addImageAsync("monster/dutu.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͽ����

	CCTextureCache::sharedTextureCache()->addImageAsync("game/zcblood.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ����Ѫ��
	CCTextureCache::sharedTextureCache()->addImageAsync("game/magic.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ����ħ����
	CCTextureCache::sharedTextureCache()->addImageAsync("game/panelblood.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ����Ѫ����ħ�����ı���



	CCTextureCache::sharedTextureCache()->addImageAsync("game/jnl.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ħ���󱳾�ͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/jnzt.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ħ����CD ����ͼƬ


	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/pause_button.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť

	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ�Ұ�ť
    CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_home_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); 
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ������ť
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_resume_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); 
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_retry_down.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ���¿�ʼ��ť
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/btn_rety_up.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť


	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/pause_bg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ��ͣ��ť


	CCTextureCache::sharedTextureCache()->addImageAsync("game/MagicMatrix.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼħ�����ͼƬ

	CCTextureCache::sharedTextureCache()->addImageAsync("specia/ligtht.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ������ЧͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("specia/diyu.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����ʯ����ЧͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("specia/long.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����Ϸ����ЧͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("specia/thumbnails.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ��Ч����ͼƬ
    

	
	CCTextureCache::sharedTextureCache()->addImageAsync("game/woniubj.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ����ţ����������ͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/woniujd.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ��ͼ��ţ������ͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/woniu.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ��ţͼƬ

	CCTextureCache::sharedTextureCache()->addImageAsync("game/stage_title.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ�ȼ��ı���ͼ


	CCTextureCache::sharedTextureCache()->addImageAsync("game/gameover.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ��Ϸ��������ͼ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/gameovertips.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ��Ϸ������ʾͼ
	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/gameoverbg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ��Ϸ�ᱳ��ͼ

	CCTextureCache::sharedTextureCache()->addImageAsync("game/coin.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��ͼ���ͼ��

	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/stats_bg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ʤ�����汳��ͼƬ

	CCTextureCache::sharedTextureCache()->addImageAsync("game/statstip.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ʤ��������ʾ��ť

	CCTextureCache::sharedTextureCache()->addImageAsync("gmbg/research_bg.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ������������ı���ͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/lvSyspng.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ������������İ�ťͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("game/lvinfo.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  �������������˵������ͼƬ



	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outdown.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); //  ��Ϸ������ťͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/outup.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); 
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/updwon.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); // ����ϵͳͼƬ
	CCTextureCache::sharedTextureCache()->addImageAsync("gmme/upup.png",this,callfuncO_selector(LoadingLayer::loadCallBack)); 

	isRet=true;
	} while (0);
	return isRet;
}
CCScene* LoadingLayer::scene(){
	CCScene* scene=CCScene::create();
	LoadingLayer* layer=LoadingLayer::create();
	scene->addChild(layer);
	return scene;
}
void LoadingLayer::loadCallBack(CCObject* ped){
	loadingNum++;	 
	CCLOG("%d",loadingNum);
    CCProgressTimer* pt=(CCProgressTimer*)this->getChildByTag(1);
	float now=pt->getPercentage();
	pt->setPercentage(100.0/totalNum+now);
	if(loadingNum<totalNum){
		
	}else{
		pt->setPercentage(100);
		// �������ʱ����ת����Ӧ�Ľ���
		CCLOG("loading over");
		
		goWelcomeLayer();
	}
}


void LoadingLayer::goWelcomeLayer(){
	CCScene* se=WelComeGameLayer::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInR::create(1,se));
}

bool LoadingLayer::setUpdateView(){
	bool isRet=false;
	do 
	{
	// ���ý������ı���ͼƬ ���ǰ����ŵ���Ļ�·���1/5��	
    CCSprite* loadbackimg=CCSprite::create("gmbg/lodingbg.png");
	CC_BREAK_IF(!loadbackimg);	
	loadbackimg->setPosition(ccp(getWinSize().width/2+getWinOrigin().x,getWinSize().height/5+getWinOrigin().y));
	this->addChild(loadbackimg,1);
	
	// ��ӽ�����
	CCSprite* loadimg=CCSprite::create("gmbg/longding.png");
	CC_BREAK_IF(!loadimg);	
	CCProgressTimer* pt = CCProgressTimer::create(loadimg);
	pt->setType(kCCProgressTimerTypeBar);// ���óɺ����
	//���Կ����ǰ�������ʾЧ���Ľ���������
	pt->setMidpoint(ccp(0,0)); 
	//  �����趨����������ǰ���ķ���������һ��Ǵ�������
	pt->setBarChangeRate(ccp(1,0));
	//��������ê��
	float tex=getWinSize().width/2+getWinOrigin().x;
	float tey=getWinSize().height/5+getWinOrigin().y-5;
	pt->setPosition(ccp(tex,tey));
	pt->setPercentage(0);
	this->addChild(pt,2,1);

	isRet=true;
	} while (0);
	return isRet;
}