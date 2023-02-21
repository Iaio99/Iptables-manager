import os


class Table:
    def __init__(self, table: str):
        self.__table = table.upper()
        tables = ["FILTER", "NAT", "MANGLE", "RAW", "SECURITY"]

        if self.__table not in tables:
            raise ValueError("The table must be one of %r." % tables)
        
        self.__flag = "-t"

    def __str__(self):
        return f"{self.__flag} {self.__table}"


class Chain:
    def __init__(self, chain: str, flag: str):
        self.__chain = chain.upper()
        self.__flag = flag.upper()

        chains = ["OUTPUT", "FORWARD", "INPUT", "POSTROUTING", "PREROUTING"]
        flags = ["A", "C", "D", "V", "I", "R", "S", "F", "L", "Z", "X", "P"]

        if self.__chain not in chains:
            raise ValueError("The table must be one of %r." % chains)

        if self.__flag not in flags:
            raise ValueError("The table must be one of %r." % flags)
        

    def __str__(self):
        return f"-{self.__flag} {self.__chain}"


class Target:
    def __init__(self, target: str):
        self.__target = target.upper()
        self.__flag = "-j"

        targets = ["ACCEPT", "DROP", "QUEUE", "RETURN", "PREROUTING"]

        if self.__target not in targets:
            raise ValueError("The table must be one of %r." % targets)
        
    def __str__(self):
        return f"{self.__flag} {self.__target}"


class Interface:
    pass


class Address:
    pass


class Rule:
    def __init__(self, chain, target, table=None, port=None, protocol=None, src=None, dst=None, in_interface=None, out_interface=None):
        self.__table = Table(table)
        self.__chain = Chain(chain, "A")
        self.__target = Target(target)
        self.__port = port
        self.__protocol = protocol
        self.__src = src
        self.__dst = dst
        self.__in_interface = in_interface
        self.__out_interface = out_interface

    def __str__(self):
        return f"iptables {str(self.__table)} {str(self.__chain)} {str(self.__port or '')} {str(self.__protocol or '')} {str(self.__src or '')} {str(self.__dst or '')} {str(self.__in_interface or '')} {str(self.__out_interface or '')}"

    def add_rule(self):
        os.system(str(self))