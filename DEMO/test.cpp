#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
std::vector<long long> buildHouse(long long S) {
    vector<long long> ans;
    long long d = 0, r = 0;
    for (int i = 1; i <= sqrt(S); i++) {
        if (S % i == 0) {
            d = i;
            r = S / d;
        }
    }
    ans.push_back(d);
    ans.push_back(r);
    return ans;
}
int main() {
    vector<long long> a = buildHouse(50);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}