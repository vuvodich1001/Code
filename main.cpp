#include <iostream>
using namespace std;
class Person {
protected:
    int val;
    string name;

public:
    void Nhap();
    void Xuat();
};
int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << i;
    }
    while (true) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << "hello world\n";
        }
        else if (x == 1) {
            cout << "Duoc roi ne\n";
        }
        else if (x == 2) {
            cout << "dc cua lo\n";
        }
        else if (x == 0) {
            break;
        }
    }
    return 0;
}