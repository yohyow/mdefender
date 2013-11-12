#ifndef __SNAILPROGRESS_SPRITE_H__
#define __SNAILPROGRESS_SPRITE_H__
#include "cocos2d.h"
/***
������Ҫ���Զ����һ����ţ��ʽ�Ľ�ͼ��

**/
class SnailProgressSprite:public cocos2d::CCNode{
public:
	SnailProgressSprite();
	~SnailProgressSprite();
	static SnailProgressSprite* createWithPic(const char* progressPic,const char* progressBgPic, const char* snailPic);// ��һ������ �Ƚ�������ͼƬ��ʵ���ǽ���������Ķ��� �ڶ������� ����������ͼƬ  ���������� ��ţ ����˵�ǻ����ͼƬ
	CC_SYNTHESIZE(float,runTime,RunTime);// ������������
	bool setUpdateView(const char* progressPic,const char* progressBgPic, const char* snailPic);
	void setSnailProgress(float jindu);// �������ý���
	void runSnailProgress();// ִ�� ���ȶ���
	void initialization();// ���³�ʼ������ؼ�

};

#endif