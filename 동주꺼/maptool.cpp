#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//Ÿ�ϸ� �̹��� �ʱ�ȭ
	//�̹��� ���� �Ϲٲ� - ���� (����ʵ� Ȯ�� ���)
	terrainImg = IMAGEMANAGER->findImage("����Ÿ��_����");
	terrainImgMini = IMAGEMANAGER->findImage("����Ÿ��_���չ̴�");

	objectImg = IMAGEMANAGER->findImage("������ƮŸ��_����");
	objectImgMini = IMAGEMANAGER->findImage("������ƮŸ��_���չ̴�");

	enemyImg = IMAGEMANAGER->findImage("���ʹ�Ÿ��_����"); //���ʹ� Ÿ�� �̹��� �߰� -���� 0409 
	//enemyImgMini = IMAGEMANAGER->findImage("���ʹ�Ÿ��_���չ̴�"); //���ʹ� �̴�Ÿ�� �̹��� �߰� -���� 0409

	toolBoxImg = IMAGEMANAGER->findImage("���ڽ�");
	buttonEraserImg = IMAGEMANAGER->findImage("��ư_�̷�����");
	buttonLoadImg = IMAGEMANAGER->findImage("��ư_�ε�");
	buttonResetImg = IMAGEMANAGER->findImage("��ư_����");
	buttonSaveImg = IMAGEMANAGER->findImage("��ư_���̺�");
	buttonTerrainImg = IMAGEMANAGER->findImage("��ư_����");
	buttonObjectImg = IMAGEMANAGER->findImage("��ư_������Ʈ");
	buttonDragImg = IMAGEMANAGER->findImage("��ư_�巡��");
	buttonPlayerImg = IMAGEMANAGER->findImage("��ư_�÷��̾�");
	buttonEnemyImg = IMAGEMANAGER->findImage("��ư_���ʹ�");
	buttonExitImg = IMAGEMANAGER->findImage("��ư_����Ʈ");

	buttonEraserOnImg = IMAGEMANAGER->findImage("��ư_�̷�������");
	buttonLoadOnImg = IMAGEMANAGER->findImage("��ư_�ε��");
	buttonResetOnImg = IMAGEMANAGER->findImage("��ư_���¿�");
	buttonSaveOnImg = IMAGEMANAGER->findImage("��ư_���̺��");
	buttonTerrainOnImg = IMAGEMANAGER->findImage("��ư_������");
	buttonObjectOnImg = IMAGEMANAGER->findImage("��ư_������Ʈ��");
	buttonDragOnImg = IMAGEMANAGER->findImage("��ư_�巡�׿�");
	buttonPlayerOnImg = IMAGEMANAGER->findImage("��ư_�÷��̾��");
	buttonEnemyOnImg = IMAGEMANAGER->findImage("��ư_���ʹ̿�");
	buttonExitOnImg = IMAGEMANAGER->findImage("��ư_����Ʈ��");

	buttonLeftImg = IMAGEMANAGER->findImage("��ư_����ȭ��ǥ");
	buttonRightImg = IMAGEMANAGER->findImage("��ư_������ȭ��ǥ");

	buttonLeftOnImg = IMAGEMANAGER->findImage("��ư_����ȭ��ǥ��");
	buttonRightOnImg = IMAGEMANAGER->findImage("��ư_������ȭ��ǥ��");

	mapToolBgImg = IMAGEMANAGER->findImage("��׶���");
	miniMapImg = IMAGEMANAGER->findImage("�̴ϸ�");

	//���ʹ� �̹��� find �ϱ� -���� 0410
	bossImg = IMAGEMANAGER->findImage("����");
	bossAttackImg = IMAGEMANAGER->findImage("��������");
	greenTurtleImg = IMAGEMANAGER->findImage("�ʷϰź�");
	blueTurtleImg = IMAGEMANAGER->findImage("�Ķ��ź�");
	wingTurtleImg = IMAGEMANAGER->findImage("�����ź�");
	dochiImg = IMAGEMANAGER->findImage("��ġ");
	mushroomImg = IMAGEMANAGER->findImage("����");
	greenFlowerImg = IMAGEMANAGER->findImage("�ʷϲ�");
	blueFlowerImg = IMAGEMANAGER->findImage("�Ķ���");
	greyBirdImg = IMAGEMANAGER->findImage("ȸ����");
	greenBirdImg = IMAGEMANAGER->findImage("�ʷϻ�");
	redBirdImg = IMAGEMANAGER->findImage("������");
	greyBeanImg = IMAGEMANAGER->findImage("ȸ�������");
	blueBeanImg = IMAGEMANAGER->findImage("�Ķ������");
	blackBeanImg = IMAGEMANAGER->findImage("���������");
	leftBulletImg = IMAGEMANAGER->findImage("������ź");
	rightBulletImg = IMAGEMANAGER->findImage("��������ź");
	cannonImg = IMAGEMANAGER->findImage("ĳ��");



	



	//����Ÿ�� �ʱ�ȭ
	sCurrentTile.x = 12; 
	sCurrentTile.y = 10; 
	sToolBox.moveSpeed = 5;
	sToolBox.toggle = false;
	sToolBox.selectedPage = 1;

	//Ÿ�� �¾�
	this->tileSetup();

	//�ʱ� ���� �� = ����
	ctrlSelect = CTRL_TERRAIN;

	//�巡�� �ʱ�ȭ
	isDrag = false;
	saveX = saveY = 0;

	//�������� ��Ʈ
	rcWins = RectMake(0, 0, WINSIZEX, WINSIZEY);
	//��׶��� ��Ʈ
	rcBg = RectMake(0, 0, 6000, 960);     
	//�̴ϸ� ��Ʈ
	rcMini = RectMake(0, 0, 600, 96); 
	rcMcamera = RectMake(0, 0, 160, 96);


	//��ư�ڽ�Ŭ�� - ��ưŬ�������� �̹������� �Һ���
	isSaveClick = false;
	isLoadClick = false;
	isObjectClick = false;
	isTerrainClick = false;
	isDragClick = false;
	isEraserClick = false;
	isResetClick = false;
	isLeftPointerClick = false;
	isRightPointerClick = false;
	isEnemyClick = false;
	isPlayerClick = false;
	isExitClick = false;

	dragRc = RectMake(-10, -10, 1, 1);


	//EX
	//DATAMANAGER->setEnemy();
	
	return S_OK;
}

