#pragma once
class cStage1Map
{
private:
	float m_speed = 0;
	cTexture* m_image;
public:
	cStage1Map();
	~cStage1Map();
	void Render();
	void Update(float speed);

};

