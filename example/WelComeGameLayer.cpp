#include "WelComeGameLayer.h"
#include "AboutCoderLayer.h"
#include "DefenderGameLayer.h"
#include "SimpleAudioEngine.h"
#include "UpgradeSystemLayer.h"
USING_NS_CC;
bool WelComeGameLayer::init(){
	bool isRet=false;
	do 
	{
	CC_BREAK_IF(!BaseLayer::init());
	CC_BREAK_IF(!setUpdateView());
	isRet=true;
	} while (0);
	return isRet;
}
void WelComeGameLayer::onEnter(){
	BaseLayer::onEnter();	
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()){
	}else {
		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",true)){			
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/dt.mp3",true);				
			// �� ����״̬����Ϊ����״̬
			CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",true);
		}
	}	
}
CCScene* WelComeGameLayer::scene(){
	CCScene* scene=CCScene::create();
	WelComeGameLayer* layer=WelComeGameLayer::create();
	scene->addChild(layer);
	return scene;
}
bool WelComeGameLayer::setUpdateView(){
	bool isRet=false;
	do 
	{
        // �ӻ����� ȡ�� ����ͼƬ
		CCTexture2D* texturebg=  CCTextureCache::sharedTextureCache()->textureForKey("gmbg/welcomebg.png");
		CCSprite* pSpriteBg=CCSprite::createWithTexture(texturebg);
		CC_BREAK_IF(!pSpriteBg);
		pSpriteBg->setPosition(getWinCenter());
		this->addChild(pSpriteBg,1);

		// ��������˵���ť
		CCTexture2D* textureon = CCTextureCache::sharedTextureCache()->textureForKey("gmme/button_sound_on.png");
		CCTexture2D* textureoff = CCTextureCache::sharedTextureCache()->textureForKey("gmme/button_sound_off.png");
		CCMenuItemSprite* pitemVon=CCMenuItemSprite::create(CCSprite::createWithTexture(textureon),CCSprite::createWithTexture(textureon));
		CC_BREAK_IF(!pitemVon);
		CCMenuItemSprite* pitemVoff=CCMenuItemSprite::create(CCSprite::createWithTexture(textureoff),CCSprite::createWithTexture(textureoff));
		CC_BREAK_IF(!pitemVoff);
		CCMenuItemToggle* pVedioTo=NULL;
		// ������ ������ ���ŵ�ʱ���������ʾ�İ�ťӦ���� ��ͣ���ְ�ť ��֮ ����ʾ���Ű�ť
		if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",false)){
			pVedioTo=CCMenuItemToggle::createWithTarget(this,menu_selector(WelComeGameLayer::vedioOnAndOffCallBack),pitemVoff,pitemVon,NULL);
		}else {
			pVedioTo=CCMenuItemToggle::createWithTarget(this,menu_selector(WelComeGameLayer::vedioOnAndOffCallBack),pitemVon,pitemVoff,NULL);
		}
		
		
		CC_BREAK_IF(!pVedioTo);
		// ע�� ����� 0.15 ��0.55 ���� ͨ��PS ��λ �������ͼƬ����������������
		pVedioTo->setPosition(converSpritRel(getWinSize().width*0.15f,getWinSize().height*0.55f));		



		// ������ʼ�˵�
		CCTexture2D* texturestar_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/star_up.png");
		CCTexture2D* texturestar_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/star_down.png");
		CCMenuItemSprite* pStar=CCMenuItemSprite::create(CCSprite::createWithTexture(texturestar_up),CCSprite::createWithTexture(texturestar_down),this,menu_selector(WelComeGameLayer::menuStarGame));
		CC_BREAK_IF(!pStar);
		pStar->setPosition(ccp(getWinSize().width*0.83f,getWinSize().height*0.75f));

		// ��������ϵͳ�˵�
		CCTexture2D* textureup_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/upup.png");
		CCTexture2D* textureup_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/updwon.png");
		CCMenuItemSprite* pup=CCMenuItemSprite::create(CCSprite::createWithTexture(textureup_up),CCSprite::createWithTexture(textureup_down),this,menu_selector(WelComeGameLayer::menuUpGameCallback));
		CC_BREAK_IF(!pup);
		pup->setPosition(ccp(660,275));


		// �����˳���Ϸ�˵�
		CCTexture2D* textureout_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/outup.png");
		CCTexture2D* textureout_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/outdown.png");
		CCMenuItemSprite* pout=CCMenuItemSprite::create(CCSprite::createWithTexture(textureout_up),CCSprite::createWithTexture(textureout_down),this,menu_selector(WelComeGameLayer::menuGameOverCallback));
		CC_BREAK_IF(!pout);
		pout->setPosition(ccp(640,190));



		// ���������� �˵���ť
		CCTexture2D* texturecoder_up = CCTextureCache::sharedTextureCache()->textureForKey("gmme/coder_up.png");
		CCTexture2D* texturecoder_down = CCTextureCache::sharedTextureCache()->textureForKey("gmme/coder_down.png");
		CCMenuItemSprite* pcoder=CCMenuItemSprite::create(CCSprite::createWithTexture(texturecoder_up),CCSprite::createWithTexture(texturecoder_down),this,menu_selector(WelComeGameLayer::menuCoderCallback));
		CC_BREAK_IF(!pcoder);
		pcoder->setPosition(converSpritRel(getWinSize().width*0.78f,getWinSize().height*0.21f));






		CCMenu* pMenu=CCMenu::create(pVedioTo,pStar,pup,pout,pcoder,NULL);
		CC_BREAK_IF(!pMenu);
		pMenu->setPosition(CCPointZero);
		this->addChild(pMenu,2);



	    isRet=true;
	} while (0);
	return isRet;
}

// ����ϵͳ�ص�����
void WelComeGameLayer::menuUpGameCallback(cocos2d::CCObject* pSend){
	CCScene* se=UpgradeSystemLayer::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
}
//�˳���Ϸ�ص�����
void WelComeGameLayer::menuGameOverCallback(cocos2d::CCObject* pSend){
	CCDirector::sharedDirector()->end();
}



void WelComeGameLayer::vedioOnAndOffCallBack(CCObject* pSend){
	if(CCUserDefault::sharedUserDefault()->getBoolForKey("isplay",false)){
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		CCLOG("music is stop");
		CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",false);
	}else {
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();		
		CCUserDefault::sharedUserDefault()->setBoolForKey("isplay",true);
		CCLOG("music is play");
	}

}
void WelComeGameLayer::menuCoderCallback(CCObject* pSend){
	CCScene* se=AboutCoderLayer::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
}
void WelComeGameLayer::menuStarGame(CCObject* pSend){
	CCScene* se=DefenderGameLayer::scene();
	//CCScene* se=GameSuccessfullyLayer::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
}