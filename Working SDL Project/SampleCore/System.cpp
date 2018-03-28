#include "stdafx.h"
#include "System.h"

namespace Core
{
	System::System(SystemType type) : type(type)

	{
	}


	System::~System()
	{
		
	}
	bool System::init()
	{
		return true;
	}
	void System::update()
	{

	}
	void System::draw() const
	{

	}
	bool System::shutdown()
	{	
		return true;
	}
}


