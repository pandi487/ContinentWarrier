#pragma once
class cTimer
{
public:
	FLOAT m_Start = 0;
	FLOAT m_Del = 0;
public:
	cTimer(FLOAT Del);

	~cTimer() {};
	BOOL Update();
};

