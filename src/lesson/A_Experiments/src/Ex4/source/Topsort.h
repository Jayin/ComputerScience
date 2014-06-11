#ifndef TOPSORT_H_
#define TOPSORT_H_

#include <list>
#include <queue>
#include <iostream>
using namespace std;

class Point {

public:

	Point(){
		this->id = 0;
		this->in = 0;
	}
	list<int> getEdges() {
		return this->edges;
	}

	void addEdge(int point) {
		if (point == id || point < 1)
			return;
		edges.push_back(point);
		edges.sort();
		edges.unique();
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	int getIn() const {
		return in;
	}

	void setIn(int in) {
		this->in = in;
	}

	void reduceIn() {
		this->in--;
	}

	void println() {
		cout << "id=" << id << " in=" << in << " edgesize=[";
		for (list<int>::iterator it = edges.begin(); it != edges.end(); it++) {
			cout << *it << ",";
		}
		cout << "]" << endl;
	}

private:
	//该点的编号
	int id;
	//该点的入度
	int in;
	//从该点连接到其他点的集合,保证唯一
	list<int> edges;
};

int m, n;

bool solve(Point* points) {
	int out = 0;
	queue<Point> q;
	for (int i = 1; i <= m; i++) {
		if (points[i].getIn() == 0)
			q.push(points[i]);
	}
	if(q.empty())
		return false;
	while (!q.empty()) {
		Point p = q.front();
		p.println();
		list<int> l = p.getEdges();
		q.pop();
		out++;
		for (list<int>::iterator it = l.begin();
				it != l.end(); it++) {
			points[*it].println();
			points[*it].reduceIn();
			if(points[*it].getIn() == 0){
				q.push(points[*it]);
			}
		}
	}
	return out == m;
}

Point* input() {
	cin >> m >> n;
	Point *points = new Point[m+1];
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		if (a < 1 || a > m || b < 1 || b > m || a == b) {
			cout << "ingore input :a=" << a << " b=" << b << endl;
			continue;
		}

		points[a].setId(a);
		points[b].setId(b);
		points[b].setIn(points[b].getIn() + 1);
		points[a].addEdge(b);
//		points[a].println();
//		points[b].println();
	}
	return points;
}

#endif
