#pragma once
#include "gameNode.h"

//������ �̹��� 
enum state
{
	ENEMYRUN,
	ENEMYDIE,
	ENEMYATT
};

//���ʹ� ����ü 
struct sEnemy
{
	float x, y;
	RECT rc;
	float angle;
	int width;
	int height;
	float speed;
	float jumpSpeed;
}; 

//���� ����
struct bossattack
{
	RECT rc;
	float x, y;
	float angle;
	float speed;
	bool fire;

};

class enemy : public gameNode
{
private:
	state sEnemyState;
	bossattack sBossAtt;

	sEnemy sBean; //����� ����ü
	sEnemy sMushroom; //���� ����ü
	sEnemy sBird; //�����(��) ����ü
	sEnemy sFlower; // �� ����ü
	sEnemy sBoss; //  ���� ����ü

	float gravity; // ����� �߷°�
	float flowerG; // �� �߷°�
	float bossG; // ���� �߷°�
	int count; //�߰��� ���� �ֱ����� ���� ī��Ʈ

	image* run;
	image* die;
	image* jump;

	bool bossJump; // ���� �����߳�?
	bool isJump; // ����� �����߳�?
	bool flowerJump;//�� �����߳�?
	bool _beanleft; //�� �������� ����?
	bool _beanright;//�� ���������� ����?

	bool _fishleft; //����� �������� ����?
	bool _fishright;//����� ���������� ����?

	bool _mushroomleft;  //������������ ����?
	bool _mushroomright; //���� ���������� ����?

	bool bossleft;		//���� �������� ����?
	bool bossright;		//���� ���������� ����?

	int imgCount;			//�ִϸ��̼�ī��Ʈ
	int imgIndex;			//�ִϸ��̼��ε���

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void enemyAnimation();
	void bossAttackMove();

};

