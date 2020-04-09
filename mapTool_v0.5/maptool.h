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

	//�������� ��Ʈ
	RECT rcWins;
	//���ȭ�� ��Ʈ
	RECT rcBg;
	//�̴ϸ� ��Ʈ
	RECT rcMini;
	RECT rcMcamera;

	//��ưŬ���̹��� ������			//�Һ��� �߰�
<<<<<<< HEAD:mapTool_v0.5/maptool.h
	bool isSaveClick;
	bool isLoadClick;
	bool isObjectClick;
	bool isTerrainClick;
	bool isEraserClick;
	bool isResetClick;
	bool isLeftPointerClick;
	bool isRightPonterClick;
	bool isDragClick;
	bool isPlayerClick;
	bool isEnemyClick;
	bool isExitClick;



=======
	bool isSave;
	bool isLoad;
	bool isObject;
	bool isTerrain;
	bool isDragBox;
	bool isErase;
	bool isReset;
	
>>>>>>> 1e90396d34c982ff771d41cdeb1aaa66b48c7c4a:mapTool_v0.4/maptool.h
	//���ڽ� ��Ʈ
	RECT rcToolCamera;			//���ڽ� ������ �� ���ͼ�Ʈ��Ʈ�� ī�޶�Ʈ - ����

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

