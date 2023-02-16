#pragma once

#include <stdarg.h>


typedef enum table
{
    RAW,
    FILTER,
    NAT,
    MANGLE,
    SECURITY
}table_t;


typedef enum chain
{
    INPUT,
    OUTPUT,
    FORWARD,
    PREROUTING,
    POSTROUTING
}chain_t;


typedef enum rule
{
    ACCEPT,
    DROP,
    QUEUE,
    RETURN
}rule_t;


extern char *make_rule(const char *fmt, ...);
static const char *get_table(table_t table);
static const char *get_chain(chain_t chain);
static const char *get_rule(rule_t rule);