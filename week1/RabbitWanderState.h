#pragma once
#include "IFSMRabbit.h"

namespace Tmpl8
{
	class Graph;
	class RabbitWanderState : public IFSMRabbit
	{
	public:
		RabbitWanderState();
		virtual ~RabbitWanderState();
		void execute();
	};

}

