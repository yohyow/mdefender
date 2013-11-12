#include "MainCityBloodSprite.h"
USING_NS_CC;
MainCityBloodSprite::MainCityBloodSprite(){
	// Ĭ�ϳ�ʼ�� 100 ħ�� 100 ��Ѫ
	this->blood=CCUserDefault::sharedUserDefault()->getIntegerForKey("cityblood",100);
	this->magic=CCUserDefault::sharedUserDefault()->getIntegerForKey("citymg",100);
}
MainCityBloodSprite::~MainCityBloodSprite(){

}
MainCityBloodSprite* MainCityBloodSprite::createWithTexture(CCTexture2D *pTexture){
	MainCityBloodSprite* sprite=new MainCityBloodSprite();
	if (sprite&&pTexture&&sprite->initWithTexture(pTexture)&&sprite->setUpdateView()){
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool MainCityBloodSprite::setUpdateView(){
	bool isRet=false;
	do 
	{

		// �����Ѫ������
		CCSprite* bloodsp=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/zcblood.png"));
		CC_BREAK_IF(!bloodsp);
		this->bloodBwlid=CCProgressTimer::create(bloodsp);
		CC_BREAK_IF(!bloodBwlid);
		bloodBwlid->setType(kCCProgressTimerTypeBar);// ���óɺ����
		//���Կ����ǰ�������ʾЧ���Ľ���������
		bloodBwlid->setMidpoint(ccp(0,0)); 
		//  �����趨����������ǰ���ķ���������һ��Ǵ�������
		bloodBwlid->setBarChangeRate(ccp(1,0));
		bloodBwlid->setPosition(ccp(67,33));
		bloodBwlid->setPercentage(100);
		bloodBwlid->setAnchorPoint(ccp(0,0.5));
		this->addChild(bloodBwlid,1);

		// ���ħ��������
		CCSprite* magicblood=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/magic.png"));
		CC_BREAK_IF(!magicblood);
		this->magicBwlid=CCProgressTimer::create(magicblood);
		CC_BREAK_IF(!magicBwlid);
		magicBwlid->setType(kCCProgressTimerTypeBar);// ���óɺ����
		//���Կ����ǰ�������ʾЧ���Ľ���������
		magicBwlid->setMidpoint(ccp(0,0)); 
		//  �����趨����������ǰ���ķ���������һ��Ǵ�������
		magicBwlid->setBarChangeRate(ccp(1,0));
		magicBwlid->setAnchorPoint(ccp(0,0.5));
		magicBwlid->setPosition(ccp(66,19));
		magicBwlid->setPercentage(100);
		this->addChild(magicBwlid,1);
		isRet=true;
	} while (0);
	return isRet;
}

// ���ܵ��������˺� 
float MainCityBloodSprite::injuries(float hurt){
	float magicd= bloodBwlid->getPercentage()*(this->blood/100);// �õ���ǰʣ�����Ѫֵ
	float temp=magicd-hurt;
	if(temp>0){
		bloodBwlid->setPercentage(temp/(this->blood/100));
		return temp;
	}else {
		bloodBwlid->setPercentage(0);
		return 0;
	}
}
// ����ʣ��ħ��ֵ 
float MainCityBloodSprite::mana(float mf){
	float magicd= magicBwlid->getPercentage()*(this->magic/100);// �õ���ǰʣ���ħ��ֵ
	if (magicd>0){
		if(magicd-mf>=0){
			float temp=magicd-mf;
			magicBwlid->setPercentage(temp/(this->magic/100));
			return temp;
		}else {
			magicBwlid->setPercentage(0);
			return 0;
		}
	}else {
		return 0;
	}	
}

void MainCityBloodSprite::restoreBlood(){
	magicBwlid->setPercentage(100);
	bloodBwlid->setPercentage(100);
}


void MainCityBloodSprite::setBlood(float blood){
	this->blood=blood;
}
float MainCityBloodSprite::getBlood(){
	return this->blood;
}
void MainCityBloodSprite::setMagic(float magic){
	this->magic=magic;
}
float MainCityBloodSprite::getMagic(){
	return magic;
}