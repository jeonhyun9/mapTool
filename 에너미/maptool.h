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
	bool isRightPonterClick;
	bool isDragClick;
	bool isPlayerClick;
	bool isEnemyClick;
	bool isExitClick;
	
	//툴박스 렉트
	RECT rcToolCamera;			//툴박스 왼쪽편 블럭 인터섹트렉트용 카메라렉트 - 이준

	//임시 연우 0409
	bool isToolboxClick;

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

