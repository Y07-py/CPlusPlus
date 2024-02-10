#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int value;
    Node *parent, *right, *left;
};

Node *root, *NIL;

void insert(int k) {
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->value = k;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->value < x->value) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NIL) {
        root = z;
    } else {
        if (z->value < y->value) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}