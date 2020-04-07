#pragma once

//����ȭ�� Ÿ��
#define TILESIZE 32
#define TILEX 50
#define TILEY 30
#define TILESIZEX (TILEX * TILESIZE)
#define TILESIZEY (TILEY * TILESIZE)

//�̹��� Ÿ��(ȭ�� ������ܿ� �ٿ����� ����Ÿ��)
#define SAMPLETILEX 14
#define SAMPLETILEY 10

//�������� ����� ��Ʈ�ѵ�
enum CTRL
{
	CTRL_SAVE, CTRL_LOAD, CTRL_DRAG,
	CTRL_TERRAIN, CTRL_OBJECT, CTRL_ERASER,
	CTRL_MAP1, CTRL_MAP2, CTRL_MAP3, CTRL_END
};

//����
enum TERRAIN
{
	TR_CEMENT, TR_GROUND, TR_GRASS, TR_WATER, TR_END
};

//������Ʈ
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_TANK1, OBJ_TANK2,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_NONE
};

//Ÿ�ϱ���ü
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;
	image* img;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
};

//�̹��� Ÿ�� ����ü
struct tagSampleTile
{
	RECT rc;
	int terrainFrameX;
	int terrainFrameY;
};

//����Ÿ�� ����ü
struct tagCurrentTile
{
	int x, y;
};

//�� ��ư ����ü
struct tagToolButton
{
	RECT rcSave;
	RECT rcDelete;
	RECT rcReset;
	RECT rcLoad;
};

//���ڽ� ����ü
struct tagToolBox
{
	RECT rcBack;
	RECT rcPage;

	float width;
	float height;
	float pageWidth;
	float pageHeight;

	int moveSpeed;

	float x;
	float y;

	bool toggle;
};

//����ư ����ü
struct tagToolBtn
{
	RECT rcSave;
	RECT rcDelete;
	RECT rcReset;
	RECT rcLoad;

	image* imaSave;
	image* imgDelete;
	image* imgReset;
	image* imgLoad;

	float width;
	float height;
};