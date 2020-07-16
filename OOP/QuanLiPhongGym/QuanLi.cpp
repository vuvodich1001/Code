#include <iostream>
#include <string>
#include <vector>
using namespace std;
class DichVu {
protected:
    int phi_co_ban;
    bool ho_tro_pt;
    bool dv_xong_hoi;

public:
    DichVu() {
        phi_co_ban = 0;
        ho_tro_pt = dv_xong_hoi = 0;
    }
    virtual void Nhap() = 0;
    virtual void Xuat() = 0;
    virtual int get_phi() = 0;
};

class KhachHang {
protected:
    string ho_ten;
    string cmnd;
    DichVu* dv;
    int luachon;

public:
    KhachHang() {
        ho_ten = cmnd = " ";
        dv = NULL;
        luachon = 0;
    }
    void Nhap();
    void Xuat();
    int get_tong_chi_phi();
};

class Premium : public DichVu {
public:
    void Nhap();
    void Xuat();
    int get_phi();
};

class Basic : public DichVu {
protected:
    int so_lop_dang_ki;

public:
    Basic() {
        so_lop_dang_ki = 0;
    }
    int chi_phi_1_lop_hoc();
    void Nhap();
    void Xuat();
    int get_phi();
};
class Non_member : public DichVu {
public:
    void Nhap();
    void Xuat();
    int get_phi();
};

void Premium::Nhap() {
    cout << "free";
}
void Premium::Xuat() {
    cout << "free" << endl;
}
int Premium::get_phi() {
    return 1000;
}

void Basic::Nhap() {
    cout << "So lop da dang ki: ";
    cin >> so_lop_dang_ki;
    cout << "Ho tro PT: ";
    cin >> ho_tro_pt;
}
void Basic::Xuat() {
    cout << "So lop da dang ki: " << so_lop_dang_ki << endl;
    cout << "Ho tro PT: " << (ho_tro_pt ? "co" : "khong") << endl;
}
int Basic::chi_phi_1_lop_hoc() {
    return 100;
}
int Basic::get_phi() {
    if (ho_tro_pt) {
        return 500 + so_lop_dang_ki * chi_phi_1_lop_hoc() + 100;
    }
    else {
        return 500 + so_lop_dang_ki * chi_phi_1_lop_hoc();
    }
}
void Non_member::Nhap() {
    cout << "Ho tro PT: ";
    cin >> ho_tro_pt;
}
void Non_member::Xuat() {
    cout << "Ho tro PT: " << (ho_tro_pt ? "co" : "khong") << endl;
}
int Non_member::get_phi() {
    if (ho_tro_pt) {
        return 400;
    }
    else
        return 200;
}

void KhachHang::Nhap() {
    cin.ignore();
    fflush(stdin);
    cout << "Ho va ten: ";
    getline(cin, ho_ten);
    cout << "Cmnd: ";
    getline(cin, cmnd);
    cout << "Loai dich vu muon su dung: ";
    cout << "\n\t1.Premium";
    cout << "\n\t2.Basic";
    cout << "\n\t3.Non_member";
    cout << "\nNhap lua chon: ";
    cin >> luachon;
    if (luachon == 1) {
        dv = new Premium;
    }
    else if (luachon == 2) {
        dv = new Basic;
    }
    else if (luachon == 3) {
        dv = new Non_member;
    }
    dv->Nhap();
}
void KhachHang::Xuat() {
    cout << "Ho va ten: " << ho_ten << endl;
    cout << "Cmnd: " << cmnd << endl;
    dv->Xuat();
    cout << "Tong chi phi cua ban: " << get_tong_chi_phi() << endl;
}
int KhachHang::get_tong_chi_phi() {
    return dv->get_phi();
}
class QuanLi {
private:
    //vector<KhachHang*> kh;
    KhachHang kh[100];
    int n;

public:
    QuanLi() {
        n = 0;
    }
    void Nhap_3();
    void Xuat_3();
    void Tu_Van_4();
};
void QuanLi::Nhap_3() {
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        system("cls");
        cout << "Nhap khac hang thu " << i + 1 << endl;
        kh[i].Nhap();
    }
}
void QuanLi::Xuat_3() {
    system("cls");
    cout << "\nDanh sach khach hang\n";
    for (int i = 0; i < n; i++) {
        cout << "Khach hang thu " << i + 1 << endl;
        kh[i].Xuat();
        cout << endl;
    }
}
void QuanLi::Tu_Van_4() {
    cout << "Danh sach khach hang can tu van lai dich vu\n";
    for (int i = 0; i < n; i++) {
        if (kh[i].get_tong_chi_phi() > 1000 || kh[i].get_tong_chi_phi() <= 600) {
            kh[i].Xuat();
        }
    }
}
int main() {
    QuanLi ql;
    ql.Nhap_3();
    ql.Xuat_3();
    ql.Tu_Van_4();
    return 0;
}