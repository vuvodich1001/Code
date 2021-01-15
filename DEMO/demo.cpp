//PhanSO
#include <iostream>
using namespace std;

class PhanSo {
private:
    int a;
    int b;

public:
    void Nhap();
    void Xuat();
    PhanSo operator+(PhanSo a);
    PhanSo operator+(int a);
};

void PhanSo::Nhap() {
    cout << "Tu so: ";
    cin >> a;
    cout << "Mau so: ";
    cin >> b;
}

void PhanSo::Xuat() {
    cout << "Phan so: " << a << "/" << b << endl;
}

int main() {
    PhanSo a, b;
    a.Nhap();
    a.Xuat();
    return 0;
}