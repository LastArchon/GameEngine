#pragma once
namespace Core
{
	//a seperate enum class that can be used to label different system types, will only take unsigned ints that are one byte
	enum class SystemType : unsigned __int8
	{
		//by default these are in order, like it would be 0,1,2 etc unless specified
		WINDOW,
		INPUT,
		TOTAL_SYSTEMS
	};
	class System
	{

	public:
		const SystemType type;
		System(SystemType type);
		virtual ~System();

		virtual bool init(); 
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();
	};
}


