#pragma once
#include <memory>
#include <unordered_map>

#include "IGObject.h"

namespace rgf
{
/// <summary>
/// [singleton] manage game objects, add and get through id (int)
/// should only be include and access in game class
/// </summary>
class IGObjectLib
{
protected:
	static std::shared_ptr<IGObjectLib> m_instance;
	int m_countId = 0;
	std::unordered_map<int, IGObject*> m_gameObjects = std::unordered_map<int, IGObject*>();
	
public:
	static std::shared_ptr<IGObjectLib> GetInstance();
	void Add( IGObject* const i_obj );
	int GetNewId();
};
}//namespace rgf
