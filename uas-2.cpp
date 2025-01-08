#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Fungsi untuk menampilkan informasi nama, kelas, dan NIM
void displayInfo() {
    cout << "===============================\n";
    cout << "Nama : Muhammad Dzakwan F\n";
    cout << "Kelas: 03TPLP029\n";
    cout << "Nim  : 231011403237\n";
    cout << "===============================\n\n";
}

// Fungsi untuk menemukan pasangan bilangan
vector<pair<int, int>> findPairs(const vector<int>& A, const vector<int>& B, int K) {
    unordered_map<int, int> mapA;
    vector<pair<int, int>> result;

    // Simpan elemen-elemen dari array A ke dalam hash map
    for (int a : A) {
        mapA[a]++;
    }

    // Iterasi melalui array B
    for (int b : B) {
        int needed = K - b; // Cari nilai yang diperlukan dari A
        if (mapA.find(needed) != mapA.end()) {
            result.push_back({needed, b});
        }
    }

    return result;
}

int main() {
    // Tampilkan informasi nama, kelas, dan NIM
    displayInfo();

    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {4, 5, 6, 7};
    int K = 9;

    vector<pair<int, int>> pairs = findPairs(A, B, K);

    cout << "Pasangan bilangan dengan jumlah " << K << ":\n";
    for (auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")\n";
    }

    return 0;
}

