#include "App.h"

#include <iostream>
#include "Timer.h"

App::App()
{
	queue.push_back(Event([=]() { 
		Menu* menu = new Menu();
		menu_->runMainMenu(queue);
		}));
	auto f = [=]() { run_(); };
	while (runApp)
	{
		Timer t{ 10, f };
	}
}

void App::run_()
{
	if (queue.size() > 0)
	{
		queue[0].executeEvent();
		queue.erase(queue.begin());
	}
}