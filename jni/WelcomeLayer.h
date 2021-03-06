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
	// s设置界面
	bool setUpdateView();
	// 播放或者暂停音乐回调函数
	void vedioOnAndOffCallBack(cocos2d::CCObject* pSend);
	// 跳转的 关于开发者界面的回调函数
	void menuCoderCallback(cocos2d::CCObject* pSend);
	// 开始游戏 按钮回调方法
	void menuStarGame(cocos2d::CCObject* pSend);
	// 升级系统回调方法
	void menuUpGameCallback(cocos2d::CCObject* pSend);
	//退出游戏回调方法
	void menuGameOverCallback(cocos2d::CCObject* pSend);

};
#endif /* WELCOMELAYER_H_ */
