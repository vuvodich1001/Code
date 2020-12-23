#include <iostream>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;
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

node* research(node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    else if (val < root->val) {
        return research(root->left, val);
    }
    else if (val > root->val) {
        return research(root->right, val);
    }
    else
        return root;
}
int main() {
    int n;
    cout << "nhap gia tri n: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "\nXuat\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "hello world\n";
    cout << "Hello World\n";
    node* root = NULL;
    int val;
    while (true) {
        cin >> val;
        if (val == 1) {
            cin >> val;
            root = add_node(root, val);
        }
        else if (val == 2) {
            cin >> val;
            cout << ((research(root, val) == NULL) ? "NO" : "YES") << endl;
        }
        else if (val == 0) {
            break;
        }
    }
    return 0;
}