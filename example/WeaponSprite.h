#ifndef __WEAPON_SPRITE_H__
#define __WEAPON_SPRITE_H__
#include "cocos2d.h"
#include "BulletsSprite.h"
#include "MagicMatrixSprite.h"
// ���������ϵͳ ���������ӵ�
class WeaponSprite:public cocos2d::CCSprite{
public:
	WeaponSprite();
	
	~WeaponSprite();
	
	CREATE_FUNC(WeaponSprite);
	
	virtual bool initWithTexture(cocos2d::CCTexture2D *pTexture);
	
	static WeaponSprite* createWithTexture(cocos2d::CCTexture2D *pTexture);
	cocos2d::CCArray* getIdleBullet(int cout);// ����Ŀǰ����ϵ �ļ����ȡ��ǰ �ӵ������� Ĭ�ϼ�����1�� ���е��ӵ� 
	void recoverBullet(BulletsSprite* pbullet);// ���յ�һ���ӵ�
	void initIdleBulletSpool(cocos2d::CCLayer* pLayer);// ��ʼ���ӵ��� 
	CC_SYNTHESIZE(bool,stop,Stop);
	// ���õ�ǰ��������ת�Ļ�����
	void setHudu(float hudu);
	inline cocos2d::CCSpriteBatchNode* getBatchNode(){
		return batchNode;
	}
	inline	cocos2d::CCArray* getRunBulletsPool(){
		return pRunBulletsPool;
	}
	
	inline	cocos2d::CCArray* getLoadedArray(){
		return loadedArray;
	}
	// ��������ת��ʱ�� ����ǹ������ĵ�ҩҲ����Ҫ��ת��
	void rotateLoadedBullets();
	// ������װ���ӵ� cout ��ʾ һ���ϵ��ӵ��ĸ���
	void loadedBullet(int cout=1);

	inline cocos2d::CCArray* getMagicArray(){
		return magicArray;
	}

	void initIdleMagicSpool(cocos2d::CCLayer* pLayer);// ��ʼ��ħ������

	MagicMatrixSprite* touchMagic(cocos2d::CCPoint point);// �鿴�����ĵ��Ƿ��� ħ������ ������ڿձ�ʾû��ħ������ �����Ϊ�շ��ص�ǰħ����
	CC_SYNTHESIZE(bool, touchMg,TouchMg);// �������true ��ʾ��ǰ�� ���ڵ�� ħ����
	CC_SYNTHESIZE(MagicMatrixSprite*, magicMatrixSprite,magicMatrixSprite);// ��ǰ������ħ����

	void initialization();

private:
	cocos2d::CCArray* pIdleBulletsPool;// �����ӵ���
	cocos2d::CCArray* pRunBulletsPool;// �������е��ӵ���
	cocos2d::CCSpriteBatchNode* batchNode;// ���������ӵ�  �Ż�����
	cocos2d::CCArray* loadedArray;// �������ŵ��ӵ� ��ʵ�����ڹ�������ʾ���ӵ� ���ʱ����ӵ��Ǵ���״̬
	cocos2d::CCArray* magicArray;// ħ����
	float hudu;// ��������ת�Ļ���ֵ	
	void loade(float tim);
	
	
};
#endif