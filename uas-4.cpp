#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Fungsi untuk menampilkan informasi nama, kelas, dan NIM
void displayInfo() {
    cout << "===============================\n";
    cout << "Nama : Muhammad Dzakwan F\n";
    cout << "Kelas: 03TPLP029\n";
    cout << "Nim  : 231011403237\n";
    cout << "===============================\n\n";
}

// Fungsi Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;

    while (maxVal / exp > 0) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        // Hitung frekuensi digit
        for (int num : arr)
            count[(num / exp) % 10]++;

        // Hitung posisi elemen
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Tempelkan elemen berdasarkan digit
        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Salin hasil ke array asli
        arr = output;
        exp *= 10;
    }
}

// Fungsi Partition untuk Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Fungsi Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi Merge untuk Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Fungsi Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main Program
int main() {
    // Menampilkan informasi nama, kelas, dan NIM
    displayInfo();

    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    vector<int> arrRadix = arr;
    vector<int> arrQuick = arr;
    vector<int> arrMerge = arr;

    // Radix Sort
    cout << "Radix Sort: ";
    radixSort(arrRadix);
    for (int num : arrRadix) cout << num << " ";
    cout << endl;

    // Quick Sort
    cout << "Quick Sort: ";
    quickSort(arrQuick, 0, arrQuick.size() - 1);
    for (int num : arrQuick) cout << num << " ";
    cout << endl;

    // Merge Sort
    cout << "Merge Sort: ";
    mergeSort(arrMerge, 0, arrMerge.size() - 1);
    for (int num : arrMerge) cout << num << " ";
    cout << endl;

    return 0;
}

