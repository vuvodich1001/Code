#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
void selection_sort(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
}

void insertion_sort(int* a, int n) {
    for (int i = 0; i < n; i++) {
        int val = a[i];
        int j = i;
        while (j != 0 && a[j - 1] > val) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = val;
    }
}

int partition(int* a, int l, int r) {
    int pivot = a[l];
    int i = l, j = r;
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j++;
        } while (a[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(a[i], a[j]);
    }
}

void quick_sort(int* a, int l, int r) {
    if (l < r) {
        int i = partition(a, l, r);
        quick_sort(a, l, i);
        quick_sort(a, i + 1, r);
    }
}
void merge(int* a, int n, int* b, int m, int* c) {
    int j = 0;
    int nc = 0;
    int i = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[nc++] = a[i++];
        }
        else if (a[i] == b[j]) {
            c[nc++] = a[i++];
            c[nc++] = b[j++];
        }
        else {
            c[nc++] = b[j++];
        }
    }
    while (j < m) {
        c[nc++] = b[j++];
    }
    while (i < n) {
        c[nc++] = a[i++];
    }
}
void its_magic(int* a, int n, int k, int*& temp) {
    int x = n / (2 * k);
    int j = 0;
    for (int i = 0; i < x; i++) {
        merge(a + j, k, a + j + k, k, temp + j);
        j = j + 2 * k;
    }
    int mod = n % (2 * k);
    if (mod > k) {
        merge(a + j, k, a + j + k, mod - k, temp + j);
    }
    else
        merge(a + j, mod, a + j + k, 0, temp + j);
}
void merge_sort(int*& a, int n) {
    int* temp = new int[n];
    for (int i = 1; i <= n; i *= 2) {
        its_magic(a, n, i, temp);
        memcpy(a, temp, n * sizeof(int));
    }
}

void heapify(int* a, int i, int n) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (i != largest) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void heap_sort(int* a, int n) {
    // buil max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, i, n);
    }
    //sort
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}
int main() {
    int* a = new int[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        a[i] = rand() % 50 + 1;
    }
    heap_sort(a, 50);
    for (int i = 0; i < 50; i++) {
        cout << a[i] << " ";
    }

    return 0;
}