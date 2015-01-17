#pragma once
#include "IFSM.h"

namespace Tmpl8
{
	class Graph;
	class IFSMCow :	public IFSM 
	{
	public:
		IFSMCow(){};
		virtual void execute(){};
		virtual ~IFSMCow(){};
	};

}