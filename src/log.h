#pragma once

#include <string>
#include <iostream>

namespace cwatch {

	namespace logger {

		/// <summary>
		/// Log level enum. Used in logger::log function.
		/// </summary>
		enum class LogLevel {
			// Fatal error occured, exit the program.
			FATAL = -2,
			// A warning message to alert the user.
			WARN = -1,
			// Simple informational message.
			INFO = 0,
			// Message, if some process completed successfully.
			SUCCESS = 1
		};

		/// <summary>
		/// Determine if the output should be colored or not.
		/// </summary>
		void setUseColors(bool useColors);

		/// <summary>
		/// Asserts the condition.
		/// If it is not, calls logger::log with logger::LogLevel::FATAL,
		/// what results in printing error into stdout and exiting with error code 1.
		/// </summary>
		/// <param name="condition"> - Condition, which will be asserted</param>
		/// <param name="error"> - Error, which will be outputed into stdout.</param>
		void assert(bool condition, std::string error);


		/// <summary>
		/// Logs output into stdout. 
		/// Log level determines the style of message.
		/// If level is FATAL, program exits with error code.
		/// </summary>
		/// <param name="level"> - Specify message severity.</param>
		/// <param name="message"> - Message, which will be outputed into stdout.</param>
		void log(LogLevel level, std::string message);

	} // namespace logger

} // namespace cwatch
