#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void error(char *message, int error_code)
{
    perror(message);
    exit(error_code);
}


char *init_string(char flag, const char *parameter)
{
    size_t len = 3 + sizeof(flag) + strlen(parameter);
    char *buffer = calloc(len, sizeof(char));
    
    buffer[0] = '-';
    buffer[1] = flag;
    buffer[2] = ' ';
    strcpy(&buffer[3], parameter);
    buffer[len-1] = ' ';

    return buffer;
}

char *concat_string(size_t rc, ...) 
{
    char *dst = calloc(rc, sizeof(char));
    char *src;
    va_list ap;
    va_start(ap, rc);

    while(rc > 0) {
        src = va_arg(ap, char *);
        strcat(dst, src);
        rc -= strlen(src);
    }

    va_end(ap);
    dst[rc-1] = 0;

    return dst;
}