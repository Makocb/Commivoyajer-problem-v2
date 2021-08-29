#pragma once

#include <vector>
#include <string>

namespace Globals
{
	const int defaultGenerationMin = 0;
	const int defaultGenerationMax = 10;
	const int defaultSize = 5;

	extern bool runInnitialized;

	const std::vector<std::string> eventNames = { "close", "help" };

	const std::string lineSeparator = "====================";
}
