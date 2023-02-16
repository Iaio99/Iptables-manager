#pragma once

#include <stdarg.h>

extern char *init_string(char flag, const char *parameter);
extern char *concat_string(size_t rc, ...);