//PhanSo
#include <iostream>
using namespace std;
class PhanSo {
private:
    int tuso;
    int mauso;

public:
    void Nhap();
    void Xuat();
    PhanSo operator+(PhanSo a);
    PhanSo operator+(int a);
    PhanSo Rut_Gon();
    bool operator==(PhanSo a);
    friend istream& operator>>(istream& is, PhanSo& a);
    friend ostream& operator<<(ostream& os, PhanSo a);
};
void PhanSo::Nhap() {
    cout << "Nhap phan so: ";
    cin >> this->tuso >> this->mauso;
}

void PhanSo::Xuat() {
    cout << "Phan so: " << this->tuso << "/" << this->mauso;
}

PhanSo PhanSo::operator+(PhanSo a) {
    PhanSo temp;
    temp.tuso = this->tuso * a.mauso + a.tuso * this->mauso;
    temp.mauso = this->mauso * a.mauso;
    return temp;
}

PhanSo PhanSo::operator+(int a) {
    PhanSo temp;
    temp.tuso = this->tuso + a * this->mauso;
    temp.mauso = this->mauso;
    return temp;
}

istream& operator>>(istream& is, PhanSo& a) {
    is >> a.tuso >> a.mauso;
    return is;
}

ostream& operator<<(ostream& os, PhanSo a) {
    os << "Phan so: " << a.tuso << "/" << a.mauso;
    return os;
}

bool PhanSo::operator==(PhanSo a) {
    return ((float)this->tuso / this->mauso) == ((float)a.tuso / a.mauso);
}

int UCLN(int a, int b) {
    for (int i = a; i >= 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
}

PhanSo PhanSo::Rut_Gon() {
    int temp = UCLN(this->tuso, this->mauso);
    this->tuso /= temp;
    this->mauso /= temp;
    return *this;
}
int main() {
    PhanSo a, b;
    cout << "Nhap phan so a: ";
    cin >> a;
    cout << a;
    cout << "\nNhap phan so b: ";
    cin >> b;
    cout << b;
    PhanSo temp = a + b + 1;
    cout << "\nTong 2 phan so la: " << temp.Rut_Gon() << endl;
    if (a == b) {
        cout << "\n2 Phan so bang nhau";
    }
    else {
        cout << "\n2 Phan So khong bang nhau";
    }
    return 0;
}