#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//Ÿ�ϸ� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addFrameImage("����Ÿ��_����", "images/����Ÿ��_����.bmp", 1792, 320, 56, 10);
	IMAGEMANAGER->addFrameImage("����Ÿ��_���չ̴�", "images/����Ÿ��_���չ̴�.bmp", 179, 32, 56, 10);//�̴�Ÿ�� �̹��� �߰� -����

	IMAGEMANAGER->addFrameImage("����Ÿ��1", "images/����Ÿ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��2", "images/����Ÿ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��3", "images/����Ÿ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��4", "images/����Ÿ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	IMAGEMANAGER->addFrameImage("������ƮŸ��1", "images/������ƮŸ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��2", "images/������ƮŸ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��3", "images/������ƮŸ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��4", "images/������ƮŸ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	IMAGEMANAGER->addImage("���ڽ�", "images/���ڽ�.bmp", 1000, 450, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�̷�����", "images/��ư_�̷�����.bmp", 173, 57,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("��ư_�ε�", "images/��ư_�ε�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���̺�", "images/��ư_���̺�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������Ʈ", "images/��ư_������Ʈ.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�巡��", "images/��ư_�巡��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�÷��̾�", "images/��ư_�÷��̾�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���ʹ�", "images/��ư_���ʹ�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����Ʈ", "images/��ư_����Ʈ.bmp", 173, 57, true, RGB(255, 0, 255));



	IMAGEMANAGER->addImage("��ư_�̷�������", "images/��ư_�̷�������.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�ε��", "images/��ư_�ε��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���¿�", "images/��ư_���¿�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���̺��", "images/��ư_���̺��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������", "images/��ư_������.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������Ʈ��", "images/��ư_������Ʈ��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�巡�׿�", "images/��ư_�巡�׿�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�÷��̾��", "images/��ư_�÷��̾��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���ʹ̿�", "images/��ư_���ʹ̿�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����Ʈ��", "images/��ư_����Ʈ��.bmp", 173, 57, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��ư_����ȭ��ǥ", "images/��ư_����ȭ��ǥ.bmp", 51, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������ȭ��ǥ", "images/��ư_������ȭ��ǥ.bmp", 51, 60, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��ư_����ȭ��ǥ��", "images/��ư_����ȭ��ǥ��.bmp", 51, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������ȭ��ǥ��", "images/��ư_������ȭ��ǥ��.bmp", 51, 60, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��׶���", "images/���ȭ��3��.bmp", 6000, 960); //���� >> ���λ����� 3�� - ����
	IMAGEMANAGER->addImage("�̴ϸ�", "images/���ȭ��3��̴�.bmp", 600, 96); //���� >> ���λ����� 3�� - ����

	//����Ÿ�� �ʱ�ȭ
	sCurrentTile.x = 12; //�ʱ� Ÿ�� ���� ���� - ���� 
	sCurrentTile.y = 10; //�ʱ� Ÿ�� ���� ���� - ���� 
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
	rcBg = RectMake(0, 0, 6000, 960);     //��׶��� ��Ʈ ũ�� ���� - ����
	//�̴ϸ� ��Ʈ
	rcMini = RectMake(0, 0, 600, 96); //�̴ϸ� ��Ʈ ũ�� ���� -����
	rcMcamera = RectMake(0, 0, 160, 96);//�̴ϸ� ī�޶� ��ǥ ���� - ���� 

	//��ư�ڽ�Ŭ�� - ��ưŬ�������� �̹������� �Һ���
	isSaveClick = false;
	isLoadClick = false;
	isObjectClick = false;
	isTerrainClick = false;
	isDragClick = false;
	isEraserClick = false;
	isResetClick = false;
	isLeftPointerClick = false;
	isRightPonterClick = false;
	isEnemyClick = false;
	isPlayerClick = false;
	isExitClick = false;

	return S_OK;
}

void maptool::release()
{
}

void maptool::update()
{
	this->toolBoxUpdate();

	//Z ���� �� �巡��
	if (INPUT->GetToggleKey('Z'))
	{
		if (INPUT->GetKeyDown(VK_LBUTTON))
		{
			//Ÿ�� ���� ���� �巡�� �����϶� �ȵǼ� �巡�׿� �߰��� - ����
			for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
			{
				if (sToolBox.toggle == false)continue; //���Ű �ȴ����� �浹ó���� ���� �ʴ´�.
				if (PtInRect(&sSampleTile[i].rc, _ptMouse))
				{
					sCurrentTile.x = sSampleTile[i].terrainFrameX;
					sCurrentTile.y = sSampleTile[i].terrainFrameY;
					break;
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
					ctrlSelect = CTRL_TERRAIN;
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
				isRightPonterClick = true;
				sToolBox.selectedPage++;
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				isTerrainClick = true;
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				isObjectClick = true;
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
				isEnemyClick = true;
			}
			if (PtInRect(&sToolBtn.rcDrag, _ptMouse))
			{
				isDragClick = true;
			}
			if (PtInRect(&sToolBtn.rcExit, _ptMouse))
			{
				isExitClick = true;
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
			isLeftPointerClick = false;
			isRightPonterClick = false;
			isPlayerClick = false;
			isEnemyClick = false;
			isDragClick = false;
			isExitClick = false;
			
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
					ctrlSelect = CTRL_TERRAIN;
				}
				
			}

			if (PtInRect(&sToolBtn.rcLeftPointer, _ptMouse) && sToolBox.selectedPage >= 2)
			{
				isLeftPointerClick = true;
				sToolBox.selectedPage--;
			}
			if (PtInRect(&sToolBtn.rcRightPointer, _ptMouse) && sToolBox.selectedPage < 4)
			{
				isRightPonterClick = true;
				sToolBox.selectedPage++;
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				isTerrainClick = true;
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				isObjectClick = true;
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
				isEnemyClick = true;
			}
			if (PtInRect(&sToolBtn.rcDrag, _ptMouse))
			{
				isDragClick = true;
			}
			if (PtInRect(&sToolBtn.rcExit, _ptMouse))
			{
				isExitClick = true;
			}
		}
		if (INPUT->GetKeyUp(VK_LBUTTON))					//���̺�,�ε�,���¹�ư false ��Ű�� �߰�
		{
			isSaveClick = false;
			isLoadClick = false;
			isResetClick = false;
			isTerrainClick = false;
			isObjectClick = false;
			isLeftPointerClick = false;
			isRightPonterClick = false;
			isPlayerClick = false;
			isEnemyClick = false;
			isDragClick = false;
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

	if (INPUT->GetKey('D'))
	{
		dragRc = RectMake(-10, -10, 1, 1);
		if (WINSIZEX >= rcBg.right)
		{
			rcBg.right = WINSIZEX;
		}
		else
		{
			rcBg.left -= 10;
			rcBg.right -= 10;
			rcMcamera.left += 1;
			rcMcamera.right += 1;
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
			rcBg.left += 10;
			rcBg.right += 10;
			rcMcamera.left -= 1;
			rcMcamera.right -= 1;
		}
	}

	if (ctrlSelect == CTRL_RESET)					//���� ���� �߰�
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			sTile[i].terrainFrameX = 10;
			sTile[i].terrainFrameY = 9;
			sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);

			//�̴ϸ� Ÿ�� ���� ���� �߰� - ���� 
			sMiniTile[i].terrainFrameX = 12;
			sMiniTile[i].terrainFrameY = 10;
			sMiniTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
		}
		ctrlSelect = CTRL_TERRAIN;
	}
	//���ڽ� ī�޶� ��Ʈ�߰� - ����
	rcToolCamera = RectMake(sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 448, 320);
}

void maptool::render()
{

	IMAGEMANAGER->render("��׶���", getMemDC(), rcBg.left, rcBg.top);
	IMAGEMANAGER->render("�̴ϸ�", getMemDC(), rcMini.left, rcMini.top);
	FrameRect(getMemDC(), rcMini, RGB(0, 0, 0));
	FrameRect(getMemDC(), rcMcamera, RGB(255, 0, 0));
	//�ΰ���ȭ�� ������ �׸���
	RECT rcTemp;
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&rcTemp, &rcWins, &sTile[i].rc))
		{
			IMAGEMANAGER->frameRender("����Ÿ��_����", getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
				sTile[i].terrainFrameX, sTile[i].terrainFrameY);

			//������ ���� �̹��� ���� -���� 
			IMAGEMANAGER->frameRender("����Ÿ��_���չ̴�", getMemDC(), sMiniTile[i].rc.left, sMiniTile[i].rc.top,
				sMiniTile[i].terrainFrameX, sMiniTile[i].terrainFrameY);
		}
	}
	
	if (isDrag)
	{
		FrameRect(getMemDC(), dragRc, RGB(255, 0, 0));
	}
	else
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
				}
				//�����ư�� ���찳��?
				if (ctrlSelect == CTRL_ERASER)							//�̷����� �����߰�
				{
					if (isEraserClick)
					{
						sTile[i].terrainFrameX = 10;
						sTile[i].terrainFrameY = 9;

						//�̴� Ÿ�� �ε��� ��ǥ ���� -����
						sMiniTile[i].terrainFrameX = 12;
						sMiniTile[i].terrainFrameY = 10;
						//sTile[i].obj = OBJ_NONE;
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
		IMAGEMANAGER->render("���ڽ�", getMemDC(), sToolBox.rcBack.left - 15, sToolBox.rcBack.top -15);
		//Rectangle(getMemDC(), sToolBox.rcPage);
		//Rectangle(getMemDC(), sToolBtn.rcLoad);
		IMAGEMANAGER->render("��ư_�ε�", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		//Rectangle(getMemDC(), sToolBtn.rcSave);
		IMAGEMANAGER->render("��ư_���̺�", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		//Rectangle(getMemDC(), sToolBtn.rcReset);
		IMAGEMANAGER->render("��ư_����", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		//Rectangle(getMemDC(), sToolBtn.rcDelete);
		IMAGEMANAGER->render("��ư_�̷�����", getMemDC(), sToolBtn.rcEraser.left, sToolBtn.rcEraser.top);
		//Rectangle(getMemDC(), sToolBtn.rcTerrain);
		IMAGEMANAGER->render("��ư_����", getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		//Rectangle(getMemDC(), sToolBtn.rcObject);
		IMAGEMANAGER->render("��ư_������Ʈ", getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		//Rectangle(getMemDC(), sToolBtn.rcDrag);
		IMAGEMANAGER->render("��ư_�巡��", getMemDC(), sToolBtn.rcDrag.left , sToolBtn.rcDrag.top);
		//Rectangle(getMemDC(), sToolBtn.rcPlayer);
		IMAGEMANAGER->render("��ư_�÷��̾�", getMemDC(), sToolBtn.rcPlayer.left, sToolBtn.rcPlayer.top);
		//Rectangle(getMemDC(), sToolBtn.rcMonster);
		IMAGEMANAGER->render("��ư_���ʹ�", getMemDC(), sToolBtn.rcEnemy.left, sToolBtn.rcEnemy.top);
		//Rectangle(getMemDC(), sToolBtn.rcExit);
		IMAGEMANAGER->render("��ư_����Ʈ", getMemDC(), sToolBtn.rcExit.left, sToolBtn.rcExit.top);
		
		//Rectangle(getMemDC(), rcToolCamera);
		RECT _rcTemp;
		switch (sToolBox.selectedPage)
		{
		case 1:
			if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("������ƮŸ��1", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				IMAGEMANAGER->render("����Ÿ��_����", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 0, 0, 448, 320);
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
				IMAGEMANAGER->render("������ƮŸ��2", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				IMAGEMANAGER->render("����Ÿ��_����", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 448, 0, 448, 320);
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
				IMAGEMANAGER->render("������ƮŸ��3", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				IMAGEMANAGER->render("����Ÿ��_����", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 896, 0, 448, 320);
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
				IMAGEMANAGER->render("������ƮŸ��4", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				//���� �������Ϸ� �ٲٸ鼭 �̹��� �ҽ���ǥ �� �ҽ����μ��� ũ�� ��ȭ �߰� - ����
				IMAGEMANAGER->render("����Ÿ��_����", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15, 1344, 0, 448, 320);
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
			IMAGEMANAGER->render("��ư_�ε��", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		}
		if (isSaveClick)
		{
			IMAGEMANAGER->render("��ư_���̺��", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		}
		if (isResetClick)
		{
			IMAGEMANAGER->render("��ư_���¿�", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		}
		if (isEraserClick)
		{
			IMAGEMANAGER->render("��ư_�̷�������", getMemDC(), sToolBtn.rcEraser.left, sToolBtn.rcEraser.top);
		}
		if (isObjectClick)
		{
			IMAGEMANAGER->render("��ư_������Ʈ��", getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		}
		if (isTerrainClick)
		{
			IMAGEMANAGER->render("��ư_������", getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		}
		if (isDragClick)
		{
			IMAGEMANAGER->render("��ư_�巡�׿�", getMemDC(), sToolBtn.rcDrag.left, sToolBtn.rcDrag.top);
		}
		if (isPlayerClick)
		{
			IMAGEMANAGER->render("��ư_�÷��̾��", getMemDC(), sToolBtn.rcPlayer.left, sToolBtn.rcPlayer.top);
		}
		if (isEnemyClick)
		{
			IMAGEMANAGER->render("��ư_���ʹ̿�", getMemDC(), sToolBtn.rcEnemy.left, sToolBtn.rcEnemy.top);
		}
		if (isExitClick)
		{
			IMAGEMANAGER->render("��ư_����Ʈ��", getMemDC(), sToolBtn.rcExit.left, sToolBtn.rcExit.top);
		}

		//ȭ��ǥ �̹��� Ŭ���� ����
		if (isLeftPointerClick)
		{
			IMAGEMANAGER->render("��ư_����ȭ��ǥ��", getMemDC(), sToolBtn.rcLeftPointer.left, sToolBtn.rcLeftPointer.top);
		}
		else
		{
			//Rectangle(getMemDC(), sToolBtn.rcLeftPointer);
			IMAGEMANAGER->render("��ư_����ȭ��ǥ", getMemDC(), sToolBtn.rcLeftPointer.left, sToolBtn.rcLeftPointer.top);
		}
		if (isRightPonterClick)
		{
			IMAGEMANAGER->render("��ư_������ȭ��ǥ��", getMemDC(), sToolBtn.rcRightPointer.left, sToolBtn.rcRightPointer.top);
		}
		else
		{
			//Rectangle(getMemDC(), sToolBtn.rcRightPointer);
			IMAGEMANAGER->render("��ư_������ȭ��ǥ", getMemDC(), sToolBtn.rcRightPointer.left, sToolBtn.rcRightPointer.top);
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
		sTile[i].obj = OBJ_NONE; //������Ʈ ���þ��� ����
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
				sCurrentTile.x = sSampleTile[i].terrainFrameX;
				sCurrentTile.y = sSampleTile[i].terrainFrameY;
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
			}
			//�����ư�� ���찳��?
			if (ctrlSelect == CTRL_ERASER)							//�̷����� �����߰�
			{
				if (isEraserClick)
				{
					sTile[i].terrainFrameX = 10;
					sTile[i].terrainFrameY = 9;
					//�̴ϸ� Ÿ�� �ε��� ��ǥ ���� - ����
					sMiniTile[i].terrainFrameX = 12;
					sMiniTile[i].terrainFrameY = 10;
					//sTile[i].obj = OBJ_NONE;
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
	sToolBtn.rcEraser = RectMake(sToolBox.x + 10, sToolBox.y  - 18, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 10, sToolBox.y + 52, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 10, sToolBox.y + 122, sToolBtn.width, sToolBtn.height);

	//������ ��ư��
	sToolBtn.rcObject = RectMake(sToolBox.x + 225, sToolBox.y - 158, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcEnemy = RectMake(sToolBox.x + 225, sToolBox.y - 88, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcDrag = RectMake(sToolBox.x + 225, sToolBox.y - 18, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 225, sToolBox.y + 52, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcExit = RectMake(sToolBox.x + 225, sToolBox.y + 122, sToolBtn.width, sToolBtn.height);
	


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

