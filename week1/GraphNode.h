#pragma once
#include "stdafx.h"
class GraphNode
{
protected:
	int m_iIndex;
public:
	GraphNode() :m_iIndex{ invalid_node_index }{}
	GraphNode(int idx) :m_iIndex{ idx }{}

	virtual ~GraphNode();

	int Index()const { return m_iIndex; }
	void SetIndex(int NewIndex) { m_iIndex = NewIndex; }
};

