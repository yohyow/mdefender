#include "GameSuccessfullyLayer.h"
#include "DefenderGameLayer.h"
USING_NS_CC;
CCScene* GameSuccessfullyLayer::scene(){
	CCScene* scene=CCScene::create();
	GameSuccessfullyLayer* layer=GameSuccessfullyLayer::create();
	scene->addChild(layer);
	return scene;
}
bool GameSuccessfullyLayer::init(){
	bool isRet=false;
	do 
	{
		CC_BREAK_IF(!BaseLayer::init());
		CC_BREAK_IF(!setUpdateView());
		isRet=true;
	} while (0);
	return isRet;
}
bool GameSuccessfullyLayer::setUpdateView(){
	bool isRet=false;
	do 
	{
		char temp[12];
		// ��ӱ���ͼƬ
		CCSprite* laybg=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("gmbg/stats_bg.png"));
		CC_BREAK_IF(!laybg);
		laybg->setPosition(getWinCenter());
		this->addChild(laybg);
		// ��ӵ�ǰ�ؿ�
		CCLabelAtlas* stage= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!stage);
		int lve=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
	    sprintf(temp,"%d",lve);
		stage->setString(temp);
		stage->setAnchorPoint(ccp(0,0));
		stage->setPosition(ccp(415,370));
		this->addChild(stage,1);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("lve",lve+1);

		// ��ӻ�ɱ������Ŀ
		CCLabelAtlas* killcount= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!killcount);
		int killtemp=CCUserDefault::sharedUserDefault()->getIntegerForKey("killtemp",0);
		sprintf(temp,"%d",killtemp);
		killcount->setString(temp);
		killcount->setAnchorPoint(ccp(0,0));
		killcount->setPosition(ccp(415,320));
		this->addChild(killcount,1);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("killtemp",0);


		// ��ʾʣ������ֵ
		CCLabelAtlas* lifecount= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!lifecount);
		int lifetemp=CCUserDefault::sharedUserDefault()->getIntegerForKey("lifetemp",0);
		sprintf(temp,"%d",lifetemp);
		lifecount->setString(temp);
		lifecount->setAnchorPoint(ccp(0,0));
		lifecount->setPosition(ccp(415,280));
		this->addChild(lifecount,1);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("lifetemp",0);



		// ��ʾ��ɱ���� �涨ɱ��һ���־���1�����
		CCLabelAtlas* killbound= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!killbound);	
		sprintf(temp,"%d",killtemp);
		killbound->setString(temp);
		killbound->setAnchorPoint(ccp(0,0));
		killbound->setPosition(ccp(440,218));
		this->addChild(killbound,1);

		// ��ʾ����ֵ���� һ������ֵ����һ�����
		CCLabelAtlas* lifebound= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!lifebound);	
		sprintf(temp,"%d",lifetemp);
		lifebound->setString(temp);
		lifebound->setAnchorPoint(ccp(0,0));
		lifebound->setPosition(ccp(440,170));
		this->addChild(lifebound,1);


		// ��ʾ�ؿ����� һ����һ�ؽ���5�����
		CCLabelAtlas* goldbound= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!goldbound);	
		sprintf(temp,"%d",lve*5);
		goldbound->setString(temp);
		goldbound->setAnchorPoint(ccp(0,0));
		goldbound->setPosition(ccp(440,132));
		this->addChild(goldbound,1);


		// ��ʾ��ʾ�ܽ������
		CCLabelAtlas* total= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!total);	
		int totalnum=lve*5+lifetemp+killtemp;
		sprintf(temp,"%d",totalnum);
		total->setString(temp);
		total->setAnchorPoint(ccp(0,0));
		total->setPosition(ccp(415,80));
		this->addChild(total,1);

		// �����ܽ��
		int goldnum=CCUserDefault::sharedUserDefault()->getIntegerForKey("goldNum",0);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("goldNum",totalnum+goldnum);

		// ������ǰ��ʾ��Ϣ

		CCSprite* tip=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/statstip.png"));
		CC_BREAK_IF(!tip);
		tip->setPosition(ccp(this->getContentSize().width/2,30));
		this->addChild(tip,1);
		tip->runAction(CCRepeatForever::create(CCBlink::create(1,1)));
		

	isRet=true;
	} while (0);
	return isRet;
}
GameSuccessfullyLayer::GameSuccessfullyLayer(){

}
GameSuccessfullyLayer::~GameSuccessfullyLayer(){

}

void GameSuccessfullyLayer::onEnter(){
	BaseLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(  
		this,//���Ǹ�����ʵ�ִ����ص�����  
		-128, //���ȼ�  
		true);//����ʱ���Ƿ񱻸�Ŀ��ػ�  
}
 bool GameSuccessfullyLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
	 CCScene* se=DefenderGameLayer::scene();
	 //CCScene* se=GameSuccessfullyLayer::scene();
	 CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
	 return true;
 }

 void GameSuccessfullyLayer::onExit(){
	 BaseLayer::onExit();
	 CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
 }