#ifndef __RATING_SPRITE_H__
#define __RATING_SPRITE_H__
//������Ҫ�ǵȼ� ��ʾ�ľ���
#include "cocos2d.h"
class RatingSprite:public cocos2d::CCSprite{
public:
	RatingSprite();
	~RatingSprite();
    static RatingSprite* createWidthPic(const char* picName);// �˴���ͼƬ������ڻ�����
   void runAnimation();
   void	 setLeverNum(int number);// ���õ�ǰ��ʾ�ĵȼ�  
private:
 bool	setUpdateView();
  void runAnimationCallBack(cocos2d::CCNode* psed);
};
#endif