#ifndef __BULLETS_SPRITE_H__
#define __BULLETS_SPRITE_H__
#include "cocos2d.h"
class BulletsSprite :public cocos2d::CCSprite
{
public:
	BulletsSprite(void);
	~BulletsSprite(void);
	//virtual bool initWithTexture(cocos2d::CCTexture2D *pTexture);
	static BulletsSprite* createWithTexture(cocos2d::CCTexture2D *pTexture);
	inline void setMovespeed(float movespeed){
		this->movespeed=movespeed;
	}

	inline	float getMovespeed(){
		return movespeed;
	}

	inline void setHurt(float hurt){
		this->hurt=hurt;
	}
	inline	float getHurt(){
		return hurt;
	}
	cocos2d::CCPoint getMovePoint();// ����� ���ݵ�ǰ�ٶȻ�ȡ �����Ӧ���ڵ� ����

	void mymove();//  �ƶ�����
	// ��һ�α�����Ϊ�����ĽǶ�
	CC_SYNTHESIZE(float,firstRoto,FirstRoto);
	// ���һ�α������ĽǶ�
	CC_SYNTHESIZE(float,lastRoto,LastRoto);
private:
	float movespeed;// �ƶ��ٶ�
	float hurt;// �������˺�ֵ
};
#endif