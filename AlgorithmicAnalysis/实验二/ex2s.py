# -*- coding: utf-8 -*-
__author__ = 'jayin'


def main(n=None):
    if n is None:
        n = int(raw_input('input n:'))
    print(pow(3, n - 1))


if __name__ == '__main__':
    main()
