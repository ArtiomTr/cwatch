#pragma once

#include <string>
#include <iostream>

namespace cwatch {

	namespace logger {

		enum class LogLevel {
			FATAL = -2,
			WARN = -1,
			INFO = 0,
			SUCCESS = 1
		};

		void setUseColors(bool useColors);

		void assert(bool condition, std::string error);

		void log(LogLevel level, std::string message);

	} // namespace logger

} // namespace cwatch
