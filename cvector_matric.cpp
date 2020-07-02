#include<iostream>
using namespace std;
class cvector{
    int n;
    int *v;
public:
    cvector(){
        n = 0;
    }
    cvector operator+(cvector& a);`
    cvector operator-(cvector& a);
    friend istream& operator>>(istream& is, cvector& a);
    friend ostream& operator<<(ostream& os, cvector a);
};
cvector cvector::operator+(cvector& a){
    cvector temp;
    temp.n = (n > a.n) ? n : a.n;
    temp.v = new int[temp.n];
    for(int i = 0; i < n && i < a.n; i++){
        temp.v[i] = v[i] + a.v[i];
    }
    if(n > a.n){
        for(int i = a.n; i < temp.n; i++){
            temp.v[i] = a.v[i];
        }
    }
    else if(n < a.n){
        for(int i = n; i < temp.n; i++){
            temp.v[i] = v[i];
        }
    }
    return temp;

}
cvector cvector::operator-(cvector& a){
    cvector temp;
    temp.n = (n > a.n) ? n : a.n;
    temp.v = new int[temp.n];
    int i = 0;
    for(i;i < temp.n; i++){
        temp.v[i] = v[i] - a.v[i];
    }
    if(n > a.n){
        for (i = a.n; i < temp.n; i++){
            temp.v[i] = a.v[i];
        }
    }
    else if(n < a.n){
        for (i = n; i < temp.n; i++){
            temp.v[i] = v[i];
        }
    }
    return temp;
}
istream& operator>>(istream& is, cvector& a){
    cout << "Nhap cap cua vector: ";
    cin >> a.n;
    a. v = new int[a.n];
    for (int i = 0; i < a.n; i++){
        cin >> a.v[i];
    }
    return is;
}
ostream& operator<<(ostream& os, cvector a){
    os << "(";
    for (int i = 0; i < a.n; i++){
        cout << a.v[i];
        if(i < a.n -1){
            cout <<", ";
        }
    }
    os << ")";
    return os;
}
class cmatrix{
    int col;
    int row;
    int a[100][100];
public:
    cmatrix(){
        col = row = 0;
    }
    cmatrix(int r, int l);
    cmatrix operator+(cmatrix& m);
    cmatrix operator-(cmatrix& m);
    cmatrix operator*(cmatrix& m);
    friend istream& operator>>(istream& is, cmatrix& m);
    friend ostream& operator<<(ostream& os, const cmatrix& m);
};
cmatrix::cmatrix(int r, int l)
{
    row = r;
    col = l;
    for (int i = 0; i < row; i++){
        for (int j = 0; i < col; j++){
            a[i][j] = 0;
        }
    }
}
cmatrix cmatrix::operator+(cmatrix& m) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] += m.a[i][j];
		}
	}
	return *this;
}
cmatrix cmatrix::operator-(cmatrix& m) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a[i][j] -= m.a[i][j];
		}
	}
	return *this;
}
cmatrix cmatrix::operator*(cmatrix& m) {
	cmatrix s(row, m.col);
	if (col == m.row) {
		int k = 0;
		int v = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < m.col; j++) {
				for (int l = 0; l < col; l++) {
					s.a[i][j] += a[k][l] * m.a[l][v];
				}
				v++;
			}
			k++;
			v = 0;
		}
		return s;
	}
}
ostream& operator<<(ostream& os, const cmatrix& m) {
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			os << m.a[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
istream& operator>>(istream& is, cmatrix& m) {
    cout <<"row= ";
    cin >> m.row;
    cout <<"col= ";
    cin >> m.col;
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			is >> m.a[i][j];
		}
	}
	return is;
}
int main(){
    cout << "=========VECTOR=========\n";
    cvector v, x;
    cout << "Nhap vector v: " << endl;
    cin >> v;
    cout << "Nhap vector x: " << endl;
    cin >> x;
    cout << "x + v = " << x + v << endl;
    cout << "x - v = " << x - v << endl;
    cout << "=========MATRIX=========\n";
    cmatrix m, n;
    cout << "Nhap matrix m: " << endl;
    cin >> m;
    cout << "Nhap matrix n: " << endl;
    cin >> n;
    cout << "m + n = " << m + n << endl;
    cout << "m - n = " << m - n << endl;
    cout << "m * n = " << m * n << endl;
      system("pause");
    return 0;
}