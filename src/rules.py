import os
import utils


parametrize = lambda x, y: str(x + y if x else "")


def do_rule(n="", table="", chain="", chain_flag="", target="", ipv6: bool=False):
    if chain is not "":
        utils.check_chain(chain, chain_flag)
    
    if table is not "":
        utils.check_table(table)

    if target is not "":
        utils.check_target(target)

    rule = f"{parametrize(table, '-t')}"

    e = os.system(f"iptables {rule}")
    if ipv6:
        e = os.system(f"ip6tables {rule}")

    return e


append_rule = lambda chain, table = "", target = "", ipv6 = False: do_rule(chain=chain, chain_flag="-A", table=table, target=target, ipv6=ipv6)
check_rule = lambda chain, table = "", target = "", ipv6 = False: do_rule(chain=chain, chain_flag="-C", table=table, target=target, ipv6=ipv6)
delete_rule = lambda chain, table = "", target = "", ipv6 = False: do_rule(chain=chain, chain_flag="-D", table=table, target=target, ipv6=ipv6)
insert_rule = lambda chain, table = "", target = "", ipv6 = False: do_rule(chain=chain, chain_flag="-I", table=table, target=target, ipv6=ipv6)
replace_rule = lambda chain, table = "", target = "", ipv6 = False: do_rule(chain=chain, chain_flag="-R", table=table, target=target, ipv6=ipv6)
list_rules = lambda chain="", ipv6 = False: do_rule(chain=chain, chain_flag="-L", ipv6=ipv6)
print_rules = lambda chain="", ipv6 = False: do_rule(chain=chain, chain_flag="-S", ipv6=ipv6)
flush_rules = lambda table="", chain="", ipv6 = False: do_rule(table=table, chain=chain, chain_flag="-F", ipv6=ipv6)
delete_chain = lambda table="", chain="", ipv6 = False: do_rule(table=table, chain=chain, chain_flag="-X", ipv6=ipv6)
new_chain = lambda chain, table="", ipv6 = False: do_rule(table=table, chain=chain, chain_flag="-N", ipv6=ipv6)