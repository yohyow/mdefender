#include "MonsterSystem.h"
#include "DefenderGameLayer.h"
#include "MagicMatrixSprite.h"
#include "GameTipsSprite.h"
#include "CheckpointSystems.h"
USING_NS_CC;
MonsterSystem::MonsterSystem(){

	idleMonsterArry= CCArray::create();// ����������еĹ���
	idleMonsterArry->retain();
	this->runMonsterArray=CCArray::create(); // �����������ڱ����еĹ���
	this->runMonsterArray->retain();
	/**********************************************************************
	float initBlood;// ��ʼ����Ѫ
	float initSpeed;// ��ʼ���ٶ�
	float defend;// ����ķ�����
	float hurt;// ������˺�ֵ
	char* picName;// �����ͼƬ
	char* fileName;// ��������Ӧ��plist �ļ�������
	int   type;// ��������
	int   runCount;// ���ܶ�������
	int   actCount;// ������������
	int   detCount;// ������������
	float maxRun;// ����ƶ�����	                                                   
	************************************************************************/
	this->dutu.initBlood=100+5+CheckpointSystems::bloodHoist(1);
	this->dutu.initSpeed=5+CheckpointSystems::speedHoist(1);
	this->dutu.defend=1;
	this->dutu.hurt=10+CheckpointSystems::hurtHoist(1);
	this->dutu.monsName="dutu";
	this->dutu.picName="monster/dutu.png";
	this->dutu.fileName="monster/dutu.plist";
	this->dutu.type=1;
	this->dutu.runCount=8;
	this->dutu.actCount=14;
	this->dutu.detCount=8;
	this->dutu.maxRun=800*0.24;
	this->dutu.attackRangeRec="{{70,45},{30,110}}";
	this->dutu.gold=5;


}

////����������������Ӧ�Ĺ���
MonsterSprite*    MonsterSystem::productMonster(int type){
	if(type==1){
		MonsterSprite* sp=MonsterSprite::createWithMonsterRul(dutu.fileName,CCTextureCache::sharedTextureCache()->textureForKey(dutu.picName),dutu.monsName,dutu.runCount,dutu.actCount,dutu.detCount);
		sp->setHurt(dutu.hurt);
		sp->setDefense(dutu.defend);
		sp->setBlood(dutu.initBlood);
		sp->setSpeed(dutu.initSpeed);
		sp->setmaxRemoving(dutu.maxRun);
		sp->setMonType(dutu.type);
		sp->setMonState(1);
		sp->setAttackRange(CCRectFromString(dutu.attackRangeRec));
		sp->setMonsterSystemUtils(this);
		sp->setGold(dutu.gold);
		return sp;
	}
	return NULL;
}
// �ѱ����еĹ�����ӵ� ����������
void MonsterSystem::addDefenderGameLayer(MonsterSprite* monsterSprite){
	if(this->defenderGameLayer){
		this->defenderGameLayer->addChild(monsterSprite,2);
		monsterSprite->runAnimation();
	}
	this->getRunMonsterArray()->addObject(monsterSprite);
}

// ���빭�� ����Ƿ�͹��﷢����ײ
bool MonsterSystem::collisionDetection(BulletsSprite* bulletsSprite){
	bool iscon=false;
	if (this->getRunMonsterArray())
	{
		// �����Ǽ�� ���� �Ƿ�͹��﷢����ײ
		for(int i=0;i<this->getRunMonsterArray()->count();i++){
			MonsterSprite* monsterSprite=(MonsterSprite*)this->getRunMonsterArray()->objectAtIndex(i);
			// �����״̬���벻��������״̬
			if (monsterSprite->getMonState()!=4) 
			{
				// �жϵ�ǰ�Ĺ������ܹ���������ʱ��͹��� �Ƿ�����ײ
				iscon=bulletsSprite->boundingBox().intersectsRect(monsterSprite->converNowRect());
				if (iscon)
				{
					// ��ʾ�����ܵ����� ����Ҫ���е�Ѫ ����
					monsterSprite->fallBlood(bulletsSprite->getHurt());
					iscon=true;
					break;
				}else{
					continue;
				}
			}

		}
	}
	return iscon;
}

