#ifndef __COMPONENT_TRANSFORM_H__
#define __COMPONENT_TRANSFORM_H__

#include "Component.h"
#include "MathGeoLib\MathGeoLib.h"

struct Transform {
	float3 position = float3::zero;
	Quat rotation = Quat::identity;
	float3 scale = float3::one;
};
class ComponentTransform : public Component
{

public:
	ComponentTransform(GameObject* parent);
	~ComponentTransform();
	void Update();
	//Set&Get Pos
	void SetLocalTransformMatrix(float4x4 trans);
	float4x4 GetLocalTransform()const;
	void SetGlobalTransformMatrix(float4x4 trans);
	float4x4 GetGlobalTransform()const;

	
public:
	Transform global_transform;
	Transform local_transform;

	float4x4 global_transform_matrix;
	float4x4 local_transform_matrix;

};
#endif // !__COMPONENT_TRANSFORM_H__
