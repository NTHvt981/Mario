#pragma once

#include "IGObject.h"
#include "Box.h"
#include "Vector.h"
#include "ISprite.h"

namespace rgf
{
//TODO add entity(have collision, physic) inherit gameobject
class IEntity: public IGObject
{
protected:
	Vector m_position;
	Vector m_size;
	/// <summary>
	/// For rendering
	/// </summary>
	Vector m_origin;
	/// <summary>
	/// calculate from position and size
	/// </summary>
	Box<float> m_physicBox;

protected:
	void SetSizeSameAsAnimation();
	void SetSizeSameAsSprite(ISprite *sprite);
	void UpdatePhysicBox();
};
} //namespace rgf