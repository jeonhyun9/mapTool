#include "stdafx.h"
#include "loadingScene.h"

HRESULT loadingScene::init()
{
	//�ε�Ŭ���� �ʱ�ȭ
	_loading = new loading;
	_loading->init();

	//�ε� �̹��� �� ���� �ʱ�ȭ
	this->loadingImage();
	this->loadingSound();

	//�ε� ������ �̹���
	IMAGEMANAGER->addFrameImage("�ε�������", "images/�������׼�.bmp", 99, 60, 3, 1);
	count = index = 0;
	return S_OK;
}

void loadingScene::release()
{
	//�ε�Ŭ���� ����
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingScene::update()
{
	//�ε�Ŭ���� ������Ʈ
	_loading->update();

	//�ε��Ϸ��� ȭ�� ����
	if (_loading->loadingDone())
	{
		SCENEMANAGER->loadScene("�޴�");
	}
	count++;
	IMAGEMANAGER->findImage("�ε�������")->setFrameY(0);
	if (count % 5 == 0)
	{
		index++;
		if (index > 3)
		{
			index = 0;
		}
		IMAGEMANAGER->findImage("�ε�������")->setFrameX(index);
	}

}

void loadingScene::render()
{
	//�ε�Ŭ���� ����
	_loading->render();

	for (int i = 0; i < _loading->getLoadItem().size(); i++)
	{
		if (_loading->getLoadItem()[i]->getLoadKind() == LOAD_KIND_IMAGE_0) continue;
		sprintf(_LoadFileName, _loading->getLoadItem()[i]->getImageResource().fileName);
	}

	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), 570, 802, _LoadFileName, strlen(_LoadFileName));

	IMAGEMANAGER->findImage("�ε�������")->frameRender(getMemDC(), _loading->getProgressBar()->getWidth() + 470, 740);
}


//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
void loadingScene::loadingImage()
{
	//_loading->loadImage("��׶���", "Images/background.bmp", WINSIZEX, WINSIZEY);
	//_loading->loadFrameImage("ufo", "Images/ufo.bmp", 530, 32, 10, 1);
	//_loading->loadImage("bullet", "Images/bullet.bmp", 21, 21);

	_loading->loadFrameImage("����Ÿ��_����", "images/����Ÿ��_����.bmp", 1792, 320, 56, 10);
	_loading->loadFrameImage("����Ÿ��_���չ̴�", "images/����Ÿ��_���չ̴�.bmp", 179, 32, 56, 10);

	_loading->loadFrameImage("����Ÿ��1", "images/����Ÿ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("����Ÿ��2", "images/����Ÿ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("����Ÿ��3", "images/����Ÿ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("����Ÿ��4", "images/����Ÿ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	_loading->loadFrameImage("������ƮŸ��1", "images/������ƮŸ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("������ƮŸ��2", "images/������ƮŸ��2_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("������ƮŸ��3", "images/������ƮŸ��3_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("������ƮŸ��4", "images/������ƮŸ��4_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("������ƮŸ��_����", "images/������ƮŸ��_����.bmp", 1792, 320, 56, 10); // Ÿ�� ���� �̹��� �߰� -����
	_loading->loadFrameImage("������ƮŸ��_���չ̴�", "images/������ƮŸ��_���չ̴�.bmp", 179, 32, 56, 10); // �̴�Ÿ�� ���� �̹��� �߰� -���� 

	_loading->loadImage("���ڽ�", "images/���ڽ�.bmp", 1000, 450, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�̷�����", "images/��ư_�̷�����.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�ε�", "images/��ư_�ε�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_���̺�", "images/��ư_���̺�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_����", "images/��ư_����.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_������Ʈ", "images/��ư_������Ʈ.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�巡��", "images/��ư_�巡��.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�÷��̾�", "images/��ư_�÷��̾�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_���ʹ�", "images/��ư_���ʹ�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_����Ʈ", "images/��ư_����Ʈ.bmp", 173, 57, true, RGB(255, 0, 255));

	_loading->loadImage("��ư_�̷�������", "images/��ư_�̷�������.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�ε��", "images/��ư_�ε��.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_���¿�", "images/��ư_���¿�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_���̺��", "images/��ư_���̺��.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_������", "images/��ư_������.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_������Ʈ��", "images/��ư_������Ʈ��.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�巡�׿�", "images/��ư_�巡�׿�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_�÷��̾��", "images/��ư_�÷��̾��.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_���ʹ̿�", "images/��ư_���ʹ̿�.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_����Ʈ��", "images/��ư_����Ʈ��.bmp", 173, 57, true, RGB(255, 0, 255));

	_loading->loadImage("��ư_����ȭ��ǥ", "images/��ư_����ȭ��ǥ.bmp", 51, 60, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_������ȭ��ǥ", "images/��ư_������ȭ��ǥ.bmp", 51, 60, true, RGB(255, 0, 255));

	_loading->loadImage("��ư_����ȭ��ǥ��", "images/��ư_����ȭ��ǥ��.bmp", 51, 60, true, RGB(255, 0, 255));
	_loading->loadImage("��ư_������ȭ��ǥ��", "images/��ư_������ȭ��ǥ��.bmp", 51, 60, true, RGB(255, 0, 255));

	_loading->loadImage("��׶���", "images/���ȭ��3��.bmp", 6000, 960); //���� >> ���λ����� 3�� - ����
	_loading->loadImage("�̴ϸ�", "images/���ȭ��3��̴�.bmp", 600, 96); //���� >> ���λ����� 3�� - ����
	
	_loading->loadImage("�޴���׶���", "images/MenuBackGround.bmp", 1600, 960);
	_loading->loadImage("�÷��̹�ư", "images/�÷��̹�ư_off.bmp", 278, 90);
	_loading->loadImage("�÷��̿¹�ư", "images/�÷��̹�ư_on.bmp", 293, 95);
	_loading->loadImage("������ư", "images/������ư_off.bmp", 278, 90);
	_loading->loadImage("�����¹�ư", "images/������ư_on.bmp", 293, 95);
	_loading->loadImage("�������ư", "images/�������ư_off.bmp", 278, 90);
	_loading->loadImage("������¹�ư", "images/�������ư_on.bmp", 293, 95);
																
	//�ε��� �ʹ� ������ ����Ǽ� õõ�� ���ư����� �׽�Ʈ������ �����
	for (int i = 0; i < 100; i++)
	{
		_loading->loadImage("�׽�Ʈ", WINSIZEX, WINSIZEY);
	}
}

//�ε����� �Լ�(�̰��� ���带 ���� �־��)
void loadingScene::loadingSound()
{
}
