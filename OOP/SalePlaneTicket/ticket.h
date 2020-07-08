#pragma
#include <string>
#include <vector>
using namespace std;
class Customer {
protected:
    string name;
    int day, month, year;
    string address;
    int costofticket;

public:
    bool Check();
    virtual void get_data();
    virtual void put_data();
    string get_name() { return name; }
    friend bool check_order(Customer* c, Customer* v);
};

class Adult : public Customer {
protected:
    string typeofticket;

public:
    void get_data();
    void put_data();
};

class Child : public Customer {
public:
    void get_data();
    void put_data();
};

class Manage : public Customer {
private:
    vector<Customer*> c;

public:
    void add_list(Customer* c);
    void arrange();
    void replace(string n, Customer* rp);
    void remove(string n);
    void print_list();
};
bool check_order(Customer* c, Customer* v);
void menu();