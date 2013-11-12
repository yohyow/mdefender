#ifndef __MAGICMATRIX_SPRITE_H__
#define __MAGICMATRIX_SPRITE_H__
#include "cocos2d.h"
#include "DefenderGameLayer.h"
//������ħ������
class MagicMatrixSprite:public cocos2d::CCNode{
public:
      MagicMatrixSprite();
	  ~MagicMatrixSprite();
	  CC_SYNTHESIZE(float,hurt,Hurt);// �˺�ֵ
	  CC_SYNTHESIZE(bool,avail,Avail);//�Ƿ����  
	  CC_PROPERTY(bool,activation,Activation);// �Ƿ񼤻�ħ����
	  // ע��һ��ͼƬ������ڻ�������
	  static MagicMatrixSprite* createWithPic(const char* pMagicPic,const char* pMagicPicBg); // ��һ������CD �ıȽϰ�����ͼƬ �ڶ����Ǳ�����ͼƬ
	  CC_SYNTHESIZE(float,mana,Mana);// ����ħ��ֵ
	  void runMagicCDAnimation();// ִ��ħ��CD ����
	  CC_SYNTHESIZE(const char* ,speciaPicName,SpeciaPicName);// ͼƬ������
	  CC_SYNTHESIZE(const char* ,speciaFileName,SpeciaFileName);// plist �ļ�������
	  CC_SYNTHESIZE(const char* ,speciaName,SpeciaName);//��Ч��ͨ������
	  CC_SYNTHESIZE(int,speciaCount,SpeciaCount);//��Ч��ͼƬ������
	  CC_SYNTHESIZE(cocos2d::CCPoint,anchorPo,AnchorPo);// ��ǰħ����Ч�����λ��
	  CC_SYNTHESIZE(cocos2d::CCRect,hurtRect,HurtRect);//�յ���ħ��������Χ
	  void runSpecial(DefenderGameLayer* layer,cocos2d::CCPoint point);//ִ�в��ŵ�ǰ������Ч�Ķ���
	  void initialization();// ���³�ʼ��ǰ��ħ����
private:
	  bool setUpdateView(const char* pMagicPic,const char* pMagicPicBg );
	  cocos2d::CCProgressTimer *ptss;// ħ�����CD ����
	  void runMagicCDAnimationCallBack(cocos2d::CCNode* pSed);
	  void runSpecialCallBack(cocos2d::CCNode* pSend);
	  void detectMagic(float ti);// ��⵱ǰħ���Ƿ���
	 
};
#endif
