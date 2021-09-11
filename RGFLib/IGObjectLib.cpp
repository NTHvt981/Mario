#include "IGObjectLib.h"

namespace rgf
{
std::shared_ptr<IGObjectLib> IGObjectLib::m_instance = std::make_shared<IGObjectLib>( IGObjectLib() );

std::shared_ptr<IGObjectLib> IGObjectLib::GetInstance()
{
	return m_instance;
}
void IGObjectLib::Add( IGObject* const i_obj )
{
	m_gameObjects[i_obj->GetId()] = i_obj ;
}
int IGObjectLib::GetNewId()
{
	m_countId++;
	return m_countId;
}
}//namespace rgf