#include "IGObject.h"

namespace rgf
{
IGObject::IGObject( int id )
{
	if (id == -1)
	{
		throw("Please provide a legit id");
	}
	m_id = id;
}
void IGObject::UpdateEpilogue()
{
	ProcessMessages();
}
void IGObject::ProcessMessages()
{
	while (!m_messages.empty())
	{
		ProcessMessage( m_messages.front() );
		m_messages.pop();
	}
}
} //namespace rgf