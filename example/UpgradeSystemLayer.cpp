#include "UpgradeSystemLayer.h"
#include "DefenderGameLayer.h"
USING_NS_CC;
CCScene* UpgradeSystemLayer::scene(){
	CCScene* scene=CCScene::create();
	UpgradeSystemLayer* layer=UpgradeSystemLayer::create();
	scene->addChild(layer);
	return scene;
}
bool UpgradeSystemLayer::init(){
	bool isRet=false;
	do 
	{
		CC_BREAK_IF(!BaseLayer::init());
		CC_BREAK_IF(!this->setUpdateView());
		isRet=true;
	} while (0);
	return isRet;
}
bool UpgradeSystemLayer::setUpdateView(){
	bool isRet=false;
	do {
		char temp[12];
		// ��ʼ������
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("game/lvSyspng.plist",CCTextureCache::sharedTextureCache()->textureForKey("game/lvSyspng.png"));
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("game/lvinfo.plist",CCTextureCache::sharedTextureCache()->textureForKey("game/lvinfo.png"));

		CCSprite* pbg=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("gmbg/research_bg.png"));
		CC_BREAK_IF(!pbg);
		pbg->setPosition(getWinCenter());
		this->addChild(pbg);

		int gold =CCUserDefault::sharedUserDefault()->getIntegerForKey("goldNum",0);
		// �����Ŀ
		sprintf(temp,"%d",gold);
		CCLabelAtlas* goldnumbrer= CCLabelAtlas::create(temp,"game/numtips.png",25,31,'0');
		CC_BREAK_IF(!goldnumbrer);
		goldnumbrer->setAnchorPoint(ccp(0,0));
		goldnumbrer->setPosition(ccp(425,440));
		goldnumbrer->setScale(0.5);
		this->addChild(goldnumbrer,1,5);


		int lve=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
		sprintf(temp,"%d",lve);
		// ��ǰ�ؿ�
		CCLabelAtlas* stagenumbrer= CCLabelAtlas::create(temp,"game/numtips.png",25,31,'0');
		CC_BREAK_IF(!stagenumbrer);
		stagenumbrer->setScale(0.5);
		stagenumbrer->setAnchorPoint(ccp(0,0));
		stagenumbrer->setPosition(ccp(715,440));
		this->addChild(stagenumbrer,1,6);

		// ѡ��ĳ����ť����ʾ�߿�
		CCSprite* pselect= CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("logselect.png"));
		CC_BREAK_IF(!pselect);
		pselect->setVisible(false);
		this->addChild(pselect,2,1);

		// ���� ������������ť
		CCMenuItemSprite* denfer=CCMenuItemSprite::create( CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("defender.png")), CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("defender.png")),this,menu_selector(UpgradeSystemLayer::publicClickCallBack));
		CC_BREAK_IF(!denfer);
		denfer->setPosition(getWinCenter());
		denfer->setPositionY(denfer->getPositionY()+90);
		denfer->setTag(2);


		//  ������ǽ������ť
		CCMenuItemSprite* citywall=CCMenuItemSprite::create( CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("citywall.png")), CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("citywall.png")),this,menu_selector(UpgradeSystemLayer::publicClickCallBack));
		CC_BREAK_IF(!citywall);
		citywall->setPosition(getWinCenter());	
		citywall->setTag(3);


		// ���� ħ��������ť
		CCMenuItemSprite* magictower=CCMenuItemSprite::create( CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("magictower.png")), CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("magictower.png")),this,menu_selector( UpgradeSystemLayer::publicClickCallBack));
		CC_BREAK_IF(!magictower);

		magictower->setPosition(getWinCenter());

		magictower->setPositionY(magictower->getPositionY()-90);
		magictower->setTag(4);


		// ����������ť
		CCMenuItemSprite* contin=CCMenuItemSprite::create( CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("button_nextup.png")), CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("btnnextdown.png")),this,menu_selector( UpgradeSystemLayer::coniteClickCallBack));
		CC_BREAK_IF(!contin);
		contin->setAnchorPoint(ccp(1,0));
		contin->setPosition(converSpritRel(getWinSize().width,10));


		// ����������ť
		CCMenuItemSprite* updage=CCMenuItemSprite::create( CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("btnupgradeUp.png")), CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("btnUpgradedown.png")),this,menu_selector(UpgradeSystemLayer::updateClickCallBack));
		CC_BREAK_IF(!updage);

		updage->setAnchorPoint(ccp(1,0));
		updage->setPosition(converSpritRel(getWinSize().width-180,10));
		updage->setTag(5);

		CCMenu* menu=CCMenu::create(denfer,citywall,magictower,contin,updage,NULL);
		CC_BREAK_IF(!menu);
		menu->setPosition(CCPointZero);
		this->addChild(menu,1,12);

		CCSprite* deinfo=CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("definfo.png"));
		deinfo->setAnchorPoint(ccp(0,0.5));
		deinfo->setPosition(ccp(10,48));
		this->addChild(deinfo,1,7);
		deinfo->setVisible(false);

		// ������ʾ��ҵ�Сͼ��

		CCSprite* coin=CCSprite::createWithTexture(CCTextureCache::sharedTextureCache()->textureForKey("game/coin.png"));
		coin->setAnchorPoint(ccp(0,0));
		coin->setPosition(converSpritRel(getWinSize().width-315,50));
		this->addChild(coin,1,11);
		coin->setVisible(false);

		// ��ʾ���������Ŀ
		CCLabelAtlas* updagexiao= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!updagexiao);
		updagexiao->setAnchorPoint(ccp(0,0));
		updagexiao->setPosition(converSpritRel(getWinSize().width-280,57));
		updagexiao->setScale(0.7f);
		this->addChild(updagexiao,1,10);
		updagexiao->setVisible(false);


		// ��ǰ�ȼ�˵��
		CCLabelAtlas* curint= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!curint);
		curint->setAnchorPoint(ccp(0,0));
		curint->setPosition(ccp(160,30));
		curint->setScale(0.5f);
		this->addChild(curint,1,8);
		curint->setVisible(false);

		// ��һ�ȼ�˵��
		CCLabelAtlas* nextp= CCLabelAtlas::create("0","game/numtips.png",25,31,'0');
		CC_BREAK_IF(!nextp);
		nextp->setAnchorPoint(ccp(0,0));
		nextp->setPosition(ccp(180,10));
		nextp->setScale(0.5f);
		this->addChild(nextp,1,9);
		nextp->setVisible(false);
		isRet=true;
	} while (0);
	return isRet;
}

