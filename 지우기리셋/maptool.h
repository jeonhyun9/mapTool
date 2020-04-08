#pragma once
#include "gameNode.h"
#include "tileNode.h"

class maptool : public gameNode
{
private:
	tagTile sTile[TILEX * TILEY];
	tagSampleTile sSampleTile_1[SAMPLETILEX * SAMPLETILEY];
	tagSampleTile sSampleTile_2[SAMPLETILEX * SAMPLETILEY];
	tagSampleTile sSampleTile_3[SAMPLETILEX * SAMPLETILEY];
	tagSampleTile sSampleTile_4[SAMPLETILEX * SAMPLETILEY];
	tagCurrentTile sCurrentTile;
	tagToolBox sToolBox;
	tagToolBtn sToolBtn;

	image* imgTile;

	CTRL ctrlSelect;


	RECT rcPagePointer;



	//드래그용 변수
	bool isDrag;
	RECT dragRc;
	float saveX, saveY;
	//end of 드래그용

	//버튼클릭이미지 렌더용			//불변수 추가
	bool isSave;
	bool isLoad;
	bool isObject;
	bool isTerrain;
	bool isDragBox;
	bool isErase;
	bool isReset;

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

