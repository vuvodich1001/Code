#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    virtual void getdata();
    virtual void putdata();
};
void Person::getdata() {
    cin.ignore();
    fflush(stdin);
    cout << "Name: ";
    getline(cin, this->name);
    cout << "Age: ";
    cin >> this->age;
}
void Person::putdata() {
    cout << "Name: " << this->name << endl;
    cout << "Age: " << this->age << endl;
}
class Student : public Person {
protected:
    float overallmark;
    int rank;

public:
    void getdata();
    void putdata();
};
void Student::getdata() {
    Person::getdata();
    cout << "overall mark: ";
    cin >> this->overallmark;
    cout << "Rank: ";
    cin >> this->rank;
}
void Student::putdata() {
    Person::putdata();
    cout << "overrall mark: " << this->overallmark << endl;
    cout << "Rank: " << this->rank << endl;
}
class Singer : public Person {
protected:
    int numberofalbums;
    int numberofshows;

public:
    void getdata();
    void putdata();
};
void Singer::getdata() {
    Person::getdata();
    cout << "Number of albums: ";
    cin >> this->numberofalbums;
    cout << "Number of shows: ";
    cin >> this->numberofshows;
}
void Singer::putdata() {
    Person::putdata();
    cout << "Number of albums: " << this->numberofalbums << endl;
    cout << "Number of shows: " << this->numberofshows << endl;
}
void menu() {
    vector<Person*> p;
    while (true) {
        system("cls");
        cout << "\n\t1.Student";
        cout << "\n\t2.Singer";
        cout << "\n\t3.print list of student and singger";
        cout << "\n\t0.Thoat";
        int selection;
        cout << "\nYour selection is: ";
        cin >> selection;
        Person* a = NULL;
        system("cls");
        if (selection == 0) break;
        if (selection == 1) {
            a = new Student;
            a->getdata();
            p.push_back(a);
        }
        else if (selection == 2) {
            a = new Singer;
            a->getdata();
            p.push_back(a);
        }
        else if (selection == 3) {
            if (!p.empty()) {
                for (int i = 0; i < p.size(); i++) {
                    p[i]->putdata();
                    cout << "\n\n";
                }
            }
        }
        system("pause");
    }
}
int main() {
    menu();
    return 0;
}