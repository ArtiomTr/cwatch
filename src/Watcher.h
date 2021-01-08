#pragma once

#include <string>

namespace cwatch {

	class Watcher {
	private:
		std::string inputFilePath;
	public:
		Watcher(std::string inputFilePath);

		void start();
	};

} // namespace cwatch
