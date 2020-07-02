#include <iostream>
using namespace std;
struct node {
    int val;
    node* right;
    node* left;
};
node* create_node(int x) {
    node* p = new node;
    p->val = x;
    p->left = p->right = NULL;
    return p;
}
node* add_node(node* root, int x) {
    if (root == NULL) {
        root = create_node(x);
    }
    else if (x < root->val) {
        root->left = add_node(root->left, x);
    }
    else if (x > root->val) {
        root->right = add_node(root->right, x);
    }
    return root;
}
node* search(node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    else if (x < root->val) {
        return search(root->left, x);
    }
    else if (x > root->val) {
        return search(root->right, x);
    }
    else
        return root;
}
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh > rh) {
            return lh + 1;
        }
        else {
            return rh + 1;
        }
    }
}
void lnr(node* root) {
    if (root != NULL) {
        lnr(root->left);
        cout << root->val << " ";
        lnr(root->right);
    }
}
int main() {
    node* root = NULL;
    int x, val;
    while (true) {
        cin >> x;
        if (x == 0) break;
        if (x == 1) {
            cin >> val;
            root = add_node(root, val);
        }
        else if (x == 2) {
            cin >> val;
            cout << ((search(root, val) == NULL) ? "No" : "Yes") << endl;
        }
        else if (x == 3) {
            cout << "Height of tree is: " << height(root) << endl;
        }
        else if (x == 4) {
            cout << "print inorder\n";
            lnr(root);
        }
    }
    return 0;
}