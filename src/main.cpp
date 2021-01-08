#include <stdlib.h>
#include <iostream>
#include "Watcher.h"

int main() {

	cwatch::Watcher watcher = cwatch::Watcher("");

	watcher.start();

	return EXIT_SUCCESS;
}