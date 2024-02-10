#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int location;
    int p, l, r;
    Node() {}
};

class Point {
    public:
    int id, x, y;
    Point() {}
    Point(int id, int x, int y): id(id), x(x), y(y) {}
    bool operator < (const Point &p) const {
        return id < p.id;
    }

    void print() {
        printf("%d\n", id);
    }
};

static const int MAX = 100000;
static const int NIL = -1;

int N;
Point P[MAX];

Node T[MAX];
int np;

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x;}
bool lessY(const Point &p1, const Point &p2) { return p1.y < p2.y;}

int makeKDTree(int l, int r, int depth) {
    if (!(l < r)) return NIL;
    int mid = (l + r) / 2;
    int t = np++;
    if (depth % 2 == 0) {
        sort(P + l, P + r, lessX);
    } else {
        sort(P + l, P + r, lessY);
    }
    T[t].location = mid;
    T[t].r = makeKDTree(l, mid, depth + 1);
    T[t].l = makeKDTree(mid + 1, r, depth + 1);

    return t;
}



int main() {

    return 0;
}