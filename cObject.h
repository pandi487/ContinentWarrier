#pragma once
class cObject abstract
{
private:
	FLOAT Rotation=0;
	RECT rt;
	Vec2 pos;
	bool m_Die = false;
	string Tag = "";
	string CollTag= "";
public:
	cObject();
	virtual ~cObject();
public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Collision(cObject * obj) PURE;
public:
	Vec2 GetPos() { return pos; }
	void SetPos(Vec2 p) { pos = p; }
	void ObjDie() { m_Die = true; }
	bool IsDie() { return m_Die; }
	void SetTag(string name) { Tag = name; }
	string GetTag() { return Tag; }
	RECT GetRect() { return rt; }

	string GetCollTag() { return CollTag; }
	void SetCollTag(string T) { CollTag = T; }

	void SetRot(FLOAT a) { Rotation = a; }
	FLOAT GetRot() { return Rotation; }


	bool OutMap(Vec2 pros) { return (pros.x > WINSIZEX / 2 || pros.x < -WINSIZEX / 2 || pros.y < -WINSIZEY / 2 || pros.y > WINSIZEY / 2); };

	void SetRect(Vec2 pos, cTexture * texturePtr) { rt = {long(pos.x - texturePtr->info.Width/2),long(pos.y - texturePtr->info.Height / 2),long(pos.x + texturePtr->info.Width / 2),long(pos.y + texturePtr->info.Height / 2) }; }
};

