#include "GameObject.h"
#include "ComponentTransform.h"

GameObject::GameObject()
{
	parent = nullptr;

	math::LCG random;
	unique_id = random.Int();

	is_root = false;
	is_active = true;
	is_static = false;

	ComponentTransform* new_trans = new ComponentTransform(this);

}

GameObject::~GameObject()
{
}

bool GameObject::Start()
{
	return false;
}

bool GameObject::Update()
{
	return false;
}

bool GameObject::IsRoot() const
{
	return is_root;
}

bool GameObject::IsActive() const
{
	return is_active;
}

bool GameObject::IsStatic() const
{
	return is_static;
}

void GameObject::PushComponent(Component * comp)
{
	components.push_back(comp);
	myLOG("New Component");
}
