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
    FORWARD
};


enum rule_t
{
    ACCEPT,
    DROP,
    QUEUE,
    PREROUTING,
    POSTROUTING,
    OUTPUT,
    RETURN
};


extern char *make_rule(void);