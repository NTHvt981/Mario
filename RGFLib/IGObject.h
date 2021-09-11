#pragma once
#include <queue>
#include "IMessage.h"

namespace rgf
{
/// <summary>
/// gameobject implement basic life cycle (with update, render)
/// entity, scene, scene manager should inherit this class
/// </summary>
class IGObject
{
protected:
	std::queue<std::shared_ptr<IMessage>> m_messages = std::queue<std::shared_ptr<IMessage>>();
	int m_id;

public:
	IGObject( int id = -1 );
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	int GetId() { return m_id; }

protected:
	virtual void UpdateEpilogue();
	virtual void ProcessMessages();
	virtual void ProcessMessage(std::shared_ptr<IMessage> message) = 0;
};
} //namespace rgf