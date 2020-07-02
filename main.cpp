#include <iostream>
using namespace std;
struct node {
    int val;
    node* right;
    node* left;
};
node* create_node(int val) {
    node* p = new node;
    p->val = val;
    p->left = p->right = NULL;
    return p;
}
node* add_node(node* root, int val) {
    if (root == NULL) {
        root = create_node(val);
    }
    else if (val < root->val) {
        root->left = add_node(root->left, val);
    }
    else if (val > root->val) {
        root->right = add_node(root->right, val);
    }
    return root;
}
node* search(node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    else if (val < root->val) {
        return search(root->left, val);
    }
    else if (val > root->val) {
        return search(root->right, val);
    }
    else {
        return root;
    }
}
int main() {
    node* root = NULL;
    int x, val;
    while (true) {
        cin >> x;
        if (x == 0) break;
        switch (x) {
        case 1:
            cin >> val;
            root = add_node(root, val);
            break;
        case 2:
            cin >> val;
            cout << ((search(root, val) == NULL) ? "NO" : "YES") << endl;
            break;
        }
    }
    return 0;
}