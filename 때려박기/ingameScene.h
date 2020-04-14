#pragma once
#include "gameNode.h"
#include "player.h"
//#include "enemy.h"
#include "tileNode.h"

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

class ingameScene : public gameNode
{
private:
	player* ptPlayer;
	//enemy* ptEnemy;

	//타일 -이준
	tagTile sIngameTile[TILEX * TILEY];
	//배경화면 렉트 -이준
	RECT rcIngameBg;
	image* inGameBgImg;
	//로드용 이미지 - 이준
	image* inGameTerrainImg;
	image* inGameObjectImg;
	//윈사이즈 렉트 - 이준
	RECT rcIngameWins;

	RECT rc[100];
	tagEnemyData sEnemyData_ingame[100];

	//메뉴 렉트 - 이준 0413
	RECT rcMenuMain;
	float menuX, menuY;
	RECT rcMenuButtonRS;	//리썸
	RECT rcMenuButtonOP;	//옵션
	RECT rcMenuButtonEX;	//엑시트
	bool isTouch_RS;
	bool isTouch_EX;

	bool isMenu;

	//----------------------에너미 클래스 변수
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
	bool beanleft; //콩 왼쪽으로 갔냐?
	bool beanright;//콩 오른쪽으로 갔냐?

	bool _fishleft; //물고기 왼쪽으로 갔냐?
	bool _fishright;//물고기 오른쪽으로 갔냐?

	bool _mushroomleft;  //버섯왼쪽으로 갔냐?
	bool _mushroomright; //버섯 오른쪽으로 갔냐?

	bool bossleft;		//보스 왼쪽으로 갔냐?
	bool bossright;		//보스 오른쪽으로 갔냐?

	int imgCount;			//애니메이션카운트
	int imgIndex;			//애니메이션인덱스
	int imgCount2;			//애니메이션카운트
	int imgIndex2;			//애니메이션인덱스

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