void maptool::release()
{
}

void maptool::update()
{
	this->toolBoxUpdate();
	//Z ���� �� �巡��
	if (isDragClick==true)
	{
		if (INPUT->GetKeyDown(VK_LBUTTON))
		{
			//Ÿ�� ���� ���� �巡�� �����϶� �ȵǼ� �巡�׿� �߰��� - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (sToolBox.toggle == false)continue; //���Ű �ȴ����� �浹ó���� ���� �ʴ´�.
				if (PtInRect(&sSampleTile[i].rc, _ptMouse))
				{
					RECT rcTemp3;
					if (IntersectRect(&rcTemp3, &rcToolCamera, &sSampleTile[i].rc))
					{
						if (ctrlSelect == CTRL_TERRAIN)
						{
							sCurrentTile.x = sSampleTile[i].terrainFrameX;
							sCurrentTile.y = sSampleTile[i].terrainFrameY;
						}
						if (ctrlSelect == CTRL_OBJECT)
						{
							sCurrentTile.x = sSampleTile[i].objFrameX;
							sCurrentTile.y = sSampleTile[i].objFrameY;
						}
						break;
					}
				}
			}

			isDrag = true;
			saveX = _ptMouse.x;
			saveY = _ptMouse.y;

			if (PtInRect(&sToolBtn.rcSave, _ptMouse))
			{
				isSaveClick = true;		//�߰� ���̺괭������ �̹��� ��������
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoadClick = true;		//�߰� �ε崭������ �̹��� ��������
				this->load();
			}

			if (PtInRect(&sToolBtn.rcEraser, _ptMouse))
			{
				if (isEraserClick == false)		//�߰� �̷����� �������� �̹��� ��������
				{
					isEraserClick = true;
					ctrlSelect = CTRL_ERASER;
				}
				else
				{
					isEraserClick = false;		//�̷������� �ٽ� �����ָ� Ǯ��
					if (isTerrainClick)			//����¯ �̷����� ����ó�� �巡��
					{
						ctrlSelect = CTRL_TERRAIN;
					}
					else if (isObjectClick)
					{
						ctrlSelect = CTRL_OBJECT;
					}
				}
			}
			//�Ʒ� 5�� ���� �߰� �ȵǾ��־ �巡�� ���¿����� ��ư�� ������ �ʾƼ� �߰��ص��� - ����
			if (PtInRect(&sToolBtn.rcLeftPointer, _ptMouse) && sToolBox.selectedPage >= 2)
			{
				isLeftPointerClick = true;
				sToolBox.selectedPage--;
			}
			if (PtInRect(&sToolBtn.rcRightPointer, _ptMouse) && sToolBox.selectedPage < 4)
			{
				isRightPointerClick = true;
				sToolBox.selectedPage++;
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				isTerrainClick = true;
				isObjectClick = false; //������Ʈ ���� ��ȯ -���� 
				isEnemyClick = false;//���� 0409
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				isObjectClick = true;
				isTerrainClick = false; //�ͷ��� ���� ��ȯ -����
				isEnemyClick = false;
				ctrlSelect = CTRL_OBJECT;
			}
			if (PtInRect(&sToolBtn.rcReset, _ptMouse))		
			{
				isResetClick = true;
				isEraserClick = false;
				ctrlSelect = CTRL_RESET;
			}
			if (PtInRect(&sToolBtn.rcPlayer, _ptMouse))
			{
				isPlayerClick = true;
			}
			if (PtInRect(&sToolBtn.rcEnemy, _ptMouse))
			{
				isEnemyClick = true; //���� 0409
				isObjectClick = false; //���� 0409
				isTerrainClick = false; //���� 0409
				ctrlSelect = CTRL_ENEMY; //���� 0409
			}
			if (PtInRect(&sToolBtn.rcDrag, _ptMouse))
			{
				if (isDragClick == false)
				{
					isDragClick = true;
				}
				else if(isDragClick == true)
				{
					isDragClick = false;
				}
			}
			if (PtInRect(&sToolBtn.rcExit, _ptMouse))
			{
				isExitClick = true;
				SCENEMANAGER->loadScene("�޴�"); 
			}
		}
		if (INPUT->GetKey(VK_LBUTTON))
		{
			dragRc = RectMake(saveX, saveY, (_ptMouse.x - saveX), (_ptMouse.y - saveY));
		}

		if (INPUT->GetKeyUp(VK_LBUTTON))		//��Ű������ �������� true �� fasleó�����ֱ�
		{
			isDrag = false;
			isSaveClick = false;
			isLoadClick = false;
			isResetClick = false;
			isPlayerClick = false;
			//isEnemyClick = false;
			isExitClick = false;
			isLeftPointerClick = false;  //���� 0409 
			isRightPointerClick = false;
		}
	}
	else
	{
		//��Ŭ���� �ش� ��ġ�� ���õ� Ÿ�� �׸���
		if (INPUT->GetKey(VK_LBUTTON)) this->setMap();

		//��ư Ŭ�� �浹 ó��
		if (INPUT->GetKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&sToolBtn.rcSave, _ptMouse))
			{
				isSaveClick = true;		//�߰� ���̺� �������� �̹��� ��������
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoadClick = true;		//�߰� �ε� �������� �̹��� ��������
				this->load();
			}

			if (PtInRect(&sToolBtn.rcEraser, _ptMouse))
			{
				if (isEraserClick == false)		//�߰� �̷����� �������� �̹��� ��������
				{
					isEraserClick = true;
					ctrlSelect = CTRL_ERASER;
				}
				else
				{
					isEraserClick = false;		//�̷������� �ٽ� �����ָ� Ǯ��
					if (isTerrainClick)			//����¯ �̷����� ����ó��
					{
						ctrlSelect = CTRL_TERRAIN;
					}
					else if (isObjectClick)
					{
						ctrlSelect = CTRL_OBJECT;
					}
				}
				
			}

			if (PtInRect(&sToolBtn.rcLeftPointer, _ptMouse) && sToolBox.selectedPage >= 2)
			{
				isLeftPointerClick = true;
				sToolBox.selectedPage--;
			}
			if (PtInRect(&sToolBtn.rcRightPointer, _ptMouse) && sToolBox.selectedPage < 4)
			{
				isRightPointerClick = true;
				sToolBox.selectedPage++;

				//���ʹ� �̳� �����ϋ� ���������� ���Ѿ�� ����ó�� -���� 
				if (ctrlSelect == CTRL_ENEMY)
				{
					sToolBox.selectedPage = 1;
				}
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				isTerrainClick = true;
				isObjectClick = false;
				isEnemyClick = false;
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				isObjectClick = true;
				isTerrainClick = false;//�ӽ��߰�
				isEnemyClick = false;
				ctrlSelect = CTRL_OBJECT;
			}
			if (PtInRect(&sToolBtn.rcReset, _ptMouse))		//���¹�ư���� ��Ƽ�η�����
			{
				isResetClick = true;
				isEraserClick = false;
				ctrlSelect = CTRL_RESET;
			}
			if (PtInRect(&sToolBtn.rcPlayer, _ptMouse))
			{
				isPlayerClick = true;
			}
			if (PtInRect(&sToolBtn.rcEnemy, _ptMouse))
			{
				isEnemyClick = true; //���� 0409
				isObjectClick = false; //���� 0409
				isTerrainClick = false; //���� 0409
				ctrlSelect = CTRL_ENEMY; //���� 0409
			}
			if (PtInRect(&sToolBtn.rcDrag, _ptMouse))
			{
				if (isDragClick == false)
				{
					isDragClick = true;
				}
				else if (isDragClick == true)
				{
					isDragClick = false;
				}
			}
			if (PtInRect(&sToolBtn.rcExit, _ptMouse))
			{
				isExitClick = true;
				SCENEMANAGER->loadScene("�޴�");
			}
		}
		if (INPUT->GetKeyUp(VK_LBUTTON))					//���̺�,�ε�,���¹�ư false ��Ű�� �߰�
		{
			isSaveClick = false;
			isLoadClick = false;
			isResetClick = false;
			//isTerrain = false;
			//isObject = false;
			isLeftPointerClick = false;
			isRightPointerClick = false;
			isPlayerClick = false;
			//isEnemyClick = false;
			isExitClick = false;
		}
	}

	//Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sTile[i * TILEX + j].rc = RectMake(rcBg.left + j * TILESIZE, rcBg.top + i * TILESIZE, TILESIZE, TILESIZE);
		}
	}

	//�̴ϸ� Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sMiniTile[i * TILEX + j].rc = RectMake(rcMini.left + j * (TILESIZE / 10 + 0.2f), rcMini.top + i * (TILESIZE / 10 + 0.2f), TILESIZE / 10, TILESIZE / 10);
		}
	}

	//���ʹ� Ÿ�� ��Ʈ �ʱ�ȭ -����,���� 0410
	sEnemyTile.rcGreyBean = RectMake(sSampleTile[0].rc.left, sSampleTile[0].rc.top, 64, 64);
	sEnemyTile.rcBlackBean = RectMake(sSampleTile[2].rc.left, sSampleTile[2].rc.top, 64, 64);
	sEnemyTile.rcBlueBean = RectMake(sSampleTile[4].rc.left, sSampleTile[4].rc.top, 64, 64);
	sEnemyTile.rcGreyBird = RectMake(sSampleTile[112].rc.left, sSampleTile[112].rc.top, 64, 64);
	sEnemyTile.rcGreenBird = RectMake(sSampleTile[114].rc.left, sSampleTile[114].rc.top, 64, 64);
	sEnemyTile.rcRedBird = RectMake(sSampleTile[116].rc.left, sSampleTile[116].rc.top, 64, 64);
	sEnemyTile.rcDoChi = RectMake(sSampleTile[224].rc.left, sSampleTile[224].rc.top, 64, 64);
	sEnemyTile.rcMushroom = RectMake(sSampleTile[226].rc.left, sSampleTile[226].rc.top, 64, 64);
	sEnemyTile.rcBlueFlower = RectMake(sSampleTile[6].rc.left, sSampleTile[6].rc.top, 64, 96);
	sEnemyTile.rcGreenFlower = RectMake(sSampleTile[8].rc.left, sSampleTile[8].rc.top, 64, 96);
	sEnemyTile.rcWingTurtle = RectMake(sSampleTile[12].rc.left, sSampleTile[12].rc.top, 64, 96);
	sEnemyTile.rcBlueTurtle = RectMake(sSampleTile[392].rc.left, sSampleTile[392].rc.top, 64, 96);
	sEnemyTile.rcGreenTurtle = RectMake(sSampleTile[394].rc.left, sSampleTile[394].rc.top, 64, 96);
	sEnemyTile.rcBoss = RectMake(sSampleTile[340].rc.left, sSampleTile[340].rc.top, 128, 128);
	sEnemyTile.rcRightBullet = RectMake(sSampleTile[346].rc.left, sSampleTile[346].rc.top, 64, 64);
	sEnemyTile.rcLeftBullet = RectMake(sSampleTile[458].rc.left, sSampleTile[458].rc.top, 64, 64);
	sEnemyTile.rcCannon = RectMake(sSampleTile[348].rc.left, sSampleTile[348].rc.top, 64, 128);




	if (INPUT->GetKey('D'))
	{
		dragRc = RectMake(-10, -10, 1, 1);
		if (WINSIZEX >= rcBg.right)
		{
			rcBg.right = WINSIZEX;
		}
		else
		{
			rcBg.left -= 20;
			rcBg.right -= 20;
			rcMcamera.left += 2;
			rcMcamera.right += 2;
		}
	}
	if (INPUT->GetKey('A'))
	{
		dragRc = RectMake(-10, -10, 1, 1);
		if (0 <= rcBg.left)
		{
			rcBg.left = 0;
		}
		else
		{
			rcBg.left += 20;
			rcBg.right += 20;
			rcMcamera.left -= 2;
			rcMcamera.right -= 2;
		}
	}

	if (ctrlSelect == CTRL_RESET)					//���� ���� �߰�
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			//���� ���� �߰� -����

			//Ÿ�� ���� Ʈ���� ����
				sTile[i].terrainFrameX = 10;
				sTile[i].terrainFrameY = 9;
				sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
				ctrlSelect = CTRL_TERRAIN;
			//Ÿ�� ���� ������Ʈ ����
				sTile[i].objFrameX = 10;
				sTile[i].objFrameY = 9;
				sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
				ctrlSelect = CTRL_OBJECT;

			//�̴ϸ� Ÿ�� ���� ���� �߰� - ���� 
				
			//�̴ϸ� Ʈ���� ����
			sMiniTile[i].terrainFrameX = 12;
			sMiniTile[i].terrainFrameY = 10;
			sMiniTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
			ctrlSelect = CTRL_TERRAIN;
				
			//�̴ϸ� ������Ʈ ����
			sMiniTile[i].objFrameX = 12;
			sMiniTile[i].objFrameY = 10;
			sMiniTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
			ctrlSelect = CTRL_OBJECT;
		}
	}
	//���ڽ� ī�޶� ��Ʈ�߰� - ����
	rcToolCamera = RectMake(sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 448, 320);
}

