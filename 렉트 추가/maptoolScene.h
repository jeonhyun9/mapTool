#pragma once
#include "gameNode.h"
#include "tileNode.h"

struct mapToolButton
{
	//맵툴박스 버튼 렉트
	RECT rcSave;
	RECT rcDelete;
	RECT rcReset;
	RECT rcLoad;
};

class maptoolScene : public gameNode
{
private:
	//tagTile _tiles[TILEX * TILEY];	//인게임화면에 사용되는 타일 총 400개
	//tagSampleTile _sampleTile[SAMPLETILEX * SAMPLETILEY]; //샘플타일 총 160개
	//tagCurrentTile _currentTile;	//현재타일
	//
	//RECT _rcSave;		//세이브
	//RECT _rcLoad;		//로드
	//RECT _rcTerrain;	//지형
	//RECT _rcObject;		//오브젝트
	//RECT _rcEraser;		//지우개(오브젝트만 지운다, 지형은 덮어씌운다)
	//
	//CTRL _ctrlSelect;	//현재 어떤 컨트롤 상태인지


	//렉트
	RECT rcMap[900];
	//맵툴 박스 렉트
	RECT rcToolBox;

	//맵툴 박스 버튼 구조체 선언
	mapToolButton mapToolBtn;
	


	//기타 변수
	int rcToolBoxX;
	int rcToolBoxY;

	//맵툴 페이지 테스트
	RECT test;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	////맵툴세팅
	//void maptoolSetup();
	//void setMap();
	//void save();
	//void load();
	//
	////지형, 오브젝트 세터
	//TERRAIN terrainSelect(int frameX, int frameY);
	//OBJECT objectSelect(int frameX, int frameY);

	maptoolScene() {}
	~maptoolScene() {}
};

