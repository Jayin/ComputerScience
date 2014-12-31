# -*- coding: utf-8 -*-
__author__ = 'jayin'
"""
深搜验证
"""

table = {
    'a': {
        'a': 'b',
        'b': 'b',
        'c': 'a'
    },
    'b': {
        'a': 'c',
        'b': 'b',
        'c': 'a'
    },
    'c': {
        'a': 'a',
        'b': 'c',
        'c': 'c'
    }
}

total = 0


def main(n=None):
    if n is None:
        n = int(raw_input('input n:'))
    ans = []

    def print_ans():
        ans_string = ''
        for x in ans:
            ans_string += x + '*'
        print(ans_string.rstrip('*'))

    def work(cur, step):
        if step == n + 1 :
            if cur == 'a':
                print_ans()
                global total
                total += 1
        else:
            for c in ['a', 'b', 'c']:
                tmp = cur
                ans.append(c)

                work(table[cur][c], step + 1)
                cur = tmp
                ans.pop()
    if n <= 0 :
        print('Error : n > 0')
    elif n == 1:
        print(1)
    else:
        for c in ['a', 'b', 'c']:
            ans.append(c)
            work(c, 2)
            ans.pop()
        print(total)

if __name__ == '__main__':
    main()







