#ifndef __MONSTER_SYSTEM_H__
#define __MONSTER_SYSTEM_H__
#include "cocos2d.h"
#include "MonsterSprite.h"

#include "BulletsSprite.h"
typedef struct MonsterUtils{
	float initBlood;// ��ʼ����Ѫ
	float initSpeed;// ��ʼ���ٶ�
	float defend;// ����ķ�����
	float hurt;// ������˺�ֵ
	const char* monsName;// �����ù����ʱ���ͨ������
	const char* picName;// �����ͼƬ
	const char* fileName;// ��������Ӧ��plist �ļ�������
	int   type;// ��������
	int   runCount;// ���ܶ�������
	int   actCount;// ������������
	int   detCount;// ������������
	float maxRun;// ����ƶ�����	
	const char* attackRangeRec;//���ڹ������ϻ���һ���ܵ��Ĺ�����Χ ���������ò������ ͼƬ �������ܵ�������ʱ�������һ�� �ַ����� ��ʽ��������{{x,y},{w, h}}
	int  gold;// ����Я��������� ���������� ���ӽ��
} Monster;
class DefenderGameLayer;
class MagicMatrixSprite;
// ����������������ϵͳ
class MonsterSystem{
public:
	MonsterSystem();
	~MonsterSystem();
	cocos2d::CCArray* getIdleMonsterArry();// ����������еĹ���
	cocos2d::CCArray* getRunMonsterArray();// �����������ڱ����еĹ���
	void addMonster(int type,int count);// �������̵߳�����ԶԶ���ϵĲ�������
	void setDefenderGameLayer(DefenderGameLayer* defenderGameLayer);
	bool collisionDetection(BulletsSprite* bulletsSprite);// ���빭�� ����Ƿ�͹��﷢����ײ
	void recoverMonster(MonsterSprite* monsterSprite);// ���չ���
	void collisionMagc(MagicMatrixSprite* maSprite);// ����ħ�������ħ����ͼƬ���� �������ײ
	void bloodConsumption(int type,float hurt);// ����ǵ�Ѫ/��ħ���Ĳ��� 1 ��ʾ��Ѫ 2 ��ʾ ��ħ��
	void recoverALLMonster();// ���յ����е����ڽ����ϵĹ���
	void addGold(int gold);//������������Ҫ���ӽ��
private:
	cocos2d::CCArray* idleMonsterArry;// ����������еĹ���
	cocos2d::CCArray* runMonsterArray;// �����������ڱ����еĹ���
    MonsterSprite*    productMonster(int type);//����������������Ӧ�Ĺ�������� 
	DefenderGameLayer* defenderGameLayer;// ��Ϸ����
	void addDefenderGameLayer(MonsterSprite* monsterSprite);// �ѱ����еĹ�����ӵ� ����������
	Monster dutu;// ÿ������µĹ��ﶼ��Ҫ���������һ�� �����ڹ��췽�������ʼ��
	void  monsterFormation(cocos2d::CCArray* monsterArrays);// ������ʵ��һ���򵥵Ĺ������� �����
	void  monsterFormationToOne(MonsterSprite* monsterSprite);// ���ַ�ʽ�Ƕ�һ�� ���������������
	void  monsterFormationOne(cocos2d::CCArray* monsterArrays);// ��һ�ַ�ʽ ȫ���������ʽ
	void  monsterFormationTwo(cocos2d::CCArray* monsterArrays);// �ڶ��ַ�ʽ �ų�һ�� ��Ȼ�����ڵ�ǰ�������Ŷ��ٸ�
	void  monsterFormationThree(cocos2d::CCArray* monsterArrays);// �����ַ�ʽ �ų�2��  ��������
	void  monsterFormationFour(cocos2d::CCArray* monsterArrays);// �������ַ�ʽ �ų�2��  ���������� ������� ��һ�ź� �ڶ��ŵĸ���
	void  monsterFormationFive(cocos2d::CCArray* monsterArrays);// �������ַ�ʽ ʵ��ǰ�������������ʽ

};
#endif
