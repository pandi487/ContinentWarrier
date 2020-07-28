#pragma once
#include "singleton.h"
class cScore :public singleton<cScore>
{
public:
	int Score = 0;

};

#define SCORE cScore::Get()
