#pragma once
#include "Module.h"
#include "Globals.h"
#include "Primitive.h"
#include "GameObject.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleScene : public Module
{
public:
	ModuleScene(Application* app, bool start_enabled = true);
	~ModuleScene();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	void AddGameObject();
	bool IsEmpty();
	int GetGOSize();
	GameObject* GetGameObject(int id);

public:
	GameObject * root_node;
	std::vector<GameObject*> GO_list;
};
