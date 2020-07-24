#include "DXUT.h"
#include "cStage1Map.h"

cStage1Map::cStage1Map()
{
	m_image = IMAGE->FindImage("Map");
}

cStage1Map::~cStage1Map()
{
}

void cStage1Map::Render()
{
	float RenderPos = (int)m_speed % m_image->info.Height;
	RENDER->Render(m_image, Vec2(0, 0 + m_image->info.Height - RenderPos), Vec2(1, 1), 0, 0);
	RENDER->Render(m_image, Vec2(0, 0 - RenderPos), Vec2(1, 1), 0, 0);
}
void cStage1Map::Update(float speed)
{
	m_speed += speed * DXUTGetElapsedTime();
}

