# <h1 align="center">Laporan Praktikum Modul 5 Hash Table </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>


## Dasar Teori
## Hash Table

Hash Table adalah struktur data yang menyimpan data dalam bentuk pasangan kunci-nilai, di mana setiap kunci di-mapping ke sebuah nilai. Ini memungkinkan akses cepat ke nilai-nilai berdasarkan kunci-kunci tertentu. Hash table terdiri dari array atau vektor yang digunakan untuk menyimpan data, dan fungsi hash yang mengonversi kunci menjadi indeks dalam array. Pencarian data dalam hash table biasanya memiliki kompleksitas waktu O(1) dalam kasus terbaik[1].

## Kegunaan Struktur Data Hash Table
Pencarian Cepat: Dapat digunakan untuk mencari data dengan cepat berdasarkan key. Ini sangat berguna dalam aplikasi seperti basis data, kamus, dan cache.
Penyimpanan Data: Hash table dapat digunakan untuk menyimpan data dengan efisien. Data dapat diambil dan dimasukkan ke dalam tabel dengan waktu konstan, asalkan tidak ada collision yang signifikan.
Implementasi Struktur Data Lain: Hash table dapat digunakan untuk mengimplementasikan struktur data lain, seperti set dan map[2]. 

## Guided
## guided 1
source code

```c++
#include <iostream>
 using namespace std;
 const int MAX_SIZE = 10;
 // Fungsi hash sederhana
 int hash_func(int key) {
 return key % MAX_SIZE;
 }
 // Struktur data untuk setiap node
 struct Node {
 int key;
 int value;
 Node* next;
 Node(int key, int value) : key(key), value(value),
 next(nullptr) {}
 };
 // Class hash table
 class HashTable {
 private:
 Node** table;
 public:
 HashTable() {
 table = new Node*[MAX_SIZE]();
 }
 ~HashTable() {
 for (int i = 0; i < MAX_SIZE; i++) {
 Node* current = table[i];
 while (current != nullptr) {
 Node* temp = current;
 current = current->next;
 delete temp;
 }
 }
 delete[] table;
 }
 // Insertion
 void insert(int key, int value) {
 int index = hash_func(key);
 Node* current = table[index];
 while (current != nullptr) {
 if (current->key == key) {
 current->value = value;
 return;
 }
 current = current->next;
 }

Node* node = new Node(key, value);
 node->next = table[index];
 table[index] = node;
 }
 // Searching
 int get(int key) {
 int index = hash_func(key);
 Node* current = table[index];
 while (current != nullptr) {
 if (current->key == key) {
 return current->value;
 }
 current = current->next;
 }
 return-1;
 }
 // Deletion
 void remove(int key) {
 int index = hash_func(key);
 Node* current = table[index];
 Node* prev = nullptr;
 while (current != nullptr) {
 if (current->key == key) {
 if (prev == nullptr) {
 table[index] = current->next;
 } else {
 prev->next = current->next;
 }
 delete current;
 return;
 }
 prev = current;
 current = current->next;
 }
 }
 // Traversal
 void traverse() {
 for (int i = 0; i < MAX_SIZE; i++) {
 Node* current = table[i];
 while (current != nullptr) {
 cout << current->key << ": " << current->value
 << endl;
 current = current->next;
 }
 }
 }
 };

int main() {
 HashTable ht;
 // Insertion
 ht.insert(1, 10);
 ht.insert(2, 20);
 ht.insert(3, 30);
 // Searching
 cout << "Get key 1: " << ht.get(1) << endl;
 cout << "Get key 4: " << ht.get(4) << endl;
 // Deletion
 ht.remove(4);
 // Traversal
 ht.traverse();
 return 0;
 }
```
## Output Guided 1
![Screenshot (427)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/fa374400-577a-4216-9b84-fe9067c1298d)


## b.) guided 2
Source code

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah: " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus: " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table: " << endl;
    employee_map.print();

    return 0;
}
```

## Output Guided 2
![Screenshot (428)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/0cf982d6-2eab-4ddf-92f1-06d7cdb4af0e)

## Unguided 
   [Soal]
   
##  1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa
 memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,
 menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan
 nilai. Dengan ketentuan :
 a. Setiap mahasiswa memiliki NIM dan nilai.
 b. Program memiliki tampilan pilihan menu berisi poin C.
 c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
 mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
 (80– 90)
## Source Code 
```C++
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

```

## [Output Program 1]

a. tambah data

![Screenshot (430)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/db69d83d-6cd3-4b9b-a0ac-93315842f7c1)
![Screenshot (431)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/70e622fc-2d06-4a2e-98b8-33e62ca26494)
![Screenshot (432)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/079b616b-5474-4196-a7d7-0f458a6bae72)

b.Hapus data  

![Screenshot (433)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/1a40356b-8951-4cf6-9d96-d762c1e4923d)

c.  Mencari data berdasarkan nim 

![Screenshot (434)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/c6c7a007-fd9d-4250-908b-821fce263244)

d. Mencari data berdasarkan nilai 

![Screenshot (435)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/96520867-a5c5-441f-8dc6-b6b26d0579bc)

Program tersebut adalah implementasi sederhana dari sebuah hash table untuk menyimpan data mahasiswa berdasarkan NIM dan nilai.Pengguna diberikan pilihan menu untuk melakukan operasi-operasi berikut:
1.Menambah data mahasiswa baru.
2.Menghapus data mahasiswa berdasarkan NIM.
3.Mencari data mahasiswa berdasarkan NIM.
4.Mencari data mahasiswa berdasarkan rentang nilai.
5.Keluar dari program.

## Kesimpulan
Hash Table adalah struktur data yang menggunakan teknik hashing untuk mengorganisir data ke dalam pasangan kunci-nilai. Komponen utama dari hash table adalah array (atau vektor) dan fungsi hash. Fungsi hash digunakan untuk mengubah nilai kunci menjadi indeks array yang unik. Setiap slot dalam array disebut bucket, dan dapat menampung satu atau beberapa item data. Hash table memungkinkan pencarian data dalam waktu konstan (O(1)) dalam kasus terbaik, karena setiap data diakses langsung melalui indeks array yang dihasilkan oleh fungsi hash. Dalam kasus hash collision, di mana dua atau lebih data memiliki nilai hash yang sama, hash table menggunakan teknik chaining untuk menyimpan data tersebut dalam satu slot yang sama. Dengan demikian, hash table adalah struktur data yang efisien untuk mempercepat operasi pencarian dan penyimpanan data.
## Referensi
[1] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in Java (6th ed.). Wiley.

[2] https://fikti.umsu.ac.id/struktur-data-hash-table-pengertian-cara-kerja-dan-operasi-hash-table/


