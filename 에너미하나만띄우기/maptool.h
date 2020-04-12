#pragma once
#include "gameNode.h"
#include "tileNode.h"
class maptool : public gameNode
{
private:
	tagTile sTile[TILEX * TILEY];
	tagTile sMiniTile[TILEX * TILEY];
	tagSampleTile sSampleTile[SAMPLETILEX * SAMPLETILEY];
	tagCurrentTile sCurrentTile;
	tagToolBox sToolBox;
	tagToolBtn sToolBtn;
	tagEnemyTile sEnemyTile; //에너미 타일 렉트 구조체 -동주 0410

	image* imgTile;

	CTRL ctrlSelect;

	bool isDrag;
	RECT dragRc;
	float saveX, saveY;

	//윈사이즈 렉트
	RECT rcWins;
	//배경화면 렉트
	RECT rcBg;
	//미니맵 렉트
	RECT rcMini;
	RECT rcMcamera;
	

	//버튼클릭이미지 렌더용			//불변수 추가
	bool isSaveClick;
	bool isLoadClick;
	bool isObjectClick;
	bool isTerrainClick;
	bool isDragBoxClick;
	bool isEraserClick;
	bool isResetClick;
	bool isLeftPointerClick;
	bool isRightPointerClick;
	bool isDragClick;
	bool isPlayerClick;
	bool isEnemyClick;
	bool isExitClick;
	//버튼 클릭이미지
	image* terrainImg;
	image* terrainImgMini;

	image* objectImg;
	image* objectImgMini;

	image* enemyImg; // 에너미 타일 변수 추가 - 동주
	image* enemyImgMini; // 에너미 미니타일 변수 추가 - 동주  

	image* toolBoxImg;
	image* buttonEraserImg;
	image* buttonLoadImg;
	image* buttonResetImg;
	image* buttonSaveImg;
	image* buttonTerrainImg;
	image* buttonObjectImg;
	image* buttonDragImg;
	image* buttonPlayerImg;
	image* buttonEnemyImg;
	image* buttonExitImg;

	image* buttonEraserOnImg;
	image* buttonLoadOnImg;
	image* buttonResetOnImg;
	image* buttonSaveOnImg;
	image* buttonTerrainOnImg;
	image* buttonObjectOnImg;
	image* buttonDragOnImg;
	image* buttonPlayerOnImg;
	image* buttonEnemyOnImg;
	image* buttonExitOnImg;

	image* buttonLeftImg;
	image* buttonRightImg;

	image* buttonLeftOnImg;
	image* buttonRightOnImg;

	image* mapToolBgImg;
	image* miniMapImg;

	//에너미 프레임 이미지 변수 -동주 0410
	image* bossImg;
	image* bossAttackImg;
	image* greenTurtleImg;
	image* blueTurtleImg;
	image* wingTurtleImg;
	image* dochiImg;
	image* mushroomImg;
	image* greenFlowerImg;
	image* blueFlowerImg;
	image* greyBirdImg;
	image* redBirdImg;
	image* greenBirdImg;
	image* greyBeanImg;
	image* blackBeanImg;
	image* blueBeanImg;
	image* rightBulletImg;
	image* leftBulletImg;
	image* cannonImg;

	
	
	//툴박스 렉트
	RECT rcToolCamera;			//툴박스 왼쪽편 블럭 인터섹트렉트용 카메라렉트 - 이준

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//타일 셋업
	void tileSetup();
	void setMap();

	//세이브 로드
	void save();
	void load();


	//툴박스 업데이트
	void toolBoxUpdate();

	//지형 세터
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objectSelect(int frameX, int frameY);

	maptool() {}
	~maptool() {}
};

