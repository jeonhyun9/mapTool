#pragma once
#include "singletonBase.h"
enum enemyCatagory
{
	BOSS,
	GREEN_TURTLE,
	BLUE_TURTLE,
	WING_TURTLE,
	DOCHI,
	MUSHROOM,
	GREEN_FLOWER,
	BLUE_FLOWER,
	GREY_BIRD,
	RED_BIRD,
	GREEN_BIRD,
	GREY_BEAN,
	BLACK_BEAN,
	BLUE_BEAN,
};


struct tagEnemy
{
	enemyCatagory category;
	POINT ptStart;
};



class DataManager : public singletonBase <DataManager>
{
private:
	vector<tagEnemy> vEnemy;
	tagEnemy sEnemy;

public:
	HRESULT init();
	void release();
	
	void setEnemy(enemyCatagory _category, float x, float y);
	vector<tagEnemy> getEnemy() { return vEnemy; }

	DataManager() {}
	~DataManager() {}
};

