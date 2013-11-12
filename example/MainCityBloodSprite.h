#ifndef __MAINCITYBLOOD_SPRITE_H__
#define __MAINCITYBLOOD_SPRITE_H__
#include "cocos2d.h"

class MainCityBloodSprite:public cocos2d::CCSprite{
public:
	static MainCityBloodSprite* createWithTexture(cocos2d::CCTexture2D *pTexture);
	MainCityBloodSprite();
	~MainCityBloodSprite();
	CC_PROPERTY(float,blood,Blood);// �������ǵ���Ѫ��
	CC_PROPERTY(float,magic,Magic);// �������ǵ�ħ��ֵ
	float injuries(float hurt);// ���ܵ��������˺�  �������ʣ����Ѫ
	float mana(float mf);// ����ʣ��ħ��ֵ 
	void  restoreBlood();// �ָ�������Ѫ��ħ��
private:
	bool setUpdateView();
	cocos2d::CCProgressTimer* bloodBwlid;// ��Ѫ������
	cocos2d::CCProgressTimer* magicBwlid;// ħ��������



};


#endif