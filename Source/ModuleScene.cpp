#include "Globals.h"
#include "Application.h"
#include "ModuleScene.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "imgui.h"


#include <stdlib.h>
#include <time.h>

#define RADIUS 44

ModuleScene::ModuleScene(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleScene::~ModuleScene()
{}

// Load assets
bool ModuleScene::Start()
{
	myLOG("Loading Intro assets");
	bool ret = true;
	bool menu_win_opened = true;
	srand(time(NULL));
	

	return ret;
}

// Load assets
bool ModuleScene::CleanUp()
{
	myLOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleScene::Update(float dt)
{
	PPlane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	

	return UPDATE_CONTINUE;
}

void ModuleScene::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}