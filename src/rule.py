from enum import Enum, auto


class Table(Enum):
    RAW = auto()
    FILTER = auto()
    NAT = auto()
    MANGLE = auto()
    SECURITY = auto()


class Chain(Enum):
    INPUT = auto()
    OUTPUT = auto()
    FORWARD = auto()
    PREROUTING = auto()
    POSTROUTING = auto()


class Rule(Enum):
    ACCEPT = auto()
    DROP = auto()
    QUEUE = auto()
    RETURN = auto()