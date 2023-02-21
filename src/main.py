from argparse import ArgumentParser
#from rule import Rule


def main():
    parser = ArgumentParser()

    parser.add_argument("ACTION", choices=["nat", "openvpn", "dhcp", "restore", "save", "reset"])

    args = parser.parse_args()


if __name__ == "__main__":
    main()