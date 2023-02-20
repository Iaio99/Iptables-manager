from argparse import ArgumentParser


def main():
    parser = ArgumentParser()

#    parser.add_argument("ssid", help="SSID of wifi connection hotspot", type=str)

    args = parser.parse_args()


if __name__ == "__main__":
    main()