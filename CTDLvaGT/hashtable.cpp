#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>
using namespace std;
//===============HASH TABLE===============
#define size 100000
struct node {
    int val;
    node* next;
};
struct list {
    node* head;
    node* tail;
    list() {
        head = tail = NULL;
    }
};
node* create_node(int val) {
    node* p = new node;
    p->val = val;
    p->next = NULL;
    return p;
}
void add_tail(list& l, int val) {
    node* p = create_node(val);
    if (l.head == NULL) {
        l.head = l.tail = p;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
bool find(list l, int val) {
    for (node* p = l.head; p != NULL; p = p->next) {
        if (p->val == val) {
            return true;
        }
    }
    return false;
}
void insert(list*& l, int val) {
    int k = val % size;
    if (find(l[k], val))
        return;
    else {
        add_tail(l[k], val);
    }
}
bool search_hash(list* l, int val) {
    int k = val % size;
    return find(l[k], val);
}
//===============BINARY SEARCH TREE===============
struct tree {
    int val;
    tree* left;
    tree* right;
};
tree* create_tree(int val) {
    tree* p = new tree;
    p->val = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}
tree* add_node(tree*& root, int val) {
    if (root == NULL) {
        root = create_tree(val);
    }
    else if (val < root->val) {
        root->left = add_node(root->left, val);
    }
    else if (val > root->val) {
        root->right = add_node(root->right, val);
    }
    return root;
}
tree* search_tree(tree* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    else if (val < root->val) {
        return search_tree(root->left, val);
    }
    else if (val > root->val) {
        return search_tree(root->right, val);
    }
    else {
        return root;
    }
}
void lnr(tree* root) {
    if (root != NULL) {
        lnr(root->left);
        cout << root->val << " ";
        lnr(root->right);
    }
}
int main() {
    using namespace std::chrono;
    list* l = new list[size];
    tree* root = NULL;
    srand(time(NULL));
    int x;
    for (int i = 0; i < size; i++) {
        x = rand() * rand();
        insert(l, x);
        root = add_node(root, x);
    }
    int val;
    cout << "Nhap gia tri can tim: ";
    cin >> val;
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span;

    //hash table
    t1 = high_resolution_clock::now();
    search_hash(l, val);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "\nHash table tooks me " << (size_t)time_span.count() << " seconds\n\n";

    //binary search tree
    t1 = high_resolution_clock::now();
    search_tree(root, val);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double>>(t2 - t1);
    cout << "Binary search tree tooks me " << (size_t)time_span.count() << " seconds\n";
    return 0;
}