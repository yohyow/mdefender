#include "MonsterSprite.h"
#include "MonsterSystem.h"
USING_NS_CC;
MonsterSprite::MonsterSprite(void){
	runArray=CCArray::create();//���ܶ�������֡
	runArray->retain();
	deathArray=CCArray::create();//������������֡
	deathArray->retain();
	attackArray=CCArray::create();//������������֡  
	attackArray->retain();

}
MonsterSprite* MonsterSprite::createWithMonsterRul(const char* filename,CCTexture2D* ccTexture2D,const char* pic,int runcount,int attackcount,int deathcout ){
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(filename,ccTexture2D);
	CCSpriteFrame* temp=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s-10.png",pic)->getCString());
	MonsterSprite* monst=MonsterSprite::createWithSpriteFrame(temp);
	if (monst&&monst->setUpdateView()&&ccTexture2D){
		// ��ʼ�� ���ܶ�������֡
		for(int i=0;i<runcount;i++){

			monst->runArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s-1%d.png",pic,i)->getCString()));
		}
		// ��ʼ�� �������� ����֡
		for(int i=0;i<runcount;i++){
			monst->attackArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s-2%d.png",pic,i)->getCString()));
		}

		// ��ʼ�� �������� ����֡
		for(int i=0;i<runcount;i++){
			monst->deathArray->addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("%s-3%d.png",pic,i)->getCString()));
		}
		// ��ʼ��Ѫ��


		return monst;
	}else {
		return NULL;
	}
}
MonsterSprite* MonsterSprite::createWithSpriteFrame(CCSpriteFrame *pSpriteFrame){
	MonsterSprite* monSter=new MonsterSprite();
	if (pSpriteFrame&&monSter&&monSter->initWithSpriteFrame(pSpriteFrame))
	{
		monSter->autorelease();
		return monSter;
	}
	CC_SAFE_DELETE(monSter);
	return NULL;
}

bool MonsterSprite::setUpdateView(){
	bool isRet=false;
	do 
	{
		// ���Ѫ���ı���ͼƬ
		CCSprite* bloodbackimg=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/monster_blood_frame.png"));
		CC_BREAK_IF(!bloodbackimg);	
		bloodbackimg->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height+2));
		this->addChild(bloodbackimg,1);

		// ��ӽ�����
		CCSprite* blood=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/monster_blood.png"));
		CC_BREAK_IF(!blood);
		this->bloodBwlid=CCProgressTimer::create(blood);
		CC_BREAK_IF(!bloodBwlid);
		bloodBwlid->setType(kCCProgressTimerTypeBar);// ���óɺ����
		//���Կ����ǰ�������ʾЧ���Ľ���������
		bloodBwlid->setMidpoint(ccp(0,0)); 
		//  �����趨����������ǰ���ķ���������һ��Ǵ�������
		bloodBwlid->setBarChangeRate(ccp(1,0));

		bloodBwlid->setPosition(ccp(this->getContentSize().width/2,this->getContentSize().height+2));
		bloodBwlid->setPercentage(100);
		this->addChild(bloodBwlid,2);
		isRet=true;
	} while (0);
	return isRet;

}


// ִ�б��ܶ���
void MonsterSprite::runAnimation(){
	this->setMonState(2);
	this->stopAllActions();
	if(this->runArray->count()>0){
		CCAnimation *animation=CCAnimation::createWithSpriteFrames(runArray,0.15f);
		CCAnimate *animate=CCAnimate::create(animation);
		CCCallFuncN *onComplete =  CCCallFuncN::create(this, callfuncN_selector(MonsterSprite::runAnimationCallBack));  
		CCSequence* pse=CCSequence::create(animate,onComplete,NULL);
		// һֱִ�б��ܶ���
		this->runAction(CCRepeatForever::create(pse));

		this->schedule(schedule_selector(MonsterSprite::myload),0.15);
	}
}

void MonsterSprite::myload(float tie){
	if (this->getMonState()==2){
	this->moveRun();
	}
}

 void MonsterSprite::runAnimationCallBack(CCNode* pSed){
	 
 }

// ִ����������
void MonsterSprite::deathAnimation(){
	this->setMonState(4);
	this->stopAllActions();
	if(this->deathArray->count()>0){
		CCAnimation *animation=CCAnimation::createWithSpriteFrames(deathArray,0.15f);
		CCAnimate *animate=CCAnimate::create(animation);
		CCCallFuncN *onComplete =  CCCallFuncN::create(this, callfuncN_selector(MonsterSprite::deathAnimationCallBack));  
		CCSequence* pse=CCSequence::create(animate,onComplete,NULL);
		this->runAction(pse);
	}
}


 void MonsterSprite::deathAnimationCallBack(CCNode* pSed){
	 if(this->monsterSystem){
		 this->monsterSystem->recoverMonster(this);
	 }
	 bloodBwlid->setPercentage(100);
	 this->unscheduleAllSelectors();
	 this->monsterSystem->addGold(this->getGold());
}

// ִ�й�������
void MonsterSprite::attackAnimation(){
	this->setMonState(3);
	this->stopAllActions();
	if(this->attackArray->count()>0){
		CCAnimation *animation=CCAnimation::createWithSpriteFrames(attackArray,0.15f);
		CCAnimate *animate=CCAnimate::create(animation);
		CCCallFuncN *onComplete =  CCCallFuncN::create(this, callfuncN_selector(MonsterSprite::attackAnimationCallBack));  
		CCSequence* pse=CCSequence::create(animate,onComplete,NULL);
		this->runAction(CCRepeatForever::create(pse));
	}
}
// ����ǽ��ܹ��� ��Ҫ�ı� �ù������Ѫֵ ��Ѫ������ʾ
void MonsterSprite::fallBlood(float hurted){	
	// ���� һ����� �ֵܵ�10%���˺� ������	
	float temp= this->bloodBwlid->getPercentage()*this->getBlood()/100;// �õ��������ڵ���Ѫֵ
	float cha=temp-(hurted-this->getDefense()*0.1); // ��ȡ ���˺��Ժ����Ѫ	
	if(cha<=0){
		this->bloodBwlid->setPercentage(0);
		this->deathAnimation();
	}else {
		this->bloodBwlid->setPercentage(cha/this->blood*100);
	}
}

void MonsterSprite::attackAnimationCallBack(CCNode* pSed){
	 // �����ǵ�Ѫ
	 this->monsterSystem->bloodConsumption(1,this->getHurt());
	 this->unscheduleAllSelectors();
}
void MonsterSprite::moveRun(){
	int x=this->getPositionX();
	if(this->getMonState()==2){
		// ��X ������С�� ��С�ľ����� ��Ҫ���� ��������
		x=x-this->getSpeed();
		this->setPositionX(x);
		if(x<=this->getmaxRemoving()){
			this->attackAnimation();
		}
	}

}

CCRect MonsterSprite::converNowRect(){
    // �õ���ǰ�� ��������ڵľ���
	CCRect monsret=this->boundingBox();
	float x=monsret.getMinX()+this->getAttackRange().getMinX();
	float y=monsret.getMinY()-this->getAttackRange().getMinY();
	return CCRect(x,y,this->getAttackRange().getMaxX(),this->getAttackRange().getMaxY());
}

void MonsterSprite::setMonsterSystemUtils(MonsterSystem* monsterSystem){
	this->monsterSystem=monsterSystem;
}
MonsterSprite::~MonsterSprite(void){
	if (runArray)
	{
		runArray->autorelease();
	}

	if (deathArray)
	{
		deathArray->autorelease();
	}

	if (attackArray)
	{
		attackArray->autorelease();
	}
}