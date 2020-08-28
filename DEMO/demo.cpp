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
    p->left = NULL;
    p->right = NULL;
}
node* add_node(node* root, int val) {
    node* newnode = create_node(val);
    if (root == NULL) {
        root = newnode;
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
    if (root == NULL)
        return NULL;
    else if (val < root->val) {
        return search(root->left, val);
    }
    else if (val > root->val) {
        return search(root->right, val);
    }
    else
        return root;
}
void LNR(node* root) {
    if (root) {
        LNR(root->left);
        cout << root->val << " ";
        LNR(root->right);
    }
}
int main() {
    node* root = NULL;
    int val, x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        if (x == 1) {
            cin >> val;
            root = add_node(root, val);
        }
        else if (x == 2) {
            cin >> val;
            cout << (search(root, val) != NULL ? 1 : 0) << endl;
        }
        else if (x == 3) {
            LNR(root);
        }
    }
    return 0;
}