void maptool::render()
{

	mapToolBgImg->render(getMemDC(), rcBg.left, rcBg.top);
	miniMapImg->render(getMemDC(), rcMini.left, rcMini.top);
	FrameRect(getMemDC(), rcMini, RGB(0, 0, 0));
	FrameRect(getMemDC(), rcMcamera, RGB(255, 0, 0));

	//�ΰ���ȭ�� ������ �׸���
	RECT rcTemp;
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&rcTemp, &rcWins, &sTile[i].rc))
		{
			terrainImg->frameRender(getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
				sTile[i].terrainFrameX, sTile[i].terrainFrameY);
			//������ ���� �̹��� ���� -���� 
			terrainImgMini->frameRender(getMemDC(), sMiniTile[i].rc.left, sMiniTile[i].rc.top,
				sMiniTile[i].terrainFrameX, sMiniTile[i].terrainFrameY);

			objectImg->frameRender(getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
				sTile[i].objFrameX, sTile[i].objFrameY);

			objectImgMini->frameRender(getMemDC(), sMiniTile[i].rc.left, sMiniTile[i].rc.top,
				sMiniTile[i].objFrameX, sMiniTile[i].objFrameY);
		}
	}

	//���ʹ� �ΰ��� ȭ�� �׸��� -����,���� 0410 
	//RECT rcTemp2;
	//for (int i = 0; i < TILEX * TILEY; i++)
	//{
	//	if (IntersectRect(&rcTemp2, &sEnemyTile.rcBlackBean, &sTile[i].rc))
	//	{
	//
	//	}
	//}
	if (isDrag)
	{
		//�Ʒ� ���� �巡�� ���� ��Ƶа� - ���� (���� ������� ��ǲ���� �مf��)
		if (INPUT->GetKey(VK_LBUTTON))
		{
			FrameRect(getMemDC(), dragRc, RGB(255, 0, 0));
		}

		if (INPUT->GetKeyUp(VK_LBUTTON))
		{
			//�ΰ���ȭ�� ��ƮƲ�� �浹�߳�?
			RECT _tempRc;
			for (int i = 0; i < TILEX * TILEY; i++)
			{
				if (IntersectRect(&_tempRc, &sTile[i].rc, &dragRc))
				{
					//�����ư�� �����̳�?
					if (ctrlSelect == CTRL_TERRAIN)
					{
						sTile[i].terrainFrameX = sCurrentTile.x;
						sTile[i].terrainFrameY = sCurrentTile.y;
						sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);

						sMiniTile[i].terrainFrameX = sCurrentTile.x;
						sMiniTile[i].terrainFrameY = sCurrentTile.y;
						sMiniTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
					}
					//�����ư�� ������Ʈ��?
					if (ctrlSelect == CTRL_OBJECT)
					{
						sTile[i].objFrameX = sCurrentTile.x;
						sTile[i].objFrameY = sCurrentTile.y;
						sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);

						sMiniTile[i].objFrameX = sCurrentTile.x;
						sMiniTile[i].objFrameY = sCurrentTile.y;
						sMiniTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
					}
					//�����ư�� ���찳��?
					if (ctrlSelect == CTRL_ERASER)							//�̷����� �����߰�
					{
						if (isEraserClick)
						{//�ӽ� �ּ�����
							if (isTerrainClick)
							{
								sTile[i].terrainFrameX = 10;
								sTile[i].terrainFrameY = 9;
								sMiniTile[i].terrainFrameX = 12;
								sMiniTile[i].terrainFrameY = 10;
							}
							if (isObjectClick)
							{
								sTile[i].objFrameX = 10;
								sTile[i].objFrameY = 9;
								sMiniTile[i].objFrameX = 12;
								sMiniTile[i].objFrameY = 10;
							}
						}
					}
				}
			}
		}
	}



	
	//F1 �Է½� �ΰ���ȭ�� ��Ʈ �����ֱ�
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			FrameRect(getMemDC(), sTile[i].rc, RGB(0, 0, 0));
			//FrameRect(getMemDC(), sMiniTile[i].rc, RGB(0, 255, 0));
			//Rectangle(getMemDC(), sSampleTile[i].rc);
		}
	}

	if (INPUT->GetToggleKey(VK_F3))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			FrameRect(getMemDC(), sMiniTile[i].rc, RGB(0, 255, 0));
		}
	}
	
	//F2 �Է½� ���ڽ� + ������ + ��ư ��Ʈ �����ֱ�
	if (INPUT->GetToggleKey(VK_F2))
	{
		//Rectangle(getMemDC(), sToolBox.rcBack);
		toolBoxImg->render(getMemDC(), sToolBox.rcBack.left - 15, sToolBox.rcBack.top -15);
		//Rectangle(getMemDC(), sToolBox.rcPage);
		//Rectangle(getMemDC(), sToolBtn.rcLoad);
		buttonLoadImg->render(getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		//Rectangle(getMemDC(), sToolBtn.rcSave);
		buttonSaveImg->render(getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		//Rectangle(getMemDC(), sToolBtn.rcReset);
		buttonResetImg->render(getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		//Rectangle(getMemDC(), sToolBtn.rcDelete);
		buttonEraserImg->render(getMemDC(), sToolBtn.rcEraser.left, sToolBtn.rcEraser.top);
		//Rectangle(getMemDC(), sToolBtn.rcTerrain);
		buttonTerrainImg->render(getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		//Rectangle(getMemDC(), sToolBtn.rcObject);
		buttonObjectImg->render(getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		//Rectangle(getMemDC(), sToolBtn.rcDrag);
		buttonDragImg->render(getMemDC(), sToolBtn.rcDrag.left, sToolBtn.rcDrag.top);
		//Rectangle(getMemDC(), sToolBtn.rcPlayer);
		buttonPlayerImg->render(getMemDC(), sToolBtn.rcPlayer.left, sToolBtn.rcPlayer.top);
		//Rectangle(getMemDC(), sToolBtn.rcMonster);
		buttonEnemyImg->render(getMemDC(), sToolBtn.rcEnemy.left, sToolBtn.rcEnemy.top);
		//Rectangle(getMemDC(), sToolBtn.rcExit);
		buttonExitImg->render(getMemDC(), sToolBtn.rcExit.left, sToolBtn.rcExit.top);  

		//���ʹ� Ÿ�� ��Ʈ ���� -����,���� 0410
		if (INPUT->GetToggleKey('M'))
		{
			Rectangle(getMemDC(), sEnemyTile.rcGreyBean);
			Rectangle(getMemDC(), sEnemyTile.rcBlackBean);
			Rectangle(getMemDC(), sEnemyTile.rcBlueBean);
			Rectangle(getMemDC(), sEnemyTile.rcGreyBird);
			Rectangle(getMemDC(), sEnemyTile.rcGreenBird);
			Rectangle(getMemDC(), sEnemyTile.rcRedBird);
			Rectangle(getMemDC(), sEnemyTile.rcDoChi);
			Rectangle(getMemDC(), sEnemyTile.rcMushroom);
			Rectangle(getMemDC(), sEnemyTile.rcBlueFlower);
			Rectangle(getMemDC(), sEnemyTile.rcGreenFlower);
			Rectangle(getMemDC(), sEnemyTile.rcWingTurtle);
			Rectangle(getMemDC(), sEnemyTile.rcBlueTurtle);
			Rectangle(getMemDC(), sEnemyTile.rcGreenTurtle);
			Rectangle(getMemDC(), sEnemyTile.rcBoss);
			Rectangle(getMemDC(), sEnemyTile.rcRightBullet);
			Rectangle(getMemDC(), sEnemyTile.rcLeftBullet);
			Rectangle(getMemDC(), sEnemyTile.rcCannon);

		}
		

		
		//Rectangle(getMemDC(), rcToolCamera);
		RECT _rcTemp;
		switch (sToolBox.selectedPage)
		{
		case 1:
			if (ctrlSelect == CTRL_OBJECT)
			{
				objectImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 0, 0, 448, 320);
			}
			else if(ctrlSelect==CTRL_TERRAIN) // if ���� �߰� - ���� 0409
			{
				terrainImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 0, 0, 448, 320);
			}
			else if (ctrlSelect == CTRL_ENEMY) //���ʹ�Ÿ��_���� ���� -���� 0409
			{
				enemyImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 0, 0, 448, 320);
			}
			//���̽� 1~4���� ���� �߰� - Ÿ�� �׵θ� ��Ʈ ���ͼ�Ʈ��Ʈ - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (IntersectRect(&_rcTemp, &rcToolCamera, &sSampleTile[i].rc))
				{
					FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
				}
			}
			break;
		case 2:
			if (ctrlSelect == CTRL_OBJECT)
			{
				objectImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 448, 0, 448, 320);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				terrainImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 448, 0, 448, 320);
			}
			//���̽� 1~4���� ���� �߰� - Ÿ�� �׵θ� ��Ʈ ���ͼ�Ʈ��Ʈ - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (IntersectRect(&_rcTemp, &rcToolCamera, &sSampleTile[i].rc))
				{
					FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
				}
			}
			break;
		case 3:
			if (ctrlSelect == CTRL_OBJECT)
			{
				objectImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 896, 0, 448, 320);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				terrainImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 896, 0, 448, 320);
			}
			//���̽� 1~4���� ���� �߰� - Ÿ�� �׵θ� ��Ʈ ���ͼ�Ʈ��Ʈ - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (IntersectRect(&_rcTemp, &rcToolCamera, &sSampleTile[i].rc))
				{
					FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
				}
			}
			break;
		case 4:
			if (ctrlSelect == CTRL_OBJECT)
			{
				objectImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 1344, 0, 448, 320);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				terrainImg->render(getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 1344, 0, 448, 320);
			}
			//���̽� 1~4���� ���� �߰� - Ÿ�� �׵θ� ��Ʈ ���ͼ�Ʈ��Ʈ - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (IntersectRect(&_rcTemp, &rcToolCamera, &sSampleTile[i].rc))
				{
					FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
				}
			}
			break;
		}

		//�������� ��ư ��ȯ ���� �߰�
		if (isLoadClick)
		{
			buttonLoadOnImg->render(getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		}
		if (isSaveClick)
		{
			buttonSaveOnImg->render(getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		}
		if (isResetClick)
		{
			buttonResetOnImg->render(getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		}
		if (isEraserClick)
		{
			buttonEraserOnImg->render(getMemDC(), sToolBtn.rcEraser.left, sToolBtn.rcEraser.top);
		}
		if (isObjectClick)
		{
			buttonObjectOnImg->render(getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		}
		if (isTerrainClick)
		{
			buttonTerrainOnImg->render(getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		}
		if (isDragClick)
		{
			buttonDragOnImg->render(getMemDC(), sToolBtn.rcDrag.left, sToolBtn.rcDrag.top);
		}
		if (isPlayerClick)
		{
			buttonPlayerOnImg->render(getMemDC(), sToolBtn.rcPlayer.left, sToolBtn.rcPlayer.top);
		}
		if (isEnemyClick)
		{
			buttonEnemyOnImg->render(getMemDC(), sToolBtn.rcEnemy.left, sToolBtn.rcEnemy.top);
		}
		if (isExitClick)
		{
			buttonExitOnImg->render(getMemDC(), sToolBtn.rcExit.left, sToolBtn.rcExit.top);
		}

		//ȭ��ǥ �̹��� Ŭ���� ����
		if (isLeftPointerClick)
		{
			buttonLeftOnImg->render(getMemDC(), sToolBtn.rcLeftPointer.left, sToolBtn.rcLeftPointer.top);
		}
		else
		{
			//Rectangle(getMemDC(), sToolBtn.rcLeftPointer);
			buttonLeftImg->render(getMemDC(), sToolBtn.rcLeftPointer.left, sToolBtn.rcLeftPointer.top);
		}
		if (isRightPointerClick)
		{
			buttonRightOnImg->render(getMemDC(), sToolBtn.rcRightPointer.left, sToolBtn.rcRightPointer.top);
		}
		else
		{
			//Rectangle(getMemDC(), sToolBtn.rcRightPointer);
			buttonRightImg->render(getMemDC(), sToolBtn.rcRightPointer.left, sToolBtn.rcRightPointer.top);
		}

		//���ڽ� ǥ�õǾ� ���� �� ȭ��ǥ �Է½� ���ڽ� �����¿� �̵�
		if (INPUT->GetKey(VK_LEFT))
		{
			sToolBox.x -= sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_RIGHT))
		{
			sToolBox.x += sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_UP))
		{
			sToolBox.y -= sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_DOWN))
		{
			sToolBox.y += sToolBox.moveSpeed;
		}

		sToolBox.toggle = true;
	}
	else
	{
		sToolBox.toggle = false;
	}


}

