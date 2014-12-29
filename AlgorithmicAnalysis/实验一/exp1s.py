# -*- coding: utf-8 -*-
"""
全排非列递归实现
"""


def main(n=None):
    cur = {}

    def next_list(cur, n):
        last_num = n - 1
        cur_item = 0
        flag = False
        for i in range(0, last_num)[::-1]:
            if cur[i] < cur[i + 1]:
                flag = True
                cur_item = i
                break
        if flag:
            tmp_min_num = cur_item + 1
            # 找比cur[cur_item]大 且最小的数
            for i in range(tmp_min_num, last_num + 1):
                if (cur[i] > cur[cur_item] and cur[i] < cur[tmp_min_num]):
                    tmp_min_num = i
            cur[tmp_min_num], cur[cur_item] = cur[cur_item], cur[tmp_min_num]
            # 反向交换
            i = cur_item + 1
            j = last_num
            while i < j:
                cur[i], cur[j] = cur[j], cur[i]
                i += 1
                j -= 1
            print(cur.values())
            return True
        return False

    if n is None:
        n = int(raw_input('input n:'))
    for i in range(0, n):
        cur[i] = i + 1

    print(cur.values())
    total = 1
    while next_list(cur, n):
        total += 1

    print(total)


if __name__ == '__main__':
    main()






