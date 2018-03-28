#pragma once
#include "Manager.h"
#include "System.h"
#include <vector>

namespace Core
{
	/*
	to make this better, do the same thing with templates
	*/
	
	class SystemManager : public Manager
	{
		std::vector <class System*> systems;
	
		SystemManager();
	static SystemManager* s_instance;
	public:
		~SystemManager();

		 bool init();
		 void update();
		 void draw() const ;
		 bool shutdown();

		 static SystemManager* getInstance()
		 {
			 if (s_instance == NULL)
			 {
				 s_instance = new SystemManager();
			 }
			 return s_instance;
		 }

		 System* GetSystem(SystemType st)
		 {
			 for(System* s : systems)
			 {
				 if (s->type == st)
				 {
					 return s;
				 }
				 
			 }
			 return nullptr;
		 } 
	};
}

