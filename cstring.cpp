#include<iostream>
#include<string>
using namespace std;
class cstring{
    string s;
public:
    cstring(){
        s = " ";
    }
    ~cstring(){}
    cstring operator+(cstring a);
    void operator=(cstring &a);
    bool operator>(cstring a);
    bool operator>=(cstring a);
    bool operator<(cstring a);
    bool operator<=(cstring a);
    bool operator==(cstring a);
    bool operator!=(cstring a);
    friend istream& operator>>(istream& is, cstring &a);
    friend ostream& operator<<(ostream& os, cstring a);
};
cstring cstring::operator+(cstring a){
    cstring c;
    c.s = s;
    c.s += a.s;
    return c;
}
void cstring::operator=(cstring &a){
    s = a.s;
}
bool cstring::operator>(cstring a){
    return(s > a.s);
}
bool cstring::operator>=(cstring a){
    return(s >= a.s);
}
bool cstring::operator<(cstring a){
    return(s < a.s);
}
bool cstring::operator<=(cstring a){
    return(s <= a.s);
}
bool cstring::operator==(cstring a){
    return( s == a.s);
}
bool cstring::operator!=(cstring a){
    return(s != a.s);
}
istream& operator>>(istream& is, cstring &a){
    fflush(stdin);
    is >> a.s;
    return is;
}
ostream& operator<<(ostream& os, cstring a){
    os << a.s;
    return os;
}
int main(){
    cstring a, b;
    cout  << "Nhap cstring a: ";
    cin >> a;
    cout << "Nhap cstring b: ";
    cin >> b;
    cout << "a + b = " << a + b << endl;
    cout << "So sanh 2 chuoi: " << endl;
    if(a > b){
        cout << "a > b\n";
    }
    else if(a == b){
        cout << "a == b\n";
    }
    else if(a < b){
        cout << "a < b\n";
    }
    system("pause");
    return 0;
}