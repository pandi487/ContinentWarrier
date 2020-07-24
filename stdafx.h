#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <map>

using namespace std;
#define g_device DXUTGetD3D9Device()
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
const int WINSIZEX = 1600;
const int WINSIZEY = 900;
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


#include "cImageManager.h"
#include "cObjectManager.h"
#include "cSceneManager.h"
#include "cRenderManager.h"
#include "cKeyManager.h"
