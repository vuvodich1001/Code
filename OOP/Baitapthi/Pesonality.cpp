#include <iostream>
#include <vector>
using namespace std;

class O {
protected:
    int o;

public:
    void Nhap() {
        cout << "San sang trai nghiem (O): ";
        cin >> o;
    }
    void Xuat();
};

class C {
protected:
    int c;

public:
    void Nhap() {
        cout << "Tu chu tan tam (C): ";
        cin >> c;
    }
    void Xuat();
};

class E {
protected:
    int e;

public:
    void Nhap() {
        cout << "Huong ngoai (E): ";
        cin >> e;
    }
    void Xuat();
};

class A {
protected:
    int a;

public:
    void Nhap() {
        cout << "Hoa dong de chiu (A): ";
        cin >> a;
    }
    void Xuat();
};

class N {
protected:
    int n;

public:
    void Nhap() {
        cout << "Bat on cam xuc (N): ";
        cin >> n;
    }
    void Xuat();
};

void O::Xuat() {
    if (o >= 70) {
        cout << o << ":(O)Nguoi thich y tuong moi, thich hieu biet nhieu linh vuc";
    }
    else if (o <= 30) {
        cout << o << ":(O)Nguoi thich bao thu kho tiep nhan cai moi";
    }
    else {
        cout << o << ":Khong xac dinh ro";
    }
    cout << endl;
}

void C::Xuat() {
    if (c >= 70) {
        cout << c << ":(C)Nguoi cham chi, co kha nang chiu duoc ap luc";
    }
    else if (c <= 30) {
        cout << c << ":(C)Nguoi ngai giao tiep, khong thich su noi bat";
    }
    else {
        cout << c << ":Khong xac dinh ro";
    }
    cout << endl;
}

void E::Xuat() {
    if (e >= 70) {
        cout << e << ":(E)Nguoi nhiet tinh, nang dong, giao tiep tot";
    }
    else if (e <= 30) {
        cout << e << ":(E)Nguoi ngai giao tiep, khong thich su noi bat";
    }
    else {
        cout << e << ":Khong xac dinh ro";
    }
    cout << endl;
}

void A::Xuat() {
    if (a >= 70) {
        cout << a << ":(A)Nguoi than thien, coi mo, dong cam";
    }
    else if (a <= 30) {
        cout << a << ":(A)Nguoi dat loi ich ca nhan len tren, it dong cam";
    }
    else {
        cout << a << ":Khong xac dinh ro";
    }
    cout << endl;
}

void N::Xuat() {
    if (n >= 70) {
        cout << n << ":(N)Nguoi thuong co cam tuc tieu cuc, yeu duoi";
    }
    else if (n <= 30) {
        cout << n << ":(N)Nguoi kiem xoat duoc cam xuc, ung pho voi cang thang tot";
    }
    else {
        cout << n << ":Khong xac dinh ro";
    }
    cout << endl;
}

class Personality : public O, public C, public N, public E, public A {
public:
    void Xuat() {
        O::Xuat();
        C::Xuat();
        E::Xuat();
        A::Xuat();
        N::Xuat();
    }
    void Nhap() {
        O::Nhap();
        C::Nhap();
        E::Nhap();
        A::Nhap();
        N::Nhap();
    }
    int get_N() { return n; }
    int get_C() { return c; }
    int get_E() { return e; }
};
class QuanLi {
    Personality p[100];
    int n, luachon;

public:
    void Nhap();
    void Xuat_3();
    void luu_y();
};

void QuanLi::Nhap() {
    cout << "Nhap so luong nguoi kiem tra: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap nguoi thu " << i + 1 << endl;
        p[i].Nhap();
    }
}
void QuanLi::Xuat_3() {
    cout << "Nhap lua chon: ";
    cin >> luachon;
    p[luachon - 1].Xuat();
}
void QuanLi::luu_y() {
    cout << "Danh sach nhung nguoi cac cong ty can luu y\n";
    for (int i = 0; i < n; i++) {
        if (p[i].get_C() <= 30 || p[i].get_N() >= 70 || p[i].get_N() >= 70 && p[i].get_E() <= 30) {
            cout << "Nguoi thu " << i + 1 << endl;
            p[i].Xuat();
        }
    }
}
int main() {
    QuanLi a;
    a.Nhap();
    a.Xuat_3();
    a.luu_y();
    return 0;
}