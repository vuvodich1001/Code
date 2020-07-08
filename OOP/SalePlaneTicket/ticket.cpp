#include "ticket.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
// Customer
bool Customer::Check() {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) return true;
    }
    else if (month == 2) {
        if (year % 4 == 0) {
            if (day >= 1 && day <= 29) return true;
        }
        else {
            if (day >= 1 && day <= 28) return true;
        }
    }
    else {
        if (day >= 1 && day <= 31) return true;
    }
    return false;
}
void Customer::get_data() {
    cin.ignore();
    fflush(stdin);
    cout << "Name: ";
    getline(cin, this->name);
    do {
        cout << "Date of birth: ";
        cin >> this->day >> this->month >> this->year;
    } while (!Check());
    cin.ignore();
    cout << "Your address: ";
    getline(cin, this->address);
    cout << "Cost of ticket you want: ";
    cin >> this->costofticket;
}
void Customer::put_data() {
    cout << setw(15) << left << this->name
         << setw(2) << left << this->day
         << setw(1) << left << "/"
         << setw(2) << left << this->month
         << setw(1) << left << "/"
         << setw(9) << left << this->year
         << setw(10) << left << this->address
         << setw(10) << left << this->costofticket;
}
// Adult
void Adult::get_data() {
    cout << "Type of ticket: ";
    cin >> this->typeofticket;
    Customer::get_data();
}
void Adult::put_data() {
    Customer::put_data();
    cout << setw(15) << left << this->typeofticket;
}
//Child
void Child::get_data() {
    Customer::get_data();
}
void Child::put_data() {
    Customer::put_data();
}
// Management
bool check_order(Customer* c, Customer* v) {
    if (c->name.compare(v->name) > 0) {
        return false;
    }
    return true;
}
void Manage::add_list(Customer* c) {
    this->c.push_back(c);
}
void Manage::arrange() {
    sort(c.begin(), c.end(), check_order);
    print_list();
}
void Manage::replace(string n, Customer* rp) {
    for (int i = 0; i < this->c.size(); i++) {
        if (c[i]->get_name().compare(n) == 0) {
            c[i] = rp;
        }
    }
}
void Manage::remove(string n) {
    for (int i = 0; i < this->c.size(); i++) {
        if (c[i]->get_name().compare(n) == 0) {
            c.erase(c.begin() + i);
        }
    }
}
void Manage::print_list() {
    cout << setw(15) << left << "Name"
         << setw(15) << left << "Date of birth"
         << setw(10) << left << "Address"
         << setw(10) << left << "Cost"
         << setw(10) << left << "Type" << endl;
    for (int i = 0; i < c.size(); i++) {
        c[i]->put_data();
        cout << endl;
    }
}

void menu() {
    Manage m;
    Customer* c;
    int sect, sl;
    string tempname;
    while (true) {
        system("cls");
        cout << "\n\tWelcome to VUAIRWAYS\n";
        cout << "\n\t1.Buy ticket";
        cout << "\n\t2.Change ticket";
        cout << "\n\t3.Cancle ticket";
        cout << "\n\t4.Arrange list";
        cout << "\n\t5.Print list";
        cout << "\n\t0.Exit";
        cout << "\nYour selection is: ";
        cin >> sect;
        if (sect == 0) break;
        system("cls");
        if (sect == 1) {
            cout << "if you are enough 18, you should choose 1 to buy more ticket\n";
            cout << "Child can only buy 1 ticket\n";
            cout << "\n\t1.Adult";
            cout << "\n\t2.Child";
            cout << "\n\t0.Exit";
            cout << "\nYour selection is: ";
            cin >> sect;
            if (sect == 0) break;
            system("cls");
            if (sect == 1) {
                cout << "Number of ticket: ";
                cin >> sl;
                for (int i = 0; i < sl; i++) {
                    system("cls");
                    cout << "Person " << i + 1 << endl;
                    cout << "\n\t1.Adult";
                    cout << "\n\t2.Child";
                    cout << "\n\t0.Exit";
                    cout << "\nYour selection is: ";
                    cin >> sect;
                    if (sect == 0) break;
                    if (sect == 1) {
                        c = new Adult;
                    }
                    else if (sect == 2) {
                        c = new Child;
                    }
                    c->get_data();
                    m.add_list(c);
                }
            }
            else {
                c = new Child;
                c->get_data();
                m.add_list(c);
            }
        }
        else if (sect == 2) {
            cin.ignore();
            cout << "Your name: ";
            getline(cin, tempname);
            cout << "Retype your cv: \n";
            c = new Adult;
            c->get_data();
            m.replace(tempname, c);
        }
        else if (sect == 3) {
            cin.ignore();
            cout << "Your name: ";
            getline(cin, tempname);
            m.remove(tempname);
        }
        else if (sect == 4) {
            m.arrange();
        }
        else if (sect == 5) {
            m.print_list();
        }
        system("pause");
    }
}