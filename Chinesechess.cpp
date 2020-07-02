#include <iostream>
using namespace std;
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
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}
void print_list(list& l) {
    for (node* p = l.head; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
}
int main() {
    list l;
    while (true) {
        int x;
        cin >> x;
        if (x == 0) break;
        if (x == 1) {
            int val;
            cin >> val;
            add_tail(l, val);
        } else if (x == 2) {
            cout << "list:\n";
            print_list(l);
        }
    }
    return 0;
}