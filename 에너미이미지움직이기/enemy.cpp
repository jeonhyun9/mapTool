#include "stdafx.h"
#include "enemy.h"


HRESULT enemy::init()
{
	//����� ����ü �ʱ�ȭ
	sBean.x = WINSIZEX / 2;
	sBean.y = WINSIZEY/2;
	_beanleft = false;
	_beanright = true;
	
	//����� ����ü �ʱ�ȭ
	sBird.x = 700;
	sBird.y = 700;
	sBird.angle = PI_2;
	sBird.speed = 5.0f;
	sBird.jumpSpeed = 16.0f;
	_fishleft = false;
	_fishright = true;
	gravity = 0;


	//���� ����ü �ʱ�ȭ
	sMushroom.x = 800;
	sMushroom.y = 850;
	_mushroomleft = true;

	//�� ����ü �ʱ�ȭ
	sFlower.x = 500;
	sFlower.y = 700;
	sFlower.angle = PI_2;
	sFlower.speed = 3.0f;
	sFlower.jumpSpeed = 16.0f;
	flowerG = 0;
	flowerJump = false;


	//���� ����ü �ʱ�ȭ
	sBoss.x = 900;
	sBoss.y = 725;
	sBoss.angle = PI_2;
	sBoss.speed = 5.0f;
	sBoss.jumpSpeed = 16.0f;
	bossG = 0;
	bossJump = false;
	bossleft = false;
	bossright = true;



	//����ü ��Ʈ �ʱ�ȭ
	sBean.rc = RectMake(sBean.x, sBean.y, 64, 64);
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 64, 96);
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);

	//ī��Ʈ�� �ʱ�ȭ
	count = 0;
	imgCount = 0;
	imgIndex = 0;

	sEnemyState = ENEMYRUN;

	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	count++;
	sBean.rc = RectMake(sBean.x, sBean.y, 64, 64);
	//����� �� �Թ���
	//���ʰ���?
	if (sBean.rc.left < 500)
	{
		_beanleft = false;
		_beanright = true;
	}
	//�����ʰ���?
	if (sBean.rc.right > 1000)
	{
		_beanleft = true;
		_beanright = false;
	}
	//���� �̵�
	if (_beanleft)
	{
		sBean.x -= 2;
	}
	//������ �̵�
	if (_beanright)
	{
		sBean.x += 2;
	}


	// �� ���� ���
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	
	//�������� ����?
	if (sBird.rc.left < 600)
	{
		_fishleft = false;
		_fishright = true;
	}
	//���������� ����?
	if (sBird.rc.right > 900)
	{
		_fishleft = true;
		_fishright = false;
	}
	//�����̵�
	if (_fishleft)
	{
		sBird.x -= 2;
	}
	//���������� �̵�
	if (_fishright)
	{
		sBird.x += 2;
	}
	//����� �����ϳ�?

	if (sBird.y == 850)
	{
		isJump = true;
	}
	//����� ����
	if (isJump)
	{
		gravity += 0.5f;
		sBird.y += -sinf(sBird.angle) * sBird.jumpSpeed + gravity;
	}
	//�ٴ� ����ó��
	if (sBird.rc.bottom >= 900)
	{
		gravity = 0;
	}



	//���� ������ 
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	if (_mushroomleft)
	{
		sMushroom.x -= 2;
	}
	
	//�� ������ 
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 50, 50);
	if (count % 300 == 0&&flowerJump==false)
	{
		flowerG = 0.0f;
		flowerJump = true;
		
	}
	//�� ����
	if (flowerJump)
	{
		flowerG += 0.5f;
		sFlower.y += -sinf(sFlower.angle) * sFlower.jumpSpeed + flowerG;
	}
	// �ٴڿ���ó��
	if (sFlower.y>800)
	{
		flowerJump = false;
	}

	//���� ������
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);
	if (count % 500 == 0 && bossJump == false)
	{
		bossG = 0.0f;
		bossJump = true;

	}
	//���� ����
	if (bossJump)
	{
		bossG += 0.5f;
		sBoss.y += -sinf(sBoss.angle) * sBoss.jumpSpeed + bossG;
	}
	//�ٴ� ����ó�� 
	if (sBoss.y > 725)
	{
		bossJump = false;
	}
	//�������� �̵�
	if (bossleft)
	{
		sBoss.x -= 2;
		//�׸����� ����������
		if (sBoss.x<500)
		{
			bossleft = false;
			bossright = true;
		}
		
	}
	//���������� �̵�
	if (bossright)
	{
		sBoss.x += 2;
		//�׸����� �ٽ� ��������
		if (sBoss.x >1000)
		{
			bossleft = true;
			bossright = false;
		}
		
	}

	this->enemyAnimation();
	this->bossAttackMove();
}

void enemy::render()
{
	//Ȯ�ο� ��Ʈ
	Rectangle(getMemDC(), sBean.rc);//�����
	Rectangle(getMemDC(), sBird.rc);//����� 
	Rectangle(getMemDC(), sMushroom.rc);//����
	Rectangle(getMemDC(), sFlower.rc);//��
	Rectangle(getMemDC(), sBoss.rc);//����

	IMAGEMANAGER->findImage("����")->frameRender(getMemDC(),sBoss.rc.left,sBoss.rc.top);

}

void enemy::enemyAnimation()
{
	
	switch (sEnemyState)
	{
	case ENEMYRUN:
		//���� ������ �ִϸ��̼�
		if (bossleft)
		{
			imgCount++;
			IMAGEMANAGER->findImage("����")->setFrameY(1);
			if (count % 6 == 0)
			{
				imgIndex--;
				if (imgIndex < 0)
				{
					imgIndex = 4;
				}
				IMAGEMANAGER->findImage("����")->setFrameX(imgIndex);
			}
		}
		else //������ ������ �ִϸ��̼�
		{
			imgCount++;
			IMAGEMANAGER->findImage("����")->setFrameY(0);
			if (imgCount % 6 == 0)
			{
				imgIndex++;
				if (imgIndex > 4)
				{
					imgIndex = 0;
				}
				IMAGEMANAGER->findImage("����")->setFrameX(imgIndex);
			}
		}

		break;
	case ENEMYDIE:

		break;

	case ENEMYATT:
		break;

	}



}

void enemy::bossAttackMove()
{


}
