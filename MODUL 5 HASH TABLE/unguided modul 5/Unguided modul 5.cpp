#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Mahasiswa {
    string NIM;
    int nilai;
};

class HashTable {
private:
    unordered_map<string, Mahasiswa> tabel;

public:
    void tambahData(Mahasiswa mahasiswa) {
        tabel[mahasiswa.NIM] = mahasiswa;
    }

    void hapusData(string NIM) {
        if (tabel.find(NIM) != tabel.end()) {
            tabel.erase(NIM);
            cout << "Data berhasil dihapus" << endl;
        } else {
            cout << "NIM tidak ditemukan" << endl;
        }
    }

    Mahasiswa cariDataBerdasarkanNIM(string NIM) {
        if (tabel.find(NIM) != tabel.end()) {
            return tabel[NIM];
        } else {
            throw "NIM tidak ditemukan";
        }
    }

    vector<Mahasiswa> cariDataBerdasarkanRentangNilai(int nilaiMin, int nilaiMax) {
        vector<Mahasiswa> hasil;
        for (auto it = tabel.begin(); it != tabel.end(); it++) {
            if (it->second.nilai >= nilaiMin && it->second.nilai <= nilaiMax) {
                hasil.push_back(it->second);
            }
        }
        return hasil;
    }
};

int main() {
    HashTable hashTable;
    int pilihan;
    do {
        cout << "\t            PROGRAM HASH TABLE" << endl;
        cout << "\t       =============================" << endl;
        cout << "     Menu:" << endl;
        cout << "\t-------------------------------------------------" << endl;
        cout << "\t| 1. Tambah data baru                           |" << endl;
        cout << "\t| 2. Hapus data                                 |" << endl;
        cout << "\t| 3. Cari data berdasarkan NIM                  |" << endl;
        cout << "\t| 4. Cari data berdasarkan rentang nilai (80-90)|" << endl;
        cout << "\t| 5. Keluar                                     |" << endl;
        cout << "\t-------------------------------------------------" << endl;
        cout << "   MASUKKAN PILIHAN : ";
        cin >> pilihan;

        if (pilihan == 1) {
            Mahasiswa mahasiswa;
            cout << "Masukkan NIM: ";
            cin >> mahasiswa.NIM;
            cout << "Masukkan nilai: ";
            cin >> mahasiswa.nilai;
            hashTable.tambahData(mahasiswa);
            cout << "Data berhasil ditambahkan" << endl;
            cout << endl;
        } else if (pilihan == 2) {
            string NIM;
            cout << "Masukkan NIM yang ingin dihapus: ";
            cin >> NIM;
            hashTable.hapusData(NIM);
            cout << endl;
        } else if (pilihan == 3) {
            string NIM;
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> NIM;
            try {
                Mahasiswa mahasiswa = hashTable.cariDataBerdasarkanNIM(NIM);
                cout << "NIM: " << mahasiswa.NIM << ", Nilai: " << mahasiswa.nilai << endl;
            } catch (const char *msg) {
                cerr << msg << endl;
            }
            cout << endl;
        } else if (pilihan == 4) {
            int nilaiMin, nilaiMax;
            cout << "Masukkan rentang nilai yang ingin dicari (misal: 80 90): ";
            cin >> nilaiMin >> nilaiMax;

            vector<Mahasiswa> hasil = hashTable.cariDataBerdasarkanRentangNilai(nilaiMin, nilaiMax);
            for (Mahasiswa mahasiswa : hasil) {
                cout << "NIM: " << mahasiswa.NIM << ", Nilai: " << mahasiswa.nilai << endl;
            }
            cout << endl;
        }
    } while (pilihan != 5);
    return 0;
}
