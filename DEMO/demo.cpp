#include <iostream>
using namespace std;
#define max 100
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
bool search(list*& l, int val) {
    for (node* p = l->head; p != NULL; p = p->next) {
        if (p->val == val)
            return true;
    }
    return false;
}
void add_node(list*& l, int val) {
    node* p = create_node(val);
    if (l->head == NULL) {
        l->head = l->tail = p;
    }
    else {
        l->tail->next = p;
        l->tail = p;
    }
}
void insert(list* l[], int val) {
    int k = max % val;
    if (search(l[k], val)) {
        return;
    }
    else {
        add_node(l[k], val);
    }
}
int main() {
    int n;
    cin >> n;
    list* l[max];
    int selection, val;
    while (true) {
        cin >> selection;
        if (selection == 0) break;
        if (selection == 1) {
            cin >> val;
            insert(l, val);
        }
        // else if (selection == 2) {
        //     cin >> val;
        //     int k = max % val;
        //     cout << (search(l[k], val) == true ? "Yes" : "No") << endl;
        // }
    }
    return 0;
}