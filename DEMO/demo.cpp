#include <iostream>
using namespace std;
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
    return 0;
}