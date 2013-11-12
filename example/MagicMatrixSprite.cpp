#include "MagicMatrixSprite.h"
#include "DefenderGameLayer.h"
#include "MainCityBloodSprite.h"
USING_NS_CC;
MagicMatrixSprite::MagicMatrixSprite(){
	this->hurt=100;    
	this->avail=false; // �Ƿ����
	this->activation=false; // ������
	this->setContentSize(CCSize(80,81));
}

MagicMatrixSprite::~MagicMatrixSprite(){

}
MagicMatrixSprite* MagicMatrixSprite::createWithPic(const char* pMagicPic,const char* pMagicPicBg){
	MagicMatrixSprite* sprite=new MagicMatrixSprite();
	
	if (sprite&&sprite->setUpdateView(pMagicPic,pMagicPicBg)){
		sprite->autorelease();		
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

bool MagicMatrixSprite::setUpdateView(const char* pMagicPic,const char* pMagicPicBg ){
	bool isRet=false;
	do 
	{

		CCSprite *s2=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(pMagicPicBg));//pa2.png�ǽϰ���ͼƬ 
		CC_BREAK_IF(!s2);
		s2->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));  
		addChild(s2,0);
		CCSprite *s=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey(pMagicPic));//pa1.png�ǽ�����ͼƬ
		CC_BREAK_IF(!s);
		ptss=CCProgressTimer::create(s);
		CC_BREAK_IF(!ptss);

		if(!this->getActivation()){
			ptss->setVisible(false);
		}
		ptss->setPercentage(0);

		ptss->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));  
		//תȦ��CDʵ��  
		ptss->setType(cocos2d::CCProgressTimerType(kCCProgressTimerTypeRadial));  
		//���м䵽��ĳ���  
		//pt->setType(cocos2d::CCProgressTimerType(kCCProgressTimerTypeBar));  
		this->addChild(ptss,1); 
		// ���������Ҫ��⵱ǰħ��ֵ �Ƿ���

		// ��ǰ�ؿ�
		CCLabelTTF* stagelable=CCLabelTTF::create("Low\nMnan","Arial",12);
		CC_BREAK_IF(!stagelable);		
		stagelable->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height/2));
		stagelable->setColor(ccc3(255,0,0));
		
		this->addChild(stagelable,1,2);
		stagelable->setVisible(false);

		this->schedule(schedule_selector(MagicMatrixSprite::detectMagic));
		isRet=true;
	} while (0);
	return isRet;

}

void MagicMatrixSprite::detectMagic(float ti){
	// ��⵱ǰ���ǵ�ħ��ֵ�Ƿ��� ��������� �������ǰ�� ħ�����ʹ��
	DefenderGameLayer* layer= (DefenderGameLayer*)this->getParent();
	MainCityBloodSprite* mainc=(MainCityBloodSprite*)layer->getChildByTag(5);
	float mf=mainc->mana(0);// �õ���ǰ����ʣ���ħ��ֵ
	CCLabelTTF* stagelable=(CCLabelTTF*)this->getChildByTag(2);
	if (mf>=this->getMana()){
	stagelable->setVisible(false);	
	float fd= ptss->getPercentage();
	if(fd>=99){
		this->avail=true;
	}
	}else {
   this->avail=false;
	stagelable->setVisible(true);
	}
}


void MagicMatrixSprite::runMagicCDAnimation(){
	if (ptss)
	{
		if (avail==false&&this->activation)
		{
			ptss->stopAllActions();
			CCProgressTo *t=CCProgressTo::create(8,100);  
			CCCallFuncN *onComplete =  CCCallFuncN::create(this, callfuncN_selector(MagicMatrixSprite::runMagicCDAnimationCallBack));  
			CCSequence* pse=CCSequence::create(t,onComplete,NULL);
			ptss->runAction(pse);  
		}

	}


}

//ִ�в��ŵ�ǰ������Ч�Ķ���
void MagicMatrixSprite::runSpecial(DefenderGameLayer* layer,cocos2d::CCPoint point){
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(this->speciaFileName,CCTextureCache::sharedTextureCache()->textureForKey(this->speciaPicName));
	CCArray* sperci=CCArray::create();
	
	for(int i=0;i<this->getSpeciaCount();i++){
	sperci->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s%d.png",this->speciaName,i)->getCString()));
	}
	CCSprite* monst=CCSprite::createWithSpriteFrame((CCSpriteFrame*)sperci->objectAtIndex(0));

	CCAnimation *animation=CCAnimation::createWithSpriteFrames(sperci,0.15f);
	CCAnimate *animate=CCAnimate::create(animation);
	CCCallFuncN *onComplete =  CCCallFuncN::create(this, callfuncN_selector(MagicMatrixSprite::runSpecialCallBack));  
	CCSequence* pse=CCSequence::create(animate,onComplete,NULL);
	monst->setAnchorPoint(this->getAnchorPo());
	monst->setPosition(point);
	layer->addChild(monst,3);
	
	//monst->runAction(CCRepeatForever::create(pse));

	this->avail=false;//��Ϊ������
	this->ptss->setPercentage(0);
	this->runMagicCDAnimation();


	monst->runAction(pse);
}


 void MagicMatrixSprite::initialization(){
	 	ptss->setPercentage(0);
 }

 void MagicMatrixSprite::runSpecialCallBack(cocos2d::CCNode* pSend){
	 CCSprite* monst=(CCSprite*)pSend;
	 DefenderGameLayer* de= (DefenderGameLayer*)monst->getParent();
	 de->removeChild(pSend,true);
	 de->stopSpeciaCollisionMonster();
 }

bool MagicMatrixSprite::getActivation(){
	return this->activation;
}
void MagicMatrixSprite::setActivation(bool activation){
	this->activation=activation;
	this->ptss->setVisible(true);
}

void MagicMatrixSprite::runMagicCDAnimationCallBack(CCNode* pSed){
	// ��⵱ǰ���ǵ�ħ��ֵ�Ƿ��� ��������� �������ǰ�� ħ�����ʹ��
	DefenderGameLayer* layer= (DefenderGameLayer*)this->getParent();
	MainCityBloodSprite* mainc=(MainCityBloodSprite*)layer->getChildByTag(5);
	float mf=mainc->mana(0);// �õ���ǰ����ʣ���ħ��ֵ
	CCLabelTTF* stagelable=(CCLabelTTF*)this->getChildByTag(2);
	if (mf>=this->getMana()){
		this->avail=true;
		stagelable->setVisible(false);
	}else {
		float fd= ptss->getPercentage();
		this->avail=false;
		stagelable->setVisible(true);
	}

}
