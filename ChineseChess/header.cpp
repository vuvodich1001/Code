#include "header.h"
#include <iostream>
using namespace std;
void Tot::move() {
    cout << "Di moi o mot nuoc. Neu tot chua vuot qua song, no chi co the di thang tien, khi qua song no co the di ngang\n";
}
void Phao::move() {
    cout << "Co the di chuyen nhu xe, cach 1 con an 1 con\n";
}
void Xe::move() {
    cout << "Di chuyen ngang doc tuy y an co truc tiep\n";
}
void Ma::move() {
    cout << "Di chuyen hinh chu L, neu phia truoc cach 1 o ma co 1 quan co nam tren hinh chu L thi ko dc di\n";
}
void Tinh::move() {
    cout << "Di cheo 2 buoc va chi duoc phep di o phan song cua minh\n";
}
void Si::move() {
    cout << "Di cheo 1 buoc va chi dc phep di trong cung cua tuong\n";
}
void Tuong::move() {
    cout << "Chi co the di trong cung va chi co the di len, di xuong, khong dc phep di cheo\n";
}
void menu() {
    ChineseChess* c = NULL;
    while (true) {
        system("cls");
        cout << "\tHUONG DAN CACH DI CAC QUAN CO`\n";
        cout << "\n\t1.Tot";
        cout << "\n\t2.Phao";
        cout << "\n\t3.Xe";
        cout << "\n\t4.Ma";
        cout << "\n\t5.Tinh";
        cout << "\n\t6.Si";
        cout << "\n\t7.Tuong";
        cout << "\n\t0.Thoat chuong trinh";
        int luachon;
        cout << "\nNhap lua chon cua ban: ";
        cin >> luachon;
        system("cls");
        if (luachon == 0) return;
        if (luachon == 1) {
            c = new Tot;
        }
        else if (luachon == 2) {
            c = new Phao;
        }
        else if (luachon == 3) {
            c = new Xe;
        }
        else if (luachon == 4) {
            c = new Ma;
        }
        else if (luachon == 5) {
            c = new Tinh;
        }
        else if (luachon == 6) {
            c = new Si;
        }
        else if (luachon == 7) {
            c = new Tuong;
        }
        c->move();
        system("pause");
    }
}