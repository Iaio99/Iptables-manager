#pragma once


enum table_t
{
    RAW,
    FILTER,
    NAT,
    MANGLE,
    SECURITY
};


enum chains_t
{
    INPUT,
    OUTPUT,
    FORWARD,
    PREROUTING,
    POSTROUTING
};


enum rule_t
{
    ACCEPT,
    DROP,
    QUEUE,
    RETURN
};


extern char *make_rule(void);