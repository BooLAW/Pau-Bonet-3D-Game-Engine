#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Globals.h"

class GameObject
{
	friend class Component;
public:
	GameObject();
	~GameObject();

	bool Start();
	bool Update();

	bool IsRoot()const;
	bool IsActive()const;
	bool IsStatic()const;

public:
	GameObject * parent = nullptr;
	std::string name = "GameObject";
	std::vector<GameObject*> childs;
	std::vector<Component*> components;

	bool is_root = false;
	bool is_static = false;
	bool is_active = false;

	//ComponentTransform* transform;
};
#endif
