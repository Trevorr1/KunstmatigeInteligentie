#pragma once
#include "GraphNode.h"
#include "template.h"
#include "stdafx.h"

namespace Tmpl8 {
	class NavGraphNode : public GraphNode
	{
	protected:

		//the node's position
		vector3 m_vPosition;

	public:
		NavGraphNode(){}
		NavGraphNode(int idx, float x, float y, float z) 
			: GraphNode{idx}
			{
				m_vPosition = vector3(x, y, z);
			}

		virtual ~NavGraphNode();

		vector3 Position(){ return m_vPosition; }
	};
} // namespace Tmpl8