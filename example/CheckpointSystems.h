#ifndef  __CHECKPOINT_SYSTEMS_H__
#define  __CHECKPOINT_SYSTEMS_H__
//�ؿ�ϵͳ
class   CheckpointSystems{
public:
	CheckpointSystems();
	~CheckpointSystems();
	//���ݹ������ͺ͵�ǰ�ȼ� ��ȡ������˺�����ֵ
	static int hurtHoist(int type); // ���������������
	static int speedHoist(int type);//���ݹؿ��͹������ͻ��ȡ��������ֵ
	static int monsterBach();//���ݵ�ǰ�ؿ�����������Ĳ��� �����Ϸ�Ѷ�
	static int bloodHoist(int type);//��Ѫ����
	static int monsterCount(int count);//���ݹؿ�����ȡ��ǰ���ֵ����� // �����ʵ����Ϸ���ص� �ҵ����ڻ��޷��ദһ������ĺ��������ݹؿ����������
};
#endif   