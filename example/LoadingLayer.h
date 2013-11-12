#ifndef __LOADING_LAYER_H__
#define __LOADING_LAYER_H__
#include "BaseLayer.h"

class LoadingLayer:public BaseLayer{
public:
	virtual bool init();
	CREATE_FUNC(LoadingLayer);
	static cocos2d::CCScene* scene();
	void loadCallBack(cocos2d::CCObject* ped);// �첽����ͼƬʱ �Ļص�����
	LoadingLayer();
private:
	int loadingNum;//������¼��ǰ�ļ���ͼƬ������
	int totalNum;// һ��Ҫ���ص�ͼƬ����
	bool setUpdateView();// ������ʼ��ҳ��� ����������
	void goWelcomeLayer();
};
#endif