// ����ħ���󿴿��Ƿ���ײ
void MonsterSystem::collisionMagc(MagicMatrixSprite* maSprite){

	if (this->getRunMonsterArray())
	{
		// �����Ǽ�� ���� �Ƿ�͹��﷢����ײ
		for(int i=0;i<this->getRunMonsterArray()->count();i++){
			MonsterSprite* monsterSprite=(MonsterSprite*)this->getRunMonsterArray()->objectAtIndex(i);
			// �����״̬���벻��������״̬
			if (monsterSprite->getMonState()!=4) 
			{
				// �жϵ�ǰ�Ĺ������ܹ���������ʱ���ħ���� �Ƿ�����ײ
				bool iscon=maSprite->getHurtRect().intersectsRect(monsterSprite->converNowRect());
				if (iscon)
				{
					// ��ʾ�����ܵ����� ����Ҫ���е�Ѫ ����
					monsterSprite->fallBlood(maSprite->getHurt());
				}
			}

		}
	}

}

void MonsterSystem::recoverMonster(MonsterSprite* monsterSprite){
	// �������Ĺ����������
	this->getRunMonsterArray()->removeObject(monsterSprite,false);
	// �ӽ������Ƴ���
	this->defenderGameLayer->removeChild(monsterSprite,false);
	// ��ԭ����� ��������
	if(monsterSprite->getMonType()==1){
		monsterSprite->setBlood(dutu.initBlood);
		monsterSprite->setPosition(CCPointZero);
		monsterSprite->setMonType(dutu.type);
		// ͣ�����ж���
		monsterSprite->stopAllActions();
	}
	this->getIdleMonsterArry()->addObject(monsterSprite);
}
// ���յ����е����ڽ����ϵĹ���
void MonsterSystem::recoverALLMonster(){
for(int i=0;i<this->getRunMonsterArray()->count();i++){
MonsterSprite* monsterSprite=(MonsterSprite*)this->getRunMonsterArray()->objectAtIndex(0);
recoverMonster(monsterSprite);
i--;
}

}

// �������̵߳�����ԶԶ���ϵĲ�������
void MonsterSystem::addMonster(int type,int count){
	CCArray* formation=CCArray::create();

	for(int i=0;i<count;i++){
		MonsterSprite* runmon=NULL;

		for(int j=0;j<this->getIdleMonsterArry()->count();j++){
			MonsterSprite* temmon=(MonsterSprite*)this->getIdleMonsterArry()->objectAtIndex(j);
			if (temmon->getMonType()==type){
				runmon=temmon;
				break;
			}

		}
		// ����ӿ��е��߳� �õ�����Ҫ�� ��������  ����ӵ������� ��֮ ����Ҫ����һ��
		if (runmon){
			this->getIdleMonsterArry()->removeObject(runmon,false);
			formation->addObject(runmon);
		}else {
			MonsterSprite* temmon= this->productMonster(type);
			if (temmon)
			{
				this->getIdleMonsterArry()->addObject( this->productMonster(type));
				i--;
			}else {
				break;
			}

		}


	}

	monsterFormation(formation);

}

// ���������ʵΪ�� �������Ĺ��� �ض������� Ҫ��ȫ��������Ļ������� ���ﲻ����
void MonsterSystem::monsterFormation(CCArray* monsterArrays){
	if (monsterArrays){
		int count=monsterArrays->count();
		// ���������� С�ڵ���3��ʱ��  ����ȫ��������㷨
		if (count<=3){
		monsterFormationOne(monsterArrays);
		}else {
		float ran=CCRANDOM_0_1();
		int dt=ran*5;
		switch(dt){
		case 1:monsterFormationTwo(monsterArrays);break;
		case 2:monsterFormationThree(monsterArrays);break; 
		case 3:monsterFormationFour(monsterArrays);break; 
		default:monsterFormationOne(monsterArrays);
		}
		
		}
		for(int i=0;i<monsterArrays->count();i++){
			MonsterSprite* temmon=(MonsterSprite*)monsterArrays->objectAtIndex(i);
			this->addDefenderGameLayer(temmon);
		}
	}
}