// ͨ�ô����ص��¼�
void UpgradeSystemLayer::publicClickCallBack(cocos2d::CCObject* pSend){	
	CCMenuItemSprite* item=(CCMenuItemSprite*) pSend;
	CCSprite* pselect=(CCSprite*)this->getChildByTag(1);
	pselect->setPosition(item->getPosition());
	pselect->setVisible(true);
	int tag=item->getTag();
	this->initDefner(tag);
} 
// ������ť�ص��¼�
void UpgradeSystemLayer::updateClickCallBack(cocos2d::CCObject* pSend){
	int gold =CCUserDefault::sharedUserDefault()->getIntegerForKey("goldNum",0);
	if(selectId==2){	
		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������1000
		int denfehurtlv= CCUserDefault::sharedUserDefault()->getIntegerForKey("denfehurtlv",0); // Ĭ��0
		if((denfehurtlv+1)*1000<=gold){
			int defr= CCUserDefault::sharedUserDefault()->getIntegerForKey("denfehurt",10); // Ĭ�Ϲ�������10
			CCUserDefault::sharedUserDefault()->setIntegerForKey("denfehurt",(defr+5));// ����������
			CCUserDefault::sharedUserDefault()->setIntegerForKey("denfehurtlv",(denfehurtlv+1));// �����ȼ�
			gold=gold-(denfehurtlv+1)*1000;
			CCUserDefault::sharedUserDefault()->setIntegerForKey("goldNum",gold);// �۳����
			this->initDefner(selectId);
		}	
	}else if(selectId==3){
		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������500
		int citybloodlv= CCUserDefault::sharedUserDefault()->getIntegerForKey("citybloodlv",0); // Ĭ��0
		if((citybloodlv+1)*500<=gold){
			int cityblood= CCUserDefault::sharedUserDefault()->getIntegerForKey("cityblood",100); // Ĭ�Ϲ�������20
			CCUserDefault::sharedUserDefault()->setIntegerForKey("cityblood",(cityblood+10));// ����������
			CCUserDefault::sharedUserDefault()->setIntegerForKey("citybloodlv",(citybloodlv+1));// �����ȼ�
			gold=gold-(citybloodlv+1)*1000;
			CCUserDefault::sharedUserDefault()->setIntegerForKey("goldNum",gold);// �۳����
			this->initDefner(selectId);
		}	
	}else if(selectId==4){

		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������1500
		int citymglv= CCUserDefault::sharedUserDefault()->getIntegerForKey("citymglv",0); // Ĭ��0
		if((citymglv+1)*500<=gold){
			int citymg= CCUserDefault::sharedUserDefault()->getIntegerForKey("citymg",100); // Ĭ�Ϲ�������20
			CCUserDefault::sharedUserDefault()->setIntegerForKey("citymg",(citymg+10));// ����������
			CCUserDefault::sharedUserDefault()->setIntegerForKey("citymglv",(citymglv+1));// �����ȼ�
			gold=gold-(citymglv+1)*1000;
			CCUserDefault::sharedUserDefault()->setIntegerForKey("goldNum",gold);// �۳����
			this->initDefner(selectId);
		}	

	}

	// ���³�ʼ��������ʾ���ܽ����

	 CCLabelAtlas* goldnumbrer=(CCLabelAtlas*)this->getChildByTag(5);
	 char te[12];
	 sprintf(te,"%d",gold);
	 goldnumbrer->setString(te);

}
// ������Ϸ��ť�ص��¼�
void UpgradeSystemLayer::coniteClickCallBack(cocos2d::CCObject* pSend){
	CCScene* se=DefenderGameLayer::scene();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::create(1,se));
}
// ��ʼ����ʾ��ǩ������
void UpgradeSystemLayer::initDefner(int selectId){
	char temp[12];
	CCSprite* deinfo=(CCSprite*)this->getChildByTag(7);
	deinfo->setVisible(true);
	CCLabelAtlas* curint=(CCLabelAtlas*)this->getChildByTag(8);
	curint->setVisible(true);
	CCLabelAtlas* nextp= (CCLabelAtlas*)this->getChildByTag(9);
	nextp->setVisible(true);
	CCLabelAtlas* updagexiao=(CCLabelAtlas*)this->getChildByTag(10);
	updagexiao->setVisible(true);
	CCSprite* coin=(CCSprite*)this->getChildByTag(11);
	coin->setVisible(true);
	int tag=selectId;

	if(tag==2){// ����ķ�����	
		deinfo->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("definfo.png"));
		int defr= CCUserDefault::sharedUserDefault()->getIntegerForKey("denfehurt",10); // Ĭ�Ϲ�������20
		sprintf(temp,"%d",defr);
		curint->setString(temp);
		// ����û����һ�� ����5�㹥����
		sprintf(temp,"%d",(defr+5));
		nextp->setString(temp);
		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������1000
		int denfehurtlv= CCUserDefault::sharedUserDefault()->getIntegerForKey("denfehurtlv",0); // Ĭ�Ϲ�0
		sprintf(temp,"%d",(denfehurtlv+1)*1000);
		updagexiao->setString(temp);
		this->selectId=2;
	}else if(tag==3){ // ����
		deinfo->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("cityinfo.png"));	
		int cityblood= CCUserDefault::sharedUserDefault()->getIntegerForKey("cityblood",100); // Ĭ����100
		sprintf(temp,"%d",cityblood);
		curint->setString(temp);
		// ����û����һ�� ����10����Ѫ
		sprintf(temp,"%d",(cityblood+10));
		nextp->setString(temp);
		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������500
		int citybloodlv= CCUserDefault::sharedUserDefault()->getIntegerForKey("citybloodlv",0); // 0
		sprintf(temp,"%d",(citybloodlv+1)*500);
		updagexiao->setString(temp);

		this->selectId=3;
	}else if(tag==4){
		deinfo->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("maginfo.png"));	
		int citymg= CCUserDefault::sharedUserDefault()->getIntegerForKey("citymg",100); // Ĭ��ħ����100 ��
		sprintf(temp,"%d",citymg);
		curint->setString(temp);
		// ����û����һ�� ����10��ħ��
		sprintf(temp,"%d",(citymg+10));
		nextp->setString(temp);
		//��ûÿ��һ�� �����ĵĽ�����ϴε�˫�� ��һ��Ĭ��������1500
		int citymglv= CCUserDefault::sharedUserDefault()->getIntegerForKey("citymglv",0); // Ĭ��0
		sprintf(temp,"%d",(citymglv+1)*1500);
		updagexiao->setString(temp);
		this->selectId=4;
	}
}