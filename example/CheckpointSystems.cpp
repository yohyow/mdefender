#include "CheckpointSystems.h"
#include "cocos2d.h"
USING_NS_CC;
// ���������������
int CheckpointSystems::hurtHoist(int type) {
	//�������� ÿʮ�� �˺�ֵ����һ��  // ����Ŀǰֻ��һ�ֹ��� ����Լ����ݲ�ͬ�Ĺ����������
	
	 int i=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
	 int temp=i/10;
	 return temp;

}
	//���ݹؿ��͹������ͻ��ȡ��������ֵ
int CheckpointSystems::speedHoist(int type){
	//�������� ÿʮ�� �ٶ� ���� һ �� ��������з�ֵ �����������ڹ涨20Ϊ��ֵ 

	int i=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
	int temp=i/10;

	if(temp>=20){
		temp=20;
	}

	return temp;
}
//���ݵ�ǰ�ؿ�����������Ĳ��� �����Ϸ�Ѷ�
int CheckpointSystems::monsterBach(){
	//�������� ÿ��� ���� ���� һ �� ��������з�ֵ �����������ڹ涨20Ϊ��ֵ  ��ΪĬ������ʮ��
	int i=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
	int temp=i/5;
	if(temp>=20){
		temp=20;
	}
	return temp;
}

 int  CheckpointSystems::bloodHoist(int type){
	 //�������� ÿ��� ��Ѫ ���� һ ��  
	 int i=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
	 int temp=i/5;	 
	 return temp;
 }
 //���ݹؿ�����ȡ��ǰ���ֵ����� // �����ʵ����Ϸ���ص� �ҵ����ڻ��޷��ദһ������ĺ��������ݹؿ����������
int CheckpointSystems::monsterCount(int count){
	 int i=CCUserDefault::sharedUserDefault()->getIntegerForKey("lve",1);
      

	 // �������������涨 �����Ǹ��ؿ� ǰ�����Ĺ����� ���ܴ���3 ����Ĳ��ܴ���10 �в��ܵ���2
	 float ran=CCRANDOM_0_1();
	 int temp=(int)(ran*10);
	 temp=temp==0?1:temp;
	 if(i<=10){
		 if(count<=3){
			 if(temp>3){
				 temp=3;
			 }
		 }else {
			 if(temp<3){
				 temp=temp+1;		
			 }
		 }
	 }else {
		 if(count<=3){
			 if(temp<3){
				 temp=temp+1;
			 }
		 }else {
			 if(temp<5){
				 temp=temp+1;		
			 }
		 }
	 }

	
	 return temp;
}