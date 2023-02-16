#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void error(char *message, int error_code)
{
    perrror(stderr, "Input invalid\n");
    exit(error_code);
}