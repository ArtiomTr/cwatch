#include "Watcher.h"
#include "iostream"
#include "chrono"
#include <filesystem>
#include <thread>

cwatch::Watcher::Watcher(std::string inputFilePath) : inputFilePath{ inputFilePath } {
	std::filesystem::path filepath = std::filesystem::path(inputFilePath);
	if (std::filesystem::exists(filepath)) {
		std::cout << "Watcher initialized" << std::endl;
	}
	else {
		std::cout << "Watcher initialization failed: No file found at path " << filepath << std::endl;
		throw "Initialization exception";
	}
}

void cwatch::Watcher::start() {

	std::chrono::duration<int, std::milli> duration = std::chrono::milliseconds(100000);

	std::chrono::duration<int, std::milli> pauseDuration = std::chrono::milliseconds(100);

	std::chrono::system_clock::time_point point = std::chrono::system_clock::now() + duration;

	std::filesystem::path filepath = std::filesystem::path(inputFilePath);

	auto lastModifiedTime = std::filesystem::last_write_time(filepath);

	while (point > std::chrono::system_clock::now()) {
		std::this_thread::sleep_for(pauseDuration);
		auto currentModifiedTime = std::filesystem::last_write_time(filepath);
		if (currentModifiedTime != lastModifiedTime) {
			std::cout << "Modified!!!" << std::endl;
			lastModifiedTime = currentModifiedTime;
		}

	}

}