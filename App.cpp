#include "App.h"

#include <iostream>
#include "Timer.h"
#include "Globals.h"

App::App()
{
	queue.push_back(Event([=]() { 
		Menu* menu = new Menu();
		menu_->runMainMenu(queue, runApp);
		}) );
	auto f = [=]() { run_(); };
	while (runApp)
	{
		Timer t{ 10, f };
	}
	std::cout << Globals::lineSeparator << std::endl << "End of events" << std::endl;
}

void App::run_()
{
	if (queue.size() > 0)
	{
		queue[0].executeEvent();
		queue.erase(queue.begin());
	}
}