#include <iostream>
using namespace std;
class dathuc {
protected:
    int* heso;
    int bac;

public:
    dathuc() {
        heso = NULL;
        bac = 0;
    }
    dathuc(int bac) {
        this->bac = bac;
        heso = new int[this->bac + 1];
        for (int i = 0; i <= this->bac; i++) {
            heso[i] = 0;
        }
    }
    void Nhap();
    void Xuat();
    dathuc operator+(const dathuc& a);
};
void dathuc::Nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> bac;
    heso = new int[bac + 1];
    for (int i = 0; i <= bac; i++) {
        cin >> heso[i];
    }
}
void dathuc::Xuat() {
    for (int i = 0; i <= bac; i++) {
        if (heso[i] > 0 && i != 0) cout << "+";
        if (heso[i] == 0) {
            continue;
        }
        else if (i == bac) {
            cout << heso[i];
        }
        else
            cout << heso[i] << "x^" << bac - i;
    }
}
dathuc dathuc::operator+(const dathuc& a) {
    int bactemp = (this->bac >= a.bac) ? this->bac : a.bac;
    dathuc temp(bactemp);
    int j = bactemp;
    int m = a.bac;
    int n = this->bac;
    while (m > -1 && n > -1) {
        temp.heso[j--] = a.heso[m--] + this->heso[n--];
    }
    while (m > -1 && j > -1) {
        temp.heso[j--] = a.heso[m--];
    }
    while (n > -1 && j > -1) {
        temp.heso[j--] = this->heso[n--];
    }
    return temp;
}
int main() {
    dathuc a, b, c;
    cout << "Nhap da thuc a: ";
    a.Nhap();
    cout << "Nhap da thuc b: ";
    b.Nhap();
    cout << endl;
    c = a + b;
    c.Xuat();

    return 0;
}