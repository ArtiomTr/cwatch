#include "log.h"

#define color_reset "\033[m"
#define prefix_color_fatal "\033[41m"
#define prefix_color_success "\033[42m"
#define prefix_color_warn "\033[43m"
#define message_color_fatal "\033[31m"
#define message_color_success "\033[32m"
#define message_color_warn "\033[33m"

bool _useColors = false;

void cwatch::logger::setUseColors(bool useColors) {
	_useColors = useColors;
}

void printToStdOut(std::string prefix, const char* prefixColor, std::string message, const char* messageColor) {
	if (_useColors && prefixColor != nullptr) {
		std::cout << prefixColor << prefix << ":" << color_reset;
	}
	else {
		std::cout << prefix << ":";
	}

	std::cout << " ";

	if (_useColors && messageColor != nullptr) {
		std::cout << messageColor << message << color_reset;
	}
	else {
		std::cout << message;
	}

	std::cout << std::endl;
}

void cwatch::logger::log(cwatch::logger::LogLevel level, std::string message) {

	switch (level) {
	case cwatch::logger::LogLevel::FATAL:
		printToStdOut("FATAL ERROR", prefix_color_fatal, message, message_color_fatal);
		exit(EXIT_FAILURE);
		break;
	case cwatch::logger::LogLevel::WARN:
		printToStdOut("WARNING", prefix_color_warn, message, message_color_warn);
		break;
	case cwatch::logger::LogLevel::INFO:
		std::cout << message << std::endl;
		break;
	case cwatch::logger::LogLevel::SUCCESS:
		printToStdOut("SUCCESS", prefix_color_success, message, message_color_success);
		break;
	default:
		std::cout << message << std::endl;
		break;
	}
}

void cwatch::logger::assert(bool condition, std::string error) {
	if (!condition) {
		log(LogLevel::FATAL, error);
	}
}