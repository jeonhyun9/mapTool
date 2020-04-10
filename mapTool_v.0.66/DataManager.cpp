#include "stdafx.h"
#include "DataManager.h"

HRESULT DataManager::init()
{
	return	S_OK;
}

void DataManager::release()
{

}

void DataManager::setEnemy(enemyCatagory _category, float _x, float _y)
{
	sEnemy.category = _category;
	sEnemy.ptStart.x = _x;
	sEnemy.ptStart.y = _y;
	vEnemy.push_back(sEnemy);
}

