#pragma once

#include "./global/global.h"
#include "./printer/printer.h"

//GLOBAL CONSTANTS OBJECTS
Terminal terminal = Terminal();
Printer printer = Printer(terminal.width, terminal.height - 1);
