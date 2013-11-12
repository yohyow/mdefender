/*
 * WelcomeLayer.h
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#ifndef WELCOMELAYER_H_
#define WELCOMELAYER_H_

#include "MBaseLayer.h"
class WelcomeLayer:public MBaseLayer{
public:
	virtual bool init();
	CREATE_FUNC(WelcomeLayer);
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
#endif /* WELCOMELAYER_H_ */
