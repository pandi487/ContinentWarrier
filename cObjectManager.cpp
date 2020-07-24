#include "DXUT.h"
#include "cObjectManager.h"
#include "cObject.h"

cObjectManager::cObjectManager()
{
}

cObjectManager::~cObjectManager()
{
	Release();
}

cObject * cObjectManager::AddObj(cObject * _newObj)
{
	if (_newObj)
	{
		m_objlist.push_back(_newObj);

	}
	return _newObj;
}

void cObjectManager::Collision(cObject * obj)
{
	if (obj->GetRect().bottom != rt.bottom)
	{

		for (auto iter : m_objlist)
		{
			if (obj->GetTag() != iter->GetTag())
			{

				if (obj != iter)
				{
					if (IntersectRect(&rt, &iter->GetRect(), &obj->GetRect()))
					{
						obj->Collision(iter);
					}
				}
			}

		}

	}
}

void cObjectManager::ObbColl(cObject * obj)
{
	if (obj->GetRect().bottom != rt.bottom)
		for (auto iter : m_objlist)
		{
			if (obj != iter)
			{
				
				if (obj->GetTag() != iter->GetTag())
				{
					Vec2 interval = obj->GetPos() - iter->GetPos();
					Vec2 vX[2], vY[2];
					vX[0] = GetWidthVector(obj->GetRect(), obj->GetRot());
					vY[0] = GetHeightVector(obj->GetRect(), obj->GetRot());
					vX[1] = GetWidthVector(iter->GetRect(), iter->GetRot());
					vY[1] = GetHeightVector(iter->GetRect(), iter->GetRot());

					Vec2 vSA[4];
					D3DXVec2Normalize(&vSA[0], &vX[0]);
					D3DXVec2Normalize(&vSA[1], &vY[0]);
					D3DXVec2Normalize(&vSA[2], &vX[1]);
					D3DXVec2Normalize(&vSA[3], &vY[1]);

					for (size_t i = 0; i < 4; i++)
					{
						FLOAT d = fabs((D3DXVec2Dot(&vSA[i], &interval)));

						FLOAT r1 =
							fabs(D3DXVec2Dot(&vSA[i], &vX[0])) +
							fabs(D3DXVec2Dot(&vSA[i], &vY[0]));
						FLOAT r2 =
							fabs(D3DXVec2Dot(&vSA[i], &vX[1])) +
							fabs(D3DXVec2Dot(&vSA[i], &vY[1]));
						if (r1 + r2 < d)
						{
							return;
						}

					}
					obj->Collision(iter);
				}
			}
		}
}



void cObjectManager::Update()
{
	rt = { 0,0,0,0 };

	for (auto iter = m_objlist.begin(); iter != m_objlist.end();)
	{
		(*iter)->Update();

		
			Collision(*iter);
		
		

		if ((*iter)->ObjDel())
		{
			delete *iter;
			iter = m_objlist.erase(iter);
		}
		else iter++;
	}
}

void cObjectManager::Render()
{
	for (auto iter : m_objlist)
	{
		iter->Render();
	}
}

void cObjectManager::Release()
{
	for (auto iter : m_objlist)
	{
		SAFE_DELETE(iter);
	}
	m_objlist.clear();
}

void cObjectManager::UIRender()
{
	for (auto iter : m_objlist)
	{
		iter->UIRender();
	}
}

Vec2 cObjectManager::GetWidthVector(RECT obj, FLOAT rot)
{
	FLOAT Width = obj.right - obj.left;
	Vec2 temp;
	temp.x = Width * cos(D3DXToRadian(rot)) / 2;
	temp.y = Width * sin(D3DXToRadian(rot)) / 2;
	return temp;
}

Vec2 cObjectManager::GetHeightVector(RECT obj, FLOAT rot)
{
	FLOAT height = obj.bottom - obj.top;
	Vec2 temp;
	temp.x = height * cos(D3DXToRadian(rot - 90)) / 2;
	temp.y = height * sin(D3DXToRadian(rot - 90)) / 2;

	return temp;
	return temp;
}
