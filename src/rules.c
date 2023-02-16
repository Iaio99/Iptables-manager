#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rules.h"


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

            break;
    }

    return rule_name;
}


char *make_rule(const char *fmt, ...)
{
//    char cmd[1024] = {0};
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
                chain = calloc(strlen(get_chain(va_arg(ap, chain_t))) + 3, sizeof(chain_t));
                chain[0] = '-';
                chain[1] = *fmt;
                chain[2] = ' ';
                strcpy(&chain[3], get_chain(va_arg(ap, chain_t)));
                rc += strlen(chain);
                break;

            case "t":
                table = calloc(strlen(get_table(va_arg(ap, table_t))) + 3, sizeof(table_t));
                table[0] = '-';
                table[1] = *fmt;
                table[2] = ' ';
                strcpy(&table[3], get_table(va_arg(ap, table_t)));
                rc += strlen(table);

            case "j":
                rule = calloc(strlen(get_rule(va_arg(ap, rule_t))) + 3, sizeof(rule_t));
                rule[0] = '-';
                rule[1] = *fmt;
                rule[2] = ' ';
                strcpy(&rule[3], get_rule(va_arg(ap, rule_t)));
                rc += strlen(rule);
		}
		fmt++;
	}
	va_end(ap);

    cmd = chain;
	return cmd;
}
