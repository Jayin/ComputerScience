# -*- coding: utf-8 -*-
__author__ = 'jayin'
import sys
import copy


def main(c=None, s=None, n=None, w=None, t=None, v=None):
    """
    :param c:容量
    :param s:容积
    :param n:物品数
    :param w:物品重量
    :param t:物品体积
    :param v:物品价值
    :return:
    """
    if c is None:
        raise Exception('参数有误')
    global ans
    global ans_list
    ans = 0
    ans_list = []
    tmp_list = []

    def work(cur_c, cur_s, cur_v, step):
        global ans
        global ans_list
        if step == n:
            if cur_v > ans :
                ans = cur_v
                ans_list = copy.deepcopy(tmp_list)
                # print(ans_list)
                # print(ans)
        else:
            for x in [0, 1]:
                if x == 1:
                    if cur_c + w[step] <= c and cur_s + t[step] <= s:
                        tmp_list.append(step)
                        work(cur_c + w[step], cur_s + t[step], cur_v + v[step], step + 1)
                        tmp_list.pop()
                else:
                    work(cur_c, cur_s, cur_v, step + 1)

    work(0, 0, 0,0)
    print(ans)
    print(ans_list)


if __name__ == '__main__':
    main(60,40,5,[10,20,20,10,40],[10,20,30,75,5],[25,20,40,80,60])