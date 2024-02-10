#include <bits/stdc++.h>
#include <mm_malloc.h>
using namespace std;
typedef long long ll;

struct Node {
    int value;
    Node *prev, *next;
};

Node *nil;

void init() {
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int value) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->value = value;
    x->next = nil->next;
    nil->next = x;
    x->prev = v;
}

int main() {
    return 0;
}