#include <iostream>
using namespace std;

// Fungsi integer
void bilangan(int num) {
    cout << "Bilangan integer yang dimasukkan: " << num << endl;
}

// Fungsi karakter
void charakter(char c) {
    cout << "Karakter yang dimasukkan: " << c << endl;
}

int main() {
    int angka;
    char karakter;

    cout << "Masukkan sebuah bilangan integer: ";
    cin >> angka;

    cout << "Masukkan sebuah karakter: ";
    cin >> karakter;

    bilangan(angka);
    charakter(karakter);

    return 0;
}
