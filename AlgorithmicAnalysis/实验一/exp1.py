# -*- coding: utf-8 -*-
"""
全排列递归实现
"""


def main(n=None):
    vis = {}
    ans = {}
    global total
    total = 0


    def full_array(step):
        if step == n + 1:
            print ans.values()
            global total
            total += 1
            return

        for x in range(1, n + 1):
            if not vis[x]:
                vis[x] = True
                ans[step] = x
                full_array(step + 1)
                vis[x] = False
                ans[step] = 0

    if n is None:
        n = int(raw_input('input n:'))

    for i in range(1, n + 1):
        vis[i] = False
        ans[i] = 0

    full_array(1)
    print(total)


if __name__ == '__main__':
    main()





