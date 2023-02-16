#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rules.h"
#include "utils/parsing.h"


static const char *get_table(table_t table)
{
    static const char *table_name;

    switch(table) {
        case RAW:
            table_name = "RAW";
            break;
        case NAT:
            table_name = "NAT";
            break;
        case MANGLE:
            table_name = "MANGLE";
            break;
        case SECURITY:
            table_name = "SECURITY";
            break;
        case FILTER:
        default:
            table_name = "FILTER";
            break;
    }

    return table_name;
}


static const char *get_chain(chain_t chain)
{
    static const char *chain_name;

    switch(chain) {
        case INPUT:
            chain_name = "INPUT";
            break;
        case OUTPUT:
            chain_name = "OUTPUT";
            break;
        case FORWARD:
            chain_name = "FORWARD";
            break;
        case PREROUTING:
            chain_name = "PREROUTING";
            break;
        case POSTROUTING:
            chain_name = "POSTROUTING";
            break;
        default:
            chain_name = "";
            break;
    }

    return chain_name;
}


static const char *get_rule(rule_t rule) {
    static const char *rule_name;

    switch(rule) {
        case ACCEPT:
            rule_name = "ACCEPT";
            break;
        case DROP:
            rule_name = "DROP";
            break;
        case QUEUE:
            rule_name = "QUEUE";
            break;
        case RETURN:
            rule_name = "RETURN";
            break;
        default:
            rule_name = "";
            break;
    }

    return rule_name;
}


char *make_rule(const char *fmt, ...)
{
	int rc = 9;
    char *cmd;
	va_list ap;

	va_start(ap, fmt);

    char *chain;
    char *table;
    char *rule;

	while (*fmt != '\0') {
		if (*fmt != '%') {
			continue;
		}

		switch (*++fmt) {
            case 'A':
            case 'C':
            case 'D':
            case 'V':
            case 'I':
            case 'R':
                chain = init_string(*fmt, get_chain(va_arg(ap, chain_t)));
                rc += strlen(chain);
                break;

            case 't':
                table = init_string(*fmt, get_table(va_arg(ap, table_t)));
                rc += strlen(table);
                break;

            case 'j':
                rule = init_string(*fmt, get_rule(va_arg(ap, rule_t)));
                rc += strlen(rule);
                break;
		}
		fmt++;
	}
    
	va_end(ap);
    cmd = concat_string(rc, "iptables ", table, chain, rule);
    free(table);
    free(chain);
    free(rule);

	return cmd;
}
