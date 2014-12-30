# -*- coding: utf-8 -*-
__author__ = 'jayin'
import sys
import copy


def main(m=None, n=None, k=None, s=None):
    if m is None:
        m = int(raw_input('输入全程m公里:'))
        n = int(raw_input('输入加满油可行驶n公里:'))
        k = int(raw_input('输入共有k个加油站'))
    global count
    global ans
    count = sys.maxsize
    tmp = ans = []

    def work(cur, k):
        global count
        global ans
        if k >= count:
            return
        if cur + n >= m:
            if count > len(tmp):
                count = len(tmp)
                ans = copy.deepcopy(tmp)
                ans.append(cur + n)
        else:
            for x in s:
                if cur < x <= cur + n:
                    tmp.append(x)
                    work(x, k + 1)
                    tmp.pop()

    for x in s:
        if x <= n:
            tmp.append(x)
            work(x, 0)
            tmp.pop()
    print(count)
    print(ans)


if __name__ == '__main__':
    main(60, 20, 6, [10, 20, 30, 40, 50, 60])


