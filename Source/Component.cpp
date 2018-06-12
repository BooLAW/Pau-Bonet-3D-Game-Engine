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

bool Component::isActive() const
{
	return active;
}
