#include "Menu.h"

#include <iostream>

Menu::Menu()
{
}

void Menu::runMainMenu(std::vector<Event>& queue)
{
	queue.push_back(Event([]() {std::cout << "Hi\n"; }));
	//� ��� ����� ��������� ����� ������ ����� � ������� queue, ����� ������, ����� ������ :)))
}