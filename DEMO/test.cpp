#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    for (int i = 2; i <= 2014; i++) {
        if (i % 2 == 0)
            sum += i;
        else
            sum += -i;
    }
    cout << "ket qua sum= " << sum << endl;
    return 0;
}