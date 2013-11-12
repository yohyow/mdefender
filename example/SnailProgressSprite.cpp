#include "SnailProgressSprite.h"
USING_NS_CC;
SnailProgressSprite::SnailProgressSprite(){
	this->setContentSize(CCSize(248,41));
}
SnailProgressSprite::~SnailProgressSprite(){

}
//;// ��һ������ �Ƚ�������ͼƬ��ʵ���ǽ���������Ķ��� �ڶ������� ����������ͼƬ  ���������� ��ţ ����˵�ǻ����ͼƬ
SnailProgressSprite* SnailProgressSprite::createWithPic(const char* progressPic,const char* progressBgPic, const char* snailPic){
	SnailProgressSprite* sprite=new SnailProgressSprite();
	if (sprite&&sprite->setUpdateView(progressPic,progressBgPic,snailPic)){
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool SnailProgressSprite::setUpdateView(const char* progressPic,const char* progressBgPic, const char* snailPic){
	bool isRet=false;
	do 
	{
		CCSprite *s2=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(progressBgPic));//pa2.png�ǽϰ���ͼƬ 
		CC_BREAK_IF(!s2);
		s2->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));  
		addChild(s2,0);
		CCSprite *s=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(progressPic));//pa1.png�ǽ�����ͼƬ
		CC_BREAK_IF(!s);
		CCProgressTimer* ptss=CCProgressTimer::create(s);
		CC_BREAK_IF(!ptss);
		ptss->setPercentage(0);
		ptss->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));  
		//���м䵽��ĳ���  
		ptss->setType(kCCProgressTimerTypeBar);// ���óɺ����
		//���Կ����ǰ�������ʾЧ���Ľ���������
		ptss->setMidpoint(ccp(1,0)); 
		//  �����趨����������ǰ���ķ���������һ��Ǵ�������
		ptss->setBarChangeRate(ccp(1,0));
		this->addChild(ptss,1,2); 

		CCSprite *snail=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(snailPic));
		CC_BREAK_IF(!snail);
		snail->setAnchorPoint(ccp(0,0.5));
		snail->setPosition(ccp(this->getContentSize().width,this->getContentSize().height/2));
		this->addChild(snail,2,3);

	 isRet=true;
	} while (0);
	return isRet;
}
void SnailProgressSprite::setSnailProgress(float jindu){

}
void SnailProgressSprite::runSnailProgress(){
	CCProgressTimer* ptss =(CCProgressTimer*)this->getChildByTag(2);
	CCSprite* snail =(CCSprite*)this->getChildByTag(3);
	CCProgressFromTo* to=CCProgressFromTo::create(this->getRunTime(),0,100);
	ptss->runAction(to);
	CCMoveTo* mo=CCMoveTo::create(this->getRunTime(),ccp(-10,this->getContentSize().height/2));
	snail->runAction(mo);
}
void SnailProgressSprite::initialization(){
	CCProgressTimer* ptss =(CCProgressTimer*)this->getChildByTag(2);
	ptss->stopAllActions();
	ptss->setPercentage(0);
	CCSprite* snail =(CCSprite*)this->getChildByTag(3);
	snail->stopAllActions();
	snail->setPosition(ccp(this->getContentSize().width,this->getContentSize().height/2));
}