void  MonsterSystem::monsterFormationToOne(MonsterSprite* monsterSprite){
	float ran=CCRANDOM_0_1();
	CCSize size=this->defenderGameLayer->getContentSize();
	float x=size.width+monsterSprite->getContentSize().width/2+50*ran;// �ղ����µĹ����X ����϶� ����Ļ����� ȻX �������50��С��Χ�ڸ���
	float temp=size.height*ran+monsterSprite->getContentSize().height/2;
	float y=0;
	if (temp>=size.height){
		y=size.height-monsterSprite->getContentSize().height/2;
	}else{
		if(ran!=0){
			if (size.height*ran<monsterSprite->getContentSize().height/2){
				y=temp+40;// ��һ����ʵ���ǲ��ù���̫������ 
			}else {
				y=size.height*ran;
			}

		}else {
			y=monsterSprite->getContentSize().height/2;
		}
	}

	monsterSprite->setPosition(ccp(x,y));
}

// ��һ�ַ�ʽ ȫ���������ʽ
void  MonsterSystem::monsterFormationOne(cocos2d::CCArray* monsterArrays){
	for(int i=0;i<monsterArrays->count();i++){
		MonsterSprite* monsterSprite=(MonsterSprite*)monsterArrays->objectAtIndex(i);
		float ran=CCRANDOM_0_1();
		CCSize size=this->defenderGameLayer->getContentSize();
		float x=size.width+monsterSprite->getContentSize().width/2;// �ղ����µĹ����X ����϶� ����Ļ�����
		float temp=size.height*ran+monsterSprite->getContentSize().height/2;
		float y=0;
		if (temp>=size.height){
			y=size.height-monsterSprite->getContentSize().height/2;
		}else{
			if(ran!=0){
				if (size.height*ran<monsterSprite->getContentSize().height/2){
					y=temp+40;// ��һ����ʵ���ǲ��ù���̫������ 
				}else {
					y=size.height*ran;
				}

			}else {
				y=monsterSprite->getContentSize().height/2;
			}
		}

		monsterSprite->setPosition(ccp(x,y));
	}


}
// �ڶ��ַ�ʽ �ų�һ�� ��Ȼ�����ڵ�ǰ�������Ŷ��ٸ�
void  MonsterSystem::monsterFormationTwo(cocos2d::CCArray* monsterArrays){
	// �������һ��Ҫ���� ��Ļ���м�Ϊ��׼
	CCSize size=this->defenderGameLayer->getContentSize();// �õ�����Ϸ�� ��Ļ�ߴ�Ĵ�С
	MonsterSprite* tempspr=(MonsterSprite*)monsterArrays->objectAtIndex(0);// ����ȡ���ﾫ��
	CCSize monstersize=tempspr->getContentSize();
	float dqwidth=size.height-40;//����ǹ涨�߶ȰڷŵĹ���ĸ߶�
	int count=(int)((size.height-40)/monstersize.height); // ��ȡһ������ܷ��ö��ٹ���
	float totalh=count*monstersize.height;
	if(count>monsterArrays->count()){
		totalh=monsterArrays->count()*monstersize.height;
	}

	float cha=(dqwidth-totalh)/2;// �õ����µĵȲ�ֵ
	if(count>=monsterArrays->count()){ // ��ʾ���Էֳ�һ��	
		for(int i=0;i<monsterArrays->count();i++){
			MonsterSprite* monsterSprite=(MonsterSprite*)monsterArrays->objectAtIndex(i);// ��ȡ���ﾫ��
			float x=size.width+monstersize.width/2;
			float y=monstersize.height*i+cha+monstersize.height/2;
			monsterSprite->setPosition(ccp(x,y));

		}

	}else {		
		for(int i=0;i<monsterArrays->count();i++){
			MonsterSprite* monsterSprite=(MonsterSprite*)monsterArrays->objectAtIndex(i);//��ȡ���ﾫ��
			if ((i+1)>count){
				this->monsterFormationToOne(monsterSprite);
			}else{			
				float x=size.width+monstersize.width/2;
				float y=monstersize.height*i+cha+monstersize.height/2;
				monsterSprite->setPosition(ccp(x,y));
			}		

		}
	}
}
// �����ַ�ʽ �ų�2��  ��������
void  MonsterSystem::monsterFormationThree(cocos2d::CCArray* monsterArrays){    
	CCSize size=this->defenderGameLayer->getContentSize();// �õ�����Ϸ�� ��Ļ�ߴ�Ĵ�С
	MonsterSprite* tempspr=(MonsterSprite*)monsterArrays->objectAtIndex(0);// ����ȡ���ﾫ��	
	float dqwidth=size.height-20;//����ǹ涨�߶ȰڷŵĹ���ĸ߶�
	CCSize monstersize=tempspr->getContentSize();
	float totalh=2*monstersize.height+40; // ��������֮��ĸ߶�
	float cha=(dqwidth-totalh)/2;// �õ����µĵȲ�ֵ

	for(int i=0;i<monsterArrays->count();i++){
		MonsterSprite* monsterSprite=(MonsterSprite*)monsterArrays->objectAtIndex(i);// ����ȡ���ﾫ��
		//ż����ȫ������ �����һ��  ������ȫ�����������һ��
		float x=size.width+monstersize.width/2+monstersize.width*((int)i/2);
		float y=monstersize.height+cha+monstersize.height/2;
		monsterSprite->setPositionX(x);
		if(i%2==0){		
			monsterSprite->setPositionY(y);
		}else {
			monsterSprite->setPositionY(y+40+monstersize.height/2);
		}

	}


}
// �������ַ�ʽ �ų�2��  ���������� ������� ��һ�ź� �ڶ��ŵĸ���
void  MonsterSystem::monsterFormationFour(cocos2d::CCArray* monsterArrays){
	CCSize size=this->defenderGameLayer->getContentSize();// �õ�����Ϸ�� ��Ļ�ߴ�Ĵ�С
	MonsterSprite* tempspr=(MonsterSprite*)monsterArrays->objectAtIndex(0);// ����ȡ���ﾫ��
	CCSize monstersize=tempspr->getContentSize();
	float dqwidth=size.height-20;//����ǹ涨�߶ȰڷŵĹ���ĸ߶�
	int count=(int)((dqwidth)/monstersize.height); // ��ȡһ������ܷ��ö��ٹ���
	float totalh=count*monstersize.height;
	float cha=(dqwidth-totalh)/2;// �õ����µĵȲ�ֵ
	int shiji=(int)monsterArrays->count()/2;

	if (count>=shiji){

		for(int i=0;i<monsterArrays->count();i++){
			MonsterSprite* monsterSprite=(MonsterSprite*)monsterArrays->objectAtIndex(i);// ��ȡ���ﾫ��		
			if((i+1)<=shiji){		
				float x=size.width+monstersize.width/2;
				float y=monstersize.height*i+cha+monstersize.height/2;
				monsterSprite->setPosition(ccp(x,y));
			}else if((i+1)>shiji&&(i-shiji)<=count){
				//  ��������Ĺ�������꽫���϶���ķ�ʽ
				float x=size.width+monstersize.width/2+20+monstersize.width/2;
				float y=monstersize.height*(i-shiji)+cha+monstersize.height/2;
				monsterSprite->setPosition(ccp(x,y));
			}else {
				this->monsterFormationToOne(monsterSprite);
			}

		}

	}
}
// �������ַ�ʽ ʵ��ǰ�������������ʽ
void  MonsterSystem::monsterFormationFive(cocos2d::CCArray* monsterArrays){

}
// ����ǵ�Ѫ/��ħ���Ĳ��� 1 ��ʾ��Ѫ 2 ��ʾ ��ħ��

