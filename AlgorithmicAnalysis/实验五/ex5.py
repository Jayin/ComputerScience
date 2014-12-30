# -*- coding: utf-8 -*-
__author__ = 'jayin'


def main(m=4, n=5, x=None, y=None):
    """

    :param m: 棋盘x轴大小
    :param n: 棋盘Y轴大小
    :param x: 马一开始的坐标x
    :param y: 马一开始的坐标x
    :return:
    """
    global ans,vis,dt_x,dt_y
    ans = 0
    # 这里应该是节点！
    vis = [[False] * (n + 1)] * (m + 1)
    dt_x = [1, 1, 2, 2, -1, -1, -2 ,- 2]
    dt_y = [2, -2, 1, -1, 2, -2, 1, -1]

    def work(cur_x, cur_y, step):
        global ans
        global vis
        if cur_x == x and cur_y == y and step >0:
                ans += 1
        else:
            for i in range(0, 8):
                _x = cur_x + dt_x[i]
                _y = cur_y + dt_y[i]
                if 1 <= _x <= m and 1 <= _y <= n and not vis[_x][_y]:
                    vis[_x][_y] = True
                    work(_x, _y, step + 1)
                    vis[_x][_y] = False

    work(x, y, 0)
    print(ans)


if __name__ == '__main__':
    for i in range(1,5):
        for j in range(1,6):
            print(i,j),'->'
            main(4,5,i,j)


