#include <stdio.h>
#include <stdlib.h>

#include "io.h"

void error(char *message, int error_code)
{
    perror(message);
    exit(error_code);
}