void maptool::tileSetup()
{
	//���ڽ� �ʱ�ȭ
	sToolBox.toggle = false;
	sToolBox.x = WINSIZEX/2;
	sToolBox.y = 670;
	sToolBox.width = 1000;
	sToolBox.height = 400;

	//������ �ʱ�ȭ
	sToolBox.pageWidth = 480;
	sToolBox.pageHeight = 400;

	//����ư �ʱ�ȭ
	sToolBtn.width = 173;
	sToolBtn.height = 53;

	//����Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{	
			sSampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			sSampleTile[i * SAMPLETILEX + j].terrainFrameY = i;
			sSampleTile[i * SAMPLETILEX + j].objFrameX = j;
			sSampleTile[i * SAMPLETILEX + j].objFrameY = i;
		}
	}

	//Ÿ���� �ʱ�ȭ�� 
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		sTile[i].terrainFrameX = 10; //���� Ÿ�� X��ǥ
		sTile[i].terrainFrameY = 8; //���� Ÿ�� Y��ǥ
		sTile[i].objFrameX = 0; //������Ʈ Ÿ�� X��ǥ
		sTile[i].objFrameY = 0; //������Ʈ Ÿ�� Y��ǥ
		sTile[i].terrain = terrainSelect(sTile[i].terrainFrameX, sTile[i].terrainFrameY); //�ش� X,Y ��ǥ �� ���� Ÿ�� ����
		//sTile[i].obj = OBJ_NONE; //������Ʈ ���þ��� ����
	}
}

