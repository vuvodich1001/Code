#include <iostream>
#include <vector>
using namespace std;
int lomotu_partition(int* a, int l, int r) {
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(a[i], a[j]);
    }
}
void quick_sort(int* a, int l, int r) {
    if (l < r) {
        int i = lomotu_partition(a, l, r);
        quick_sort(a, l, i);
        quick_sort(a, i + 1, r);
    }
}
int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}