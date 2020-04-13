#include "stdafx.h"
#include "enemy.h"


HRESULT enemy::init()
{
	//콩벌레 구조체 초기화
	sBean.x = WINSIZEX / 2;
	sBean.y = WINSIZEY/2;
	_beanleft = false;
	_beanright = true;
	
	//물고기 구조체 초기화
	sBird.x = 700;
	sBird.y = 700;
	sBird.angle = PI_2;
	sBird.speed = 5.0f;
	sBird.jumpSpeed = 16.0f;
	_fishleft = false;
	_fishright = true;
	gravity = 0;


	//버섯 구조체 초기화
	sMushroom.x = 800;
	sMushroom.y = 850;
	_mushroomleft = true;

	//꽃 구조체 초기화
	sFlower.x = 500;
	sFlower.y = 700;
	sFlower.angle = PI_2;
	sFlower.speed = 3.0f;
	sFlower.jumpSpeed = 16.0f;
	flowerG = 0;
	flowerJump = false;


	//보스 구조체 초기화
	sBoss.x = 900;
	sBoss.y = 725;
	sBoss.angle = PI_2;
	sBoss.speed = 5.0f;
	sBoss.jumpSpeed = 16.0f;
	bossG = 0;
	bossJump = false;
	bossleft = false;
	bossright = true;



	//구조체 렉트 초기화
	sBean.rc = RectMake(sBean.x, sBean.y, 64, 64);
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 64, 96);
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);

	//카운트값 초기화
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
	//콩벌레 및 뿔벌레
	//왼쪽가냐?
	if (sBean.rc.left < 500)
	{
		_beanleft = false;
		_beanright = true;
	}
	//오른쪽가냐?
	if (sBean.rc.right > 1000)
	{
		_beanleft = true;
		_beanright = false;
	}
	//왼쪽 이동
	if (_beanleft)
	{
		sBean.x -= 2;
	}
	//오른쪽 이동
	if (_beanright)
	{
		sBean.x += 2;
	}


	// 새 점프 모션
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	
	//왼쪽으로 가냐?
	if (sBird.rc.left < 600)
	{
		_fishleft = false;
		_fishright = true;
	}
	//오른쪽으로 가냐?
	if (sBird.rc.right > 900)
	{
		_fishleft = true;
		_fishright = false;
	}
	//왼쪽이동
	if (_fishleft)
	{
		sBird.x -= 2;
	}
	//오른쪽으로 이동
	if (_fishright)
	{
		sBird.x += 2;
	}
	//물고기 점프하냐?

	if (sBird.y == 850)
	{
		isJump = true;
	}
	//물고기 점프
	if (isJump)
	{
		gravity += 0.5f;
		sBird.y += -sinf(sBird.angle) * sBird.jumpSpeed + gravity;
	}
	//바닥 예외처리
	if (sBird.rc.bottom >= 900)
	{
		gravity = 0;
	}



	//버섯 움직임 
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	if (_mushroomleft)
	{
		sMushroom.x -= 2;
	}
	
	//꽃 움직임 
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 50, 50);
	if (count % 300 == 0&&flowerJump==false)
	{
		flowerG = 0.0f;
		flowerJump = true;
		
	}
	//꽃 점프
	if (flowerJump)
	{
		flowerG += 0.5f;
		sFlower.y += -sinf(sFlower.angle) * sFlower.jumpSpeed + flowerG;
	}
	// 바닥예외처리
	if (sFlower.y>800)
	{
		flowerJump = false;
	}

	//보스 움직임
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);
	if (count % 500 == 0 && bossJump == false)
	{
		bossG = 0.0f;
		bossJump = true;

	}
	//보스 점프
	if (bossJump)
	{
		bossG += 0.5f;
		sBoss.y += -sinf(sBoss.angle) * sBoss.jumpSpeed + bossG;
	}
	//바닥 예외처리 
	if (sBoss.y > 725)
	{
		bossJump = false;
	}
	//왼쪽으로 이동
	if (bossleft)
	{
		sBoss.x -= 2;
		//그만가고 오른쪽으로
		if (sBoss.x<500)
		{
			bossleft = false;
			bossright = true;
		}
		
	}
	//오른쪽으로 이동
	if (bossright)
	{
		sBoss.x += 2;
		//그만가고 다시 왼쪽으로
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
	//확인용 렉트
	Rectangle(getMemDC(), sBean.rc);//콩벌레
	Rectangle(getMemDC(), sBird.rc);//물고기 
	Rectangle(getMemDC(), sMushroom.rc);//버섯
	Rectangle(getMemDC(), sFlower.rc);//꽃
	Rectangle(getMemDC(), sBoss.rc);//보스

	IMAGEMANAGER->findImage("보스")->frameRender(getMemDC(),sBoss.rc.left,sBoss.rc.top);

}

void enemy::enemyAnimation()
{
	
	switch (sEnemyState)
	{
	case ENEMYRUN:
		//왼쪽 프레임 애니메이션
		if (bossleft)
		{
			imgCount++;
			IMAGEMANAGER->findImage("보스")->setFrameY(1);
			if (count % 6 == 0)
			{
				imgIndex--;
				if (imgIndex < 0)
				{
					imgIndex = 4;
				}
				IMAGEMANAGER->findImage("보스")->setFrameX(imgIndex);
			}
		}
		else //오른쪽 프레임 애니메이션
		{
			imgCount++;
			IMAGEMANAGER->findImage("보스")->setFrameY(0);
			if (imgCount % 6 == 0)
			{
				imgIndex++;
				if (imgIndex > 4)
				{
					imgIndex = 0;
				}
				IMAGEMANAGER->findImage("보스")->setFrameX(imgIndex);
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
