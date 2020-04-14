#pragma once
#include "gameNode.h"
#include "player.h"
//#include "enemy.h"
#include "tileNode.h"

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

class ingameScene : public gameNode
{
private:
	player* ptPlayer;
	//enemy* ptEnemy;

	//Ÿ�� -����
	tagTile sIngameTile[TILEX * TILEY];
	//���ȭ�� ��Ʈ -����
	RECT rcIngameBg;
	image* inGameBgImg;
	//�ε�� �̹��� - ����
	image* inGameTerrainImg;
	image* inGameObjectImg;
	//�������� ��Ʈ - ����
	RECT rcIngameWins;

	RECT rc[100];
	tagEnemyData sEnemyData_ingame[100];

	//�޴� ��Ʈ - ���� 0413
	RECT rcMenuMain;
	float menuX, menuY;
	RECT rcMenuButtonRS;	//����
	RECT rcMenuButtonOP;	//�ɼ�
	RECT rcMenuButtonEX;	//����Ʈ
	bool isTouch_RS;
	bool isTouch_EX;

	bool isMenu;

	//----------------------���ʹ� Ŭ���� ����
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
	bool beanleft; //�� �������� ����?
	bool beanright;//�� ���������� ����?

	bool _fishleft; //����� �������� ����?
	bool _fishright;//����� ���������� ����?

	bool _mushroomleft;  //������������ ����?
	bool _mushroomright; //���� ���������� ����?

	bool bossleft;		//���� �������� ����?
	bool bossright;		//���� ���������� ����?

	int imgCount;			//�ִϸ��̼�ī��Ʈ
	int imgIndex;			//�ִϸ��̼��ε���
	int imgCount2;			//�ִϸ��̼�ī��Ʈ
	int imgIndex2;			//�ִϸ��̼��ε���

	bool isRender[TILEX * TILEY];
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void load();

	void enemyAnimation();
	void bossAttackMove();

	ingameScene() {}
	~ingameScene() {}
};

