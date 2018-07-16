#ifndef __PANEL_HIERARCHY_H__
#define __PANEL_HIERARCHY_H__
#include "Globals.h"

class GameObject;

class PanelHierarchy {
public:
	void Update();
	void SetActive(bool active);
public:
	GameObject * Scene_root = nullptr;
	bool is_active = true;
};
#endif // !__PANEL_HIERARCHY_H__

void PanelHierarchy::SetActive(bool active)
{
	is_active = active;
}
