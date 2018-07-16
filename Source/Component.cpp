#include "Component.h"

void Component::Enable()
{
	if (!active)
		active = true;
}

void Component::Disable()
{
	if (active)
		active = false;
}

void Component::Update()
{
}

bool Component::isActive() const
{
	return active;
}
