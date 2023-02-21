def check_chain(chain: str, flag: str):
    chains = ["OUTPUT", "FORWARD", "INPUT", "POSTROUTING", "PREROUTING"]
    flags = ["A", "C", "D", "V", "I", "R", "D", "S", "F", "L", "Z", "N", "X", "P", "E"]

    if chain not in chains:
        raise ValueError("The chain must be one of %r." % chains)
        
    if flag is not None and flag not in flags:
        raise ValueError("The chain flag must be one of %r." % flags)


def check_table(table: str):
    tables = ["FILTER", "NAT", "MANGLE", "RAW", "SECURITY"]

    if table not in tables:
        raise ValueError("The table must be one of %r." % tables)


def check_target(target: str):
    targets = ["ACCEPT", "DROP", "QUEUE", "RETURN", "PREROUTING"]
    
    if target not in targets:
        raise ValueError("The target must be one of %r." % targets)