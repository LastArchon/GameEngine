#include "stdafx.h"
#include "MainScene.h"
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}
bool MainScene::init()
{
	
	std::cout << "Scene is initialized" << std::endl;

	return true;
 }
void MainScene::update()
{
	using namespace Core;
	SystemManager* sm = Core::SystemManager::getInstance();
	System* systemDontKnowYet = sm->GetSystem(Core::SystemType::INPUT);
	InputSystem* inputSystem = dynamic_cast<InputSystem*>(systemDontKnowYet);
	
	//std::cout << "Scene is updated" << std::endl;
 }
void MainScene::draw() const
{
	//std::cout << "Scene is drawn" << std::endl;
 }
bool MainScene::shutdown()
{
	return true;
 }
