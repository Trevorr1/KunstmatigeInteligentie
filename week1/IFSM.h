#pragma once

#include "Graph.h"

namespace Tmpl8
{
	class Graph;
	class IFSM
	{
	public:
		IFSM() {};
		virtual ~IFSM() {};

		virtual void execute() {};
		virtual int getState() { return 0; };
	protected:
		int m_StateID;
	};

} //namespace

