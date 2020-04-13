#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	//�̱��濡�� �÷��̾��� ���� x, y��ǥ�� �޾ƿ´�.
	sPlayer.x = DATAMANAGER->getPlayerData().ptStart.x;
	sPlayer.y = DATAMANAGER->getPlayerData().ptStart.y;

	//�÷��̾� �Ӽ� �ʱ�ȭ
	sPlayer.width = 15;
	sPlayer.height = 20;
	sPlayer.speed = 5.0f;
	sPlayer.jumpSpeed = 16.0f;
	sPlayer.angle = PI_2;
	sPlayer.animation = IDLE;
	frameCnt = frameIdx = 0;

	//�÷��̾� �̹��� �ʱ�ȭ
	sPlayer.imgIdle = IMAGEMANAGER->findImage("������_IDLE");

	gravity = 0;

	isJump = false;

	return S_OK;
}

void player::release()
{

}

void player::update()
{
	//�÷��̾� ��Ʈ ����
	sPlayer.rc = RectMake(sPlayer.x, sPlayer.y, sPlayer.width, sPlayer.height);

	if (INPUT->GetKey(VK_LEFT))
	{
		sPlayer.angle = PI_2 + 1;
		sPlayer.x += cosf(sPlayer.angle) * sPlayer.speed;
		sPlayer.animation = WALK;
		isRight = false;
	}

	if (INPUT->GetKey(VK_RIGHT))
	{
		sPlayer.angle = PI_2 - 1;
		sPlayer.x += cosf(sPlayer.angle) * sPlayer.speed;
		sPlayer.animation = WALK;
		isRight = true;
	}

	if (INPUT->GetKeyDown(VK_SPACE))
	{
		isJump = true;
	}

	if (isJump)
	{
		gravity += 0.5f;
		sPlayer.y += -sinf(sPlayer.angle) * sPlayer.jumpSpeed + gravity;
		sPlayer.animation = JUMP;
	}

	this->playerAnimation();
}

void player::render()
{
	Rectangle(getMemDC(), sPlayer.rc);
	switch (sPlayer.animation)
	{
	case IDLE:
		sPlayer.imgIdle->frameRender(getMemDC(), sPlayer.x - sPlayer.width / 2, sPlayer.y - sPlayer.height / 2);
		break;
	case WALK:
		break;
	case RUN:
		break;
	case JUMP:
		break;
	}
}

void player::playerAnimation()
{
	switch (sPlayer.animation)
	{
	case IDLE:
		frameCnt++;
		if (isRight)
		{
			sPlayer.imgIdle->setFrameY(0);
			if (frameCnt % 5 == 0)
			{
				frameIdx++;
				if (frameIdx > 4)
				{
					frameIdx = 0;
				}
				sPlayer.imgIdle->setFrameX(frameIdx);
			}
		}
		else
		{
			sPlayer.imgIdle->setFrameY(1);
			if (frameCnt % 5 == 0)
			{
				frameIdx--;
				if (frameIdx < 1)
				{
					frameIdx = 5;
				}
				sPlayer.imgIdle->setFrameX(frameIdx);
			}
		}
		break;
	case WALK:
		break;
	case RUN:
		break;
	case JUMP:
		break;
	}
}
