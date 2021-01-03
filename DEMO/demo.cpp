#include <iostream>
using namespace std;
int main() {
    cout << "hello world\n";
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