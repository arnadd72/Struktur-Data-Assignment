#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int jumlahSimpul2311102180;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul2311102180;

    string simpul[jumlahSimpul2311102180];
    int busur[jumlahSimpul2311102180][jumlahSimpul2311102180];

    for (int i = 0; i < jumlahSimpul2311102180; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    for (int i = 0; i < jumlahSimpul2311102180; i++) {
        for (int j = 0; j < jumlahSimpul2311102180; j++) {
            cout << "Silakan masukkan bobot antara simpul " << simpul[i] << " dan " << simpul[j] << ": ";
            cin >> busur[i][j];
        }
    }

    cout << "\nGraf yang dihasilkan:\n";
    cout << setw(15) << " ";
    for (int i = 0; i < jumlahSimpul2311102180; i++) {
        cout << setw(15) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul2311102180; i++) {
        cout << setw(15) << simpul[i];
        for (int j = 0; j < jumlahSimpul2311102180; j++) {
            cout << setw(15) << busur[i][j];
        }
        cout << endl;
    }

    return 0;
}
