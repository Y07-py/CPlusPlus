#include <bits/stdc++.h>
using namespace std;

struct Node {
    int Key;
    Node *prev, *next;
};

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int Key) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->Key = Key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

Node* listSearch(int key) {
    Node *cur = nil->next;
    while (cur != nil && cur->Key != key) {
        cur = cur->next;
    }
    return cur;
}

void deleteNode(Node *t) {
    if (t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}