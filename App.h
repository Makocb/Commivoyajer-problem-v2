#pragma once

#include "Menu.h"

class App
{
	public:
		bool runApp = true;
		std::vector<Event> queue;

		App();

	private:
		Menu* menu_ = nullptr;
		void run_();
};