void MonsterSystem::bloodConsumption(int type,float hurt){
	this->defenderGameLayer->bloodConsumption(type,hurt);
}

void MonsterSystem::addGold(int gold){
	
	GameTipsSprite* gameTipsSprite=(GameTipsSprite*) this->defenderGameLayer->getChildByTag(8);
	int goldnum=CCUserDefault::sharedUserDefault()->getIntegerForKey("goldNum",0);
	goldnum=gold+goldnum;
	CCUserDefault::sharedUserDefault()->setIntegerForKey("goldNum",goldnum);
	gameTipsSprite->setgoldNum(goldnum);

	
	int killtemp=CCUserDefault::sharedUserDefault()->getIntegerForKey("killtemp",1);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("killtemp",killtemp+1);




}



void MonsterSystem::setDefenderGameLayer(DefenderGameLayer* defenderGameLayer){
	this->defenderGameLayer=defenderGameLayer;
}

CCArray* MonsterSystem::getRunMonsterArray(){
	return this->runMonsterArray;

}
CCArray* MonsterSystem::getIdleMonsterArry(){
	return this->idleMonsterArry;
}

MonsterSystem::~MonsterSystem(){
	if (idleMonsterArry)
	{
		this->idleMonsterArry->autorelease();
	}
	if (runMonsterArray)
	{
		this->runMonsterArray->autorelease();
	}

}