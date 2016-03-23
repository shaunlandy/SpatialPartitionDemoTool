#include "BruteForce.h"
#include "PartitionManager.h"
#include "PartitionObject.h"
#include "VBShape.h"

BruteForce::BruteForce()
{
	m_parent = nullptr;
	m_outline = nullptr;
	
	m_maxObjects = 0;
	m_maxLevels = 0;
}

BruteForce::~BruteForce()
{
	Clear();
}

void BruteForce::Insert(PartitionObject* _object)
{
	AssignObject(_object);
}

void BruteForce::Remove(PartitionObject* _object)
{
	m_objects.erase(_object->GetPartitionIterator());
	_object->SetCurrentPartition(nullptr);
}

void BruteForce::Update(PartitionObject* _object)
{
	Remove(_object);
	_object->s_partitionManager->GetCurrentRoot()->Insert(_object);
}

list<PartitionObject*> BruteForce::Retrieve(PartitionObject* _object)
{
	_object;
	list<PartitionObject*> retrieve;
	return retrieve;
}

//Clears away all objects and delete all children nodes
void BruteForce::Clear()
{
	//Set the current partition each object is part of to nullptr then clear the objects
	for (list<PartitionObject*>::iterator it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		(*it)->SetCurrentPartition(nullptr);
	}
	m_objects.clear();
}

Partition* BruteForce::FindPartition(Vector3 _pos, int _level)
{
	_pos;
	_level;
	return nullptr;
}

void BruteForce::Rebuild(list<PartitionObject*> _objects)
{
	Clear();
	for (list<PartitionObject*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
	{
		AssignObject(*it);
	}
}

void BruteForce::Rebuild()
{

}

void BruteForce::Tick(GameData* _GD)
{
	_GD;
}

void BruteForce::Draw(DrawData* _DD)
{
	_DD;
}