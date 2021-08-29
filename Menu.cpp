#include "Menu.h"

#include <iostream>
#include "Globals.h"

Menu::Menu()
{
}

void Menu::runMainMenu(std::vector<Event>& queue, bool& runApp)
{
	std::string inpString;
	
	if (!Globals::runInnitialized)
	{
		std::cout << "Enter command. For list of commands enter 'help'" << std::endl;
		Globals::runInnitialized = true;
	}

	std::cin >> inpString;

	if (inpString == "close")
	{
		queue.push_back(Event([&runApp]() { runApp = false; }));
	}
	else if (inpString == "help")
	{
		for (int i = 0; i < Globals::eventNames.size(); i++)
		{
			std::cout << i + 1 << ": " << Globals::eventNames[i] << std::endl;
		}
	}
	else
	{
		std::cout << "No such command: " << inpString << std::endl;
	}

	queue.push_back(Event([&queue, &runApp, this]() { runMainMenu(queue, runApp); }));

}
