#pragma once
class cScene abstract
{
public:
	cScene();
	virtual ~cScene();
public:

	virtual void Init() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Release() PURE;
	virtual void Update() PURE;
	virtual void IUIRender() PURE;
	
};

