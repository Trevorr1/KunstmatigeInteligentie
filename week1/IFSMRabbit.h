#pragma once
#include "IFSM.h"

namespace Tmpl8
{
	class Graph;
	class IFSMRabbit : public IFSM 
	{
	public:
		IFSMRabbit(){};
		virtual void execute(){};
		virtual ~IFSMRabbit(){};
	};

}