void maptool::setMap()
{
	RECT _rcTemp2;
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
	{
		if (sToolBox.toggle == false)continue; //���Ű �ȴ����� �浹ó���� ���� �ʴ´�.
		if (PtInRect(&sSampleTile[i].rc, _ptMouse))
		{
			//���ڽ� ������Ʈ ���ͼ��ͷ�Ʈ ����ó�� - ����
			if (IntersectRect(&_rcTemp2, &rcToolCamera, &sSampleTile[i].rc))
			{
				if (ctrlSelect == CTRL_TERRAIN)
				{
					sCurrentTile.x = sSampleTile[i].terrainFrameX;
					sCurrentTile.y = sSampleTile[i].terrainFrameY;
				}
				if (ctrlSelect == CTRL_OBJECT)
				{
					sCurrentTile.x = sSampleTile[i].objFrameX;
					sCurrentTile.y = sSampleTile[i].objFrameY;
				}
			}
			break;
		}

	}

	//�ΰ���ȭ�� ��ƮƲ�� �浹�߳�?
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&sTile[i].rc, _ptMouse))
		{
			if (PtInRect(&sToolBox.rcBack, _ptMouse) && sToolBox.toggle == true)continue; //��� �ڽ� ���� ������ �浹ó���� ���� �ʴ´�.
			//�����ư�� �����̳�?
			if (ctrlSelect == CTRL_TERRAIN)
			{
				sTile[i].terrainFrameX = sCurrentTile.x;
				sTile[i].terrainFrameY = sCurrentTile.y;
				sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);

				sMiniTile[i].terrainFrameX = sCurrentTile.x;
				sMiniTile[i].terrainFrameY = sCurrentTile.y;
				sMiniTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//�����ư�� ������Ʈ��?
			if (ctrlSelect == CTRL_OBJECT)
			{
				sTile[i].objFrameX = sCurrentTile.x;
				sTile[i].objFrameY = sCurrentTile.y;
				sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);

				sMiniTile[i].objFrameX = sCurrentTile.x;
				sMiniTile[i].objFrameY = sCurrentTile.y;
				sMiniTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//�����ư�� ���찳��?
			if (ctrlSelect == CTRL_ERASER)							//�̷����� �����߰�
			{
				if (isEraserClick)
				{
					if (isTerrainClick)//�ӽ��ּ�
					{
						sTile[i].terrainFrameX = 10;
						sTile[i].terrainFrameY = 9;
						sMiniTile[i].terrainFrameX = 12;
						sMiniTile[i].terrainFrameY = 10;
					}
					if (isObjectClick)//�ӽ��ּ�
					{
						sTile[i].objFrameX = 10;
						sTile[i].objFrameY = 9;
						sMiniTile[i].objFrameX = 12;
						sMiniTile[i].objFrameY = 10;
					}
				}
			}
			
		}
	}
}

