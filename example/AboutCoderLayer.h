#ifndef __ABOUTCODER_LAYER_H__
#define __ABOUTCODER_LAYER_H__
#include "BaseLayer.h"
USING_NS_CC;
//  ���������  ���ڿ����߽���
class AboutCoderLayer:public BaseLayer{
public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(AboutCoderLayer);
	void menuReturnCallBack(CCObject* pSend); // ������ذ�ť �������¼�
private:
	bool setUpdateView();
};
#endif
