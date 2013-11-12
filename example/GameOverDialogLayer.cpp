#include "GameOverDialogLayer.h"
#include "DefenderGameLayer.h"
using namespace cocos2d;
/*****
http://blog.csdn.net/onerain88/article/details/7608496
�ο�����
*****/
GameOverDialogLayer::GameOverDialogLayer(void)
{
}


GameOverDialogLayer::~GameOverDialogLayer(void)
{
}
bool GameOverDialogLayer::init()
{
	bool bRet = false;

	do {
		CC_BREAK_IF(!BaseLayer::init());

		CC_BREAK_IF(!this->setUpdateView());		

		bRet = true;
	} while (0);

	return bRet;
}


bool GameOverDialogLayer::setUpdateView()
{
	bool isRet=false;
	do 
	{

	   

		CCSprite* pbg= CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("gmbg/gameoverbg.png"));
		CC_BREAK_IF(!pbg);		
		pbg->setAnchorPoint(ccp(0.5,0.5));
		pbg->setPosition(getWinCenter());
		this->addChild(pbg,1);
		pbg->setOpacity(10);

		CCSprite* pgameover= CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/gameover.png"));
		CC_BREAK_IF(!pgameover);		
		pgameover->setPosition(getWinCenter());
		this->addChild(pgameover,2);

		CCSprite* pgameovertips= CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/gameovertips.png"));
		CC_BREAK_IF(!pgameovertips);		
		pgameovertips->setPosition(getWinCenter());
		pgameovertips->setPositionY(pgameovertips->getPositionY()+pgameover->getContentSize().height);
		this->addChild(pgameovertips,3);
		//pgameovertips->runAction(CCRepeatForever::create(CCBlink::create(2,1)));// ִ����˸����
		
		isRet=true;
	} while (0);
	return isRet;

}

void GameOverDialogLayer::onEnter()
{
	BaseLayer::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(  
		this,//���Ǹ�����ʵ�ִ����ص�����  
		-128, //���ȼ�  
		true);//����ʱ���Ƿ񱻸�Ŀ��ػ�  
}

void GameOverDialogLayer::onExit()
{
	BaseLayer::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool GameOverDialogLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){

	CCDirector::sharedDirector()->replaceScene(DefenderGameLayer::scene());
	CCDirector::sharedDirector()->resume();
	this->removeFromParentAndCleanup(true);


	
	return true;
}


