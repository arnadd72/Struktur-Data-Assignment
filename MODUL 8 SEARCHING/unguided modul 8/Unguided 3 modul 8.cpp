//2311102180
#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int n = sizeof(data) / sizeof(data[0]);
    int angka = 4;
    bool ketemu = false;
    int count = 0;

    // Algoritma Sequential Search untuk menghitung kemunculan angka 4
    for (int i = 0; i < n; i++) {
        if (data[i] == angka) {
            ketemu = true;
            count++;
        }
    }

    cout << "\tSequential Search untuk Menghitung banyaknya Angka 4\n" << endl;
    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu) {
        cout << "Jumlah angka 4 dalam data: " << count << endl;
    } else {
        cout << "Angka 4 tidak ditemukan dalam data." << endl;
    }

    return 0;
}
