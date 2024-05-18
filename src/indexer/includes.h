#ifndef INCLUDES_H
#define INCLUDES_H

void setupPlatform(int argc, char *argv[]);
void setupApp(int argc, char *argv[]);

// platform specific include
#include "includesLinux.h"

#endif // INCLUDES_H
