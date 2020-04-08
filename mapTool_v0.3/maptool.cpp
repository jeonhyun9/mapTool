#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//Ÿ�ϸ� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addFrameImage("����Ÿ��_����", "images/����Ÿ��_����.bmp", 1792, 320, 56, 10);
	IMAGEMANAGER->addFrameImage("����Ÿ��1", "images/����Ÿ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��2", "images/����Ÿ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��3", "images/����Ÿ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("����Ÿ��4", "images/����Ÿ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	IMAGEMANAGER->addFrameImage("������ƮŸ��1", "images/������ƮŸ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��2", "images/������ƮŸ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��3", "images/������ƮŸ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	IMAGEMANAGER->addFrameImage("������ƮŸ��4", "images/������ƮŸ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	IMAGEMANAGER->addImage("��ư_�̷�����", "images/��ư_�̷�����.bmp", 173, 57,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("��ư_�ε�", "images/��ư_�ε�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���̺�", "images/��ư_���̺�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������Ʈ", "images/��ư_������Ʈ.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_����ȭ��ǥ", "images/��ư_����ȭ��ǥ.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_������ȭ��ǥ", "images/��ư_������ȭ��ǥ.bmp", 50, 50, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��ư_�̷�������", "images/��ư_�̷�������.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_�ε��", "images/��ư_�ε��.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���¿�", "images/��ư_���¿�.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ư_���̺��", "images/��ư_���̺��.bmp", 173, 57, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��׶���", "images/���ȭ��.bmp", 2000, 960);
	IMAGEMANAGER->addImage("�̴ϸ�", "images/�̴ϸ�ȭ��.bmp", 200, 96);
	IMAGEMANAGER->addFrameImage("�̴�Ÿ��1", "images/����Ÿ��1_�̴�.bmp", 45, 32, SAMPLETILEX, SAMPLETILEY);

	//����Ÿ�� �ʱ�ȭ
	sCurrentTile.x = 4;
	sCurrentTile.y = 4;
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
	rcBg = RectMake(0, 0, 2000, 960);
	//�̴ϸ� ��Ʈ
	rcMini = RectMake(WINSIZEX - 200, WINSIZEY - 96, 200, 960);
	rcMcamera = RectMake(WINSIZEX - 200, WINSIZEY - 96, 160, 96);

	//��ư�ڽ�Ŭ�� - ��ưŬ�������� �̹������� �Һ���
	isSave = false;
	isLoad = false;
	isObject = false;
	isTerrain = false;
	isDragBox = false;
	isErase = false;
	isReset = false;

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
			isDrag = true;
			saveX = _ptMouse.x;
			saveY = _ptMouse.y;

			if (PtInRect(&sToolBtn.rcSave, _ptMouse))
			{
				isSave = true;		//�߰� ���̺괭������ �̹��� ��������
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoad = true;		//�߰� �ε崭������ �̹��� ��������
				this->load();
			}

			if (PtInRect(&sToolBtn.rcDelete, _ptMouse))
			{
				if (isErase == false)		//�߰� �̷����� �������� �̹��� ��������
				{
					isErase = true;
					ctrlSelect = CTRL_ERASER;
				}
				else
				{
					isErase = false;		//�̷������� �ٽ� �����ָ� Ǯ��
					ctrlSelect = CTRL_TERRAIN;
				}
			}
		}
		if (INPUT->GetKey(VK_LBUTTON))
		{
			dragRc = RectMake(saveX, saveY, (_ptMouse.x - saveX), (_ptMouse.y - saveY));
		}

		if (INPUT->GetKeyUp(VK_LBUTTON))		//��Ű������ �������� true �� fasleó�����ֱ�
		{
			isDrag = false;
			isSave = false;
			isLoad = false;
			isReset = false;
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
				isSave = true;		//�߰� ���̺� �������� �̹��� ��������
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoad = true;		//�߰� �ε� �������� �̹��� ��������
				this->load();
			}

			if (PtInRect(&sToolBtn.rcDelete, _ptMouse))
			{
				if (isErase == false)		//�߰� �̷����� �������� �̹��� ��������
				{
					isErase = true;
					ctrlSelect = CTRL_ERASER;
				}
				else
				{
					isErase = false;		//�̷������� �ٽ� �����ָ� Ǯ��
					ctrlSelect = CTRL_TERRAIN;
				}
				
			}

			if (PtInRect(&sToolBtn.rcLeftPointer, _ptMouse) && sToolBox.selectedPage >= 2)
			{
				sToolBox.selectedPage--;
			}
			if (PtInRect(&sToolBtn.rcRightPointer, _ptMouse) && sToolBox.selectedPage < 4)
			{
				sToolBox.selectedPage++;
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				//isTerrain = true;
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				//isObject = true;
				ctrlSelect = CTRL_OBJECT;
			}
			if (PtInRect(&sToolBtn.rcReset, _ptMouse))		//���¹�ư���� ��Ƽ�η�����
			{
				isReset = true;
				isErase = false;
				ctrlSelect = CTRL_RESET;
			}
		}
		if (INPUT->GetKeyUp(VK_LBUTTON))					//���̺�,�ε�,���¹�ư false ��Ű�� �߰�
		{
			isSave = false;
			isLoad = false;
			isReset = false;
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
		}
		ctrlSelect = CTRL_TERRAIN;
	}
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
			IMAGEMANAGER->frameRender("����Ÿ��1", getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
				sTile[i].terrainFrameX, sTile[i].terrainFrameY);

			IMAGEMANAGER->frameRender("�̴�Ÿ��1", getMemDC(), sMiniTile[i].rc.left, sMiniTile[i].rc.top,
				sMiniTile[i].terrainFrameX, sMiniTile[i].terrainFrameY);
		}
	}
	
	if (isDrag)
	{
		//Rectangle(getMemDC(), dragRc);
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
					if (isErase)
					{
						sTile[i].terrainFrameX = 10;
						sTile[i].terrainFrameY = 9;
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
		Rectangle(getMemDC(), sToolBox.rcBack);
		Rectangle(getMemDC(), sToolBox.rcPage);
		Rectangle(getMemDC(), sToolBtn.rcLoad);
		IMAGEMANAGER->render("��ư_�ε�", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		Rectangle(getMemDC(), sToolBtn.rcSave);
		IMAGEMANAGER->render("��ư_���̺�", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		Rectangle(getMemDC(), sToolBtn.rcReset);
		IMAGEMANAGER->render("��ư_����", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		Rectangle(getMemDC(), sToolBtn.rcDelete);
		IMAGEMANAGER->render("��ư_�̷�����", getMemDC(), sToolBtn.rcDelete.left, sToolBtn.rcDelete.top);
		Rectangle(getMemDC(), sToolBtn.rcTerrain);
		IMAGEMANAGER->render("��ư_����", getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		Rectangle(getMemDC(), sToolBtn.rcObject);
		IMAGEMANAGER->render("��ư_������Ʈ", getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		//Rectangle(getMemDC(), sToolBtn.rcLeftPointer);
		IMAGEMANAGER->render("��ư_����ȭ��ǥ", getMemDC(), sToolBtn.rcLeftPointer.left, sToolBtn.rcLeftPointer.top);
		//Rectangle(getMemDC(), sToolBtn.rcRightPointer);
		IMAGEMANAGER->render("��ư_������ȭ��ǥ", getMemDC(), sToolBtn.rcRightPointer.left, sToolBtn.rcRightPointer.top);

		switch (sToolBox.selectedPage)
		{
		case 1:
			if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("������ƮŸ��1", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				IMAGEMANAGER->render("����Ÿ��1", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		case 2:
			if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("������ƮŸ��2", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				IMAGEMANAGER->render("����Ÿ��2", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		case 3:
			if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("������ƮŸ��3", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				IMAGEMANAGER->render("����Ÿ��3", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}

			break;
		case 4:
			if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("������ƮŸ��4", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else
			{
				IMAGEMANAGER->render("����Ÿ��4", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		}

		//�������� ��ư ��ȯ ���� �߰�
		if (isLoad)
		{
			IMAGEMANAGER->render("��ư_�ε��", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		}
		if (isSave)
		{
			IMAGEMANAGER->render("��ư_���̺��", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		}
		if (isReset)
		{
			IMAGEMANAGER->render("��ư_���¿�", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		}
		if (isErase)
		{
			IMAGEMANAGER->render("��ư_�̷�������", getMemDC(), sToolBtn.rcDelete.left, sToolBtn.rcDelete.top);
		}

		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			//Rectangle(getMemDC(), sSampleTile[i].rc);
			FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
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

	//������ ����Ÿ�� ��Ʈ �ʱ�ȭ
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
				if (isErase)
				{
					sTile[i].terrainFrameX = 10;
					sTile[i].terrainFrameY = 9;
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
	sToolBtn.rcDelete = RectMake(sToolBox.x + 60, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 250, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 60, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 250, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcTerrain = RectMake(sToolBox.x + 60, sToolBox.y + 10, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcObject = RectMake(sToolBox.x + 250, sToolBox.y + 10, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLeftPointer = RectMake(sToolBox.x - 315, sToolBox.y + 140, 50,50);
	sToolBtn.rcRightPointer = RectMake(sToolBox.x - 255, sToolBox.y + 140, 50, 50);

	//������ ����Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left + 15 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
		}
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

