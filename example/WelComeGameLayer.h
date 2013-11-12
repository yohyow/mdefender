#ifndef __WELCOMEGAME_LAYER_H__
#define __WELCOMEGAME_LAYER_H__
#include "BaseLayer.h"
class WelComeGameLayer:public BaseLayer{
public:
	static cocos2d::CCScene* scene();
	virtual bool init();
	CREATE_FUNC(WelComeGameLayer);
	virtual void onEnter();
private:
	// s���ý���
	bool setUpdateView();
	// ���Ż�����ͣ���ֻص�����
	void vedioOnAndOffCallBack(cocos2d::CCObject* pSend);
	// ��ת�� ���ڿ����߽���Ļص�����
	void menuCoderCallback(cocos2d::CCObject* pSend);
	// ��ʼ��Ϸ ��ť�ص�����
	void menuStarGame(cocos2d::CCObject* pSend);
	// ����ϵͳ�ص�����
	void menuUpGameCallback(cocos2d::CCObject* pSend);
	//�˳���Ϸ�ص�����
	void menuGameOverCallback(cocos2d::CCObject* pSend);

};
#endif