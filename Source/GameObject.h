#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "Globals.h"
#include "MathGeoLib\MathGeoLib.h"

class Component;
class ComponentTransform;
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

	void PushComponent(Component* comp);

public:
	GameObject* parent = nullptr;
	std::string name = "GameObject";
	UID unique_id = -1;
	std::vector<GameObject*> childs;
	std::vector<Component*> components;

	bool is_root = false;
	bool is_static = false;
	bool is_active = false;

	ComponentTransform* transform;
};
#endif
