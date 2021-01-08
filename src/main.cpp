#include <stdlib.h>
#include <iostream>
#include "Watcher.h"
#include "log.h"

int main() {
	cwatch::logger::setUseColors(true);

	cwatch::Watcher watcher = cwatch::Watcher("");

	watcher.start();

	return EXIT_SUCCESS;
}