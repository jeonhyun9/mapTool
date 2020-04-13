#pragma once
#include "gameNode.h"
#include "tileNode.h"
class maptool : public gameNode
{
private:
	tagTile sTile[TILEX * TILEY];
	tagTile sMiniTile[TILEX * TILEY];
	tagEnemyData sEnemyData[100];
	vector<tagEnemyData> vEnemyData[100];
	tagSampleTile sSampleTile[SAMPLETILEX * SAMPLETILEY];
	tagCurrentTile sCurrentTile;
	tagToolBox sToolBox;
	tagToolBtn sToolBtn;
	tagEnemyTile sEnemyTile; //���ʹ� Ÿ�� ��Ʈ ����ü -���� 0410

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
	bool isRightPointerClick;
	bool isDragClick;
	bool isPlayerClick;
	bool isEnemyClick;
	bool isExitClick;
	//��ư Ŭ���̹���
	image* terrainImg;
	image* terrainImgMini;

	image* objectImg;
	image* objectImgMini;

	image* enemyImg; // ���ʹ� Ÿ�� ���� �߰� - ����
	//image* enemyImgMini; // ���ʹ� �̴�Ÿ�� ���� �߰� - ����  
	int selectEnemyNum;

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

	//���ʹ� ������ �̹��� ���� -���� 0410
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

	//0413 ���� ���ʹ� �����͸� �ִ� �Լ�
	void setEnemyData(enemyCatagory _category, float _x, float _y)
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			if (sTile[i].enemy.isPushed == true)continue; //isPushed�� Ʈ���̸� ���� ����� �ִ� ���̹Ƿ� ���� �ε����� �Ѿ.
			sTile[i].enemy.category = _category;
			sTile[i].enemy.x = _x;
			sTile[i].enemy.y = _y;
			sTile[i].enemy.isPushed = true; //������ �־����Ƿ� Ʈ��� �ٲ���.
			break;
		}
	};

	void setEnemySelectRect(); //0413 ���� ���ʹ� �浹 ��Ʈ �Լ��� �ٲ�.

	//���� ����
	TERRAIN terrainSelect(int frameX, int frameY);
	OBJECT objectSelect(int frameX, int frameY);

	maptool() {}
	~maptool() {}
};

