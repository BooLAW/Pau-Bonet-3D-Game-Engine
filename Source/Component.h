#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class GameObject;
enum c_type
{
	COMPONENT_MESH_RENDERER,
	COMPONENT_TRANSFORM,
	COMPONENT_CAMERA,
	COMPONENT_MATERIAL,
	COMPONENT_NULL

};
class Component
{
private:
	Component() {};
	~Component() {};

	c_type type;
	bool active = false;
	virtual void Enable();
	virtual void Disable();
	virtual void Update();

	bool isActive()const;
protected:
	GameObject* GO_attached;
};
#endif // !__COMPONENT_H__
