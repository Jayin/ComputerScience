# -*- coding: utf-8 -*-
__author__ = 'jayin'

import requests
import threading


def buy_ticket():
    res = requests.get('http://localhost:8000/buy1')
    print threading.currentThread().getName() + u' buy ticket ' + res.content


def main():
    for x in range(1, 40):
        t = threading.Thread(target=buy_ticket, name=x)
        t.start()

if __name__ == '__main__':
    main()