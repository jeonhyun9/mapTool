#pragma once
#include "gameNode.h"

//프레임 이미지 
enum state
{
	ENEMYRUN,
	ENEMYDIE,
	ENEMYATT
};

//에너미 구조체 
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

//보스 공격
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

	sEnemy sBean; //콩벌레 구조체
	sEnemy sMushroom; //버섯 구조체
	sEnemy sBird; //물고기(새) 구조체
	sEnemy sFlower; // 꽃 구조체
	sEnemy sBoss; //  보스 구조체

	float gravity; // 물고기 중력값
	float flowerG; // 꽃 중력값
	float bossG; // 보스 중력값
	int count; //중간에 텀을 주기위해 쓰는 카운트

	image* run;
	image* die;
	image* jump;

	bool bossJump; // 보스 점프했냐?
	bool isJump; // 물고기 점프했냐?
	bool flowerJump;//꽃 점프했냐?
	bool _beanleft; //콩 왼쪽으로 갔냐?
	bool _beanright;//콩 오른쪽으로 갔냐?

	bool _fishleft; //물고기 왼쪽으로 갔냐?
	bool _fishright;//물고기 오른쪽으로 갔냐?

	bool _mushroomleft;  //버섯왼쪽으로 갔냐?
	bool _mushroomright; //버섯 오른쪽으로 갔냐?

	bool bossleft;		//보스 왼쪽으로 갔냐?
	bool bossright;		//보스 오른쪽으로 갔냐?

	int imgCount;			//애니메이션카운트
	int imgIndex;			//애니메이션인덱스

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void enemyAnimation();
	void bossAttackMove();

};

