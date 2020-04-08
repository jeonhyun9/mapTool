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



	//�巡�׿� ����
	bool isDrag;
	RECT dragRc;
	float saveX, saveY;
	//end of �巡�׿�

	//��ưŬ���̹��� ������			//�Һ��� �߰�
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

	//Ÿ�� �¾�
	void tileSetup();
	void setMap();

	//���̺� �ε�
	void save();
	void load();


	//���ڽ� ������Ʈ
	void toolBoxUpdate();

	//���� ����
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objectSelect(int frameX, int frameY);

	maptool() {}
	~maptool() {}
};