void maptool::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("save.map", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, sTile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	CloseHandle(file);
}

void maptool::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("save.map", GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, sTile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);
}


void maptool::toolBoxUpdate()
{
	//���ڽ� ��� ��Ʈ ����
	sToolBox.rcBack = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//���ڽ� ������ ��Ʈ ����
	sToolBox.rcPage = RectMake(sToolBox.rcBack.left, sToolBox.rcBack.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//���ڽ� ��ư ��Ʈ ����
	//���� ��ư��
	sToolBtn.rcTerrain = RectMake(sToolBox.x + 10, sToolBox.y - 158, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcPlayer = RectMake(sToolBox.x + 10, sToolBox.y - 88, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcEraser = RectMake(sToolBox.x + 10, sToolBox.y - 18, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 10, sToolBox.y + 52, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 10, sToolBox.y + 122, sToolBtn.width, sToolBtn.height);

	//������ ��ư��
	sToolBtn.rcObject = RectMake(sToolBox.x + 225, sToolBox.y - 158, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcEnemy = RectMake(sToolBox.x + 225, sToolBox.y - 88, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcDrag = RectMake(sToolBox.x + 225, sToolBox.y - 18, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 225, sToolBox.y + 52, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcExit = RectMake(sToolBox.x + 225, sToolBox.y + 122, sToolBtn.width, sToolBtn.height);

	//ȭ��ǥ
	sToolBtn.rcLeftPointer = RectMake(sToolBox.x - 315, sToolBox.y + 140, 50, 50);
	sToolBtn.rcRightPointer = RectMake(sToolBox.x - 255, sToolBox.y + 140, 50, 50);

	//����Ÿ�� ����� ��ġ �ٲ��ָ鼭 ��Ʈ����ũ�ؼ� ��ư��ġ ��ȭ�ֱ� - ����
	switch (sToolBox.selectedPage)
	{
	case 1:
		for (int i = 0; i < SAMPLETILEY; i++)
		{
			for (int j = 0; j < SAMPLETILEX; j++)
			{
				sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left + 15 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
			}
		}
		break;
	case 2:
		for (int i = 0; i < SAMPLETILEY; i++)
		{
			for (int j = 0; j < SAMPLETILEX; j++)
			{
				sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left - 433 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
			}
		}
		break;
	case 3:
		for (int i = 0; i < SAMPLETILEY; i++)
		{
			for (int j = 0; j < SAMPLETILEX; j++)
			{
				sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left - 881 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
			}
		}
		break;
	case 4:
		for (int i = 0; i < SAMPLETILEY; i++)
		{
			for (int j = 0; j < SAMPLETILEX; j++)
			{
				sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left - 1329 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
			}
		}
		break;
	}
}

TERRAIN maptool::terrainSelect(int frameX, int frameY)
{
	//�ø�Ʈ
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	//��
	if (frameX == 2 && frameY == 0)
	{
		return TR_GROUND;
	}
	//�ܵ�
	if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	//��
	if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}

	//��Ÿ
	return TR_GROUND;
}

OBJECT maptool::objectSelect(int frameX, int frameY)
{
	return  OBJ_BLOCKS;
}

