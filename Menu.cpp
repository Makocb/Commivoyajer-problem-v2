#include "Menu.h"

#include <iostream>

Menu::Menu()
{
}

void Menu::runMainMenu(std::vector<Event>& queue)
{
	queue.push_back(Event([]() {std::cout << "Hi\n"; }));
	//и тут можно добавлять сколь угодно шагов в очередь queue, когда угодно, сколь угодно :)))
}