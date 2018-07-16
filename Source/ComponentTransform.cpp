#include "ComponentTransform.h"

ComponentTransform::ComponentTransform(GameObject * _parent)
{
	GO_attached = _parent;
	active = true;
	type = COMPONENT_TRANSFORM;
	
}

ComponentTransform::~ComponentTransform()
{
}

void ComponentTransform::Update()
{
}

void ComponentTransform::SetLocalTransformMatrix(float4x4 trans)
{
	local_transform_matrix = trans;
}

float4x4 ComponentTransform::GetLocalTransform()const
{
	return local_transform_matrix;
}

void ComponentTransform::SetGlobalTransformMatrix(float4x4 trans)
{
	global_transform_matrix = trans;
}

float4x4 ComponentTransform::GetGlobalTransform() const
{
	return global_transform_matrix;
}
