#pragma once
#include "gameNode.h"
#include "tileNode.h"
class maptool : public gameNode
{
private:
	tagTile sTile[TILEX * TILEY];
	tagSampleTile sSampleTile[SAMPLETILEX * SAMPLETILEY];
	tagCurrentTile sCurrentTile;



	CTRL ctrlSelect;


public:
	HRESULT init();
	void release();
	void update();
	void render();


	maptool() {}
	~maptool() {}
};

