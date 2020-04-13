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
	
	//���ڽ� ��Ʈ
	RECT rcToolCamera;			//���ڽ� ������ �� ���ͼ�Ʈ��Ʈ�� ī�޶�Ʈ - ����

	//�ӽ� ���� 0409
	bool isToolboxClick;

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

