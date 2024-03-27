# <h1 align="center">Laporan Praktikum Modul 3 Linked List </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>


## Dasar Teori
## a) Single Linked List
Single Linked List adalah sebuah field pointer-nya hanya satu buah saja dan satu arah serta pada akhir node yang nodenya saling terhubung satu sama lain. Jadi Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list[1].

## b) Double Linked List
Pengertian Double Linked List adalah sekumpulan node data yang terurut linear atau sekuensial dengan dua buah pointer yaitu prev dan next.
Double Linked List adalah linked list dengan node yang memiliki data dan dua buah reference link (biasanya disebut next dan prev) yang menunjuk ke node sebelum dan node sesudahnya. Pada implementasinya, terdapat dua variasi double linked list yaitu circular dan non-circular layaknya pada single linked list.
Double linked list memiliki beberapa operasi dasar pada list, misalkan penyisipan, penghapusan, menampilkan maju, dan menampilkan mundur[2].

## Guided
## a.) Latihan Single Linked List
source code

```c++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
## Output Guided 1

![Screenshot (355)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/c82f21a5-149b-4350-9401-0d40422362fc)


## b.) Latihan Double Linked List
Source code

```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

## Output Guided 2

![Screenshot (352)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/4ad5fa93-e24e-46cd-ba80-1a5b9c55516b)


## Unguided 
   [Soal]
   
## 1. Soal Mengenai Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
dari user. Lakukan operasi berikut:

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda.

[Nama_anda] [Usia_anda]
John            19
Jane            20
Michael         18
Yusuke          19
Akechi          20
Hoshino         18
Karin           18

b. Hapus data Akechi

c. Tambahkan data berikut diantara John dan Jane : Futaba 18

d. Tambahkan data berikut diawal : Igor 20

e. Ubah data Michael menjadi : Reyn 18

f. Tampilkan seluruh data

## Source Code 
```C++
//Nama : arnanda setya nosa putra
// NIM : 2311102180

#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node
{
    string nama;
    int usia;
    Node *next;
};

Node *head = NULL;

Node *cariNode(Node *head, string nama)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->nama == nama)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void insertAwal(string nama, int usia)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;
    nodeBaru->next = head;
    head = nodeBaru;
}

void insertSelanjutnya(string nama, int usia)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;
    nodeBaru->next = NULL;

    if (head == NULL)
    {
        head = nodeBaru;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

void insertTengah(string nama, int usia, string namaSebelum)
{
    Node *nodeBaru = new Node;
    nodeBaru->nama = nama;
    nodeBaru->usia = usia;

    Node *temp = head;
    while (temp->nama != namaSebelum)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Data dengan nama " << namaSebelum << " tidak ditemukan " << endl;
            return;
        }
    }
    nodeBaru->next = temp->next;
    temp->next = nodeBaru;
}

// Fungsi untuk mengupdate data berdasarkan nama
void updateData(string nama, int usia, string newnama)
{
    Node *current = head;
    while (current != nullptr && current->nama != nama)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Node dengan nama " << nama << " tidak ditemukan!" << endl;
        return;
    }

    // current->nama = nama;
    current->usia = usia;
    current->nama = newnama;
}

// Fungsi untuk menghapus node berdasarkan nama
void deleteData(string nama)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong." << endl;
        return;
    }
    if (head->nama == nama)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Data berhasil dihapus." << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr && temp->next->nama != nama)
    {
        temp = temp->next;
    }
    if (temp->next != nullptr)
    {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Data berhasil dihapus." << endl;
    }
    else
    {
        cout << "Data tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan seluruh data dalam linked list
void display()
{
    Node *temp = head;
    cout << "Data Mahasiswa:" << endl;
    while (temp != nullptr)
    {
        cout << "Nama: " << temp->nama << "\t"
             << "Usia: " << temp->usia << endl;
        temp = temp->next;
    }
};

int main()
{
    int choice, pilihan;
    string nama, namaSebelum, namaBaru, newnama;
    int usia;

    do
    {

        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Update Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Tampilkan Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            do
            {
                cout << "1. Insert Data Awal" << endl;
                cout << "2. Insert Data Selanjutnya" << endl;
                cout << "3. Insert Data Tengah" << endl;
                cout << "4. Kembali ke menu sebelumnya" << endl;
                cout << "Masukkan Pilihan : ";
                cin >> pilihan;
                switch (pilihan)
                {
                case 1:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    insertAwal(nama, usia);
                    break;

                case 2:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    insertSelanjutnya(nama, usia);
                    break;

                case 3:

                    cout << "Masukkan nama: ";
                    cin >> nama;
                    cout << "Masukkan usia: ";
                    cin >> usia;
                    cout << "Masukkan nama sebelum data baru: ";
                    cin >> namaSebelum;
                    insertTengah(nama, usia, namaSebelum);

                case 4:
                    cout << "Kembali ke menu utama" << endl;
                    break;

                default:
                    cout << "Pilihan tidak valid" << endl;
                    break;
                }
            } while (pilihan != 4);
            break;
        case 2:
            cout << "Masukkan nama yang akan diupdate: ";
            cin >> nama;
            cout << "Masukkan usia baru: ";
            cin >> usia;
            cout << "Masukkan nama baru: ";
            cin >> newnama;
            updateData(nama, usia, newnama);
            break;
        case 3:
            cout << "Masukkan nama yang akan dihapus: ";
            cin >> nama;
            deleteData(nama);
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Terima kasih telah menggunakan program.\n";
            return 0;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (choice != 5);
    return 0;
}
```

## [Output Program 1]

a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda
![Screenshot (357)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/e6bec4cc-b0c6-4880-a904-967609621947)


b. Hapus data Akechi
![Screenshot (360)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/31d5a668-4906-4bf2-8db0-24ae7e159851)


c. Tambahkan data berikut diantara John dan Jane : Futaba 18
![Screenshot (361)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/0a8eef26-25d0-44dc-b0b5-3778a26932e6)
![Screenshot (362)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/dbddb07a-ab8b-4d5b-b764-a2d951c4ff71)



d. Tambahkan data berikut diawal : Igor 20

![Screenshot (364)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/0cebe9db-8f1a-463f-9abb-e3142859fe88)


e. Ubah data Michael menjadi : Reyn 18
![Screenshot (365)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/e8abdb15-829d-4614-a4f3-a5b2f71280ac)


f. Tampilkan seluruh data
![Screenshot (365)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/0ce470eb-08c9-4116-a539-8d477aef1dd2)



Kode diatas adalah Penerapan Single Linked List untuk menginputkan data nama dan usia yang telah ditentukan. Kemudian ada 5 menu yang 
akan bekerja sesuai perintah sesuai dengan yang diinputkan pengguna.

## 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di
urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Nama Produk      Harga

Originote       60.000

Somethinc       150.000

Skintific       100.000

Wardah          50.000

Hanasui         30.000   

Case:

1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific

2. Hapus produk wardah

3. Update produk Hanasui menjadi Cleora dengan harga 55.000

4. Tampilkan menu seperti dibawah ini


Toko Skincare Purwokerto

1. Tambah Data

2. Hapus Data

3. Update Data

4. Tambah Data Urutan Tertentu

5. Hapus Data Urutan Tertentu

6. Hapus Seluruh Data

7. Tampilkan Data

8. Exit


Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :

Nama Produk                 Harga

Originote                  60.000

Somethinc                 150.000

Azarine                    65.000

Skintific                 100.000

Cleora                     55.000

## Source Code
```C++
#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node
{
    string nama_produk;
    int harga;
    Node *prev;
    Node *next;
};

// Kelas untuk Doubly Linked List
class DoublyLinkedList
{
private:
    Node *head; // Pointer ke node pertama
    Node *tail; // Pointer ke node akhir
public:
    // Konstruktor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void NewFunction(Node *newNode)
    {
        tail->next = newNode;
    }

    // Fungsi untuk menyisipkan node di akhir linked list
    void insertAtEnd(string nama_produk, int harga)
    {
        Node *newNode = new Node();
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Fungsi untuk menghapus node dengan nama produk tertentu
    void deleteNode(string nama_produk)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->nama_produk == nama_produk)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp != nullptr && temp->nama_produk != nama_produk)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Node dengan nama produk " << nama_produk << " tidak ditemukan." << endl;
            return;
        }
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah harga dari node dengan nama produk tertentu
    void updateData(string nama_produk, int hargaBaru, string namaBaru)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->nama_produk == nama_produk)
            {
                current->harga = hargaBaru;
                current->nama_produk = namaBaru;
                cout << "Data produk " << nama_produk << " berhasil diupdate!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Fungsi untuk menambahkan data pada urutan Node tertentu
    void tambahDataUrutanTertentu(string nama_produk, int harga, int urutan)
    {
        Node *newNode = new Node();
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;

        Node *current = head;
        int pos = 1;
        while (current != NULL && pos < urutan)
        {
            current = current->next;
            pos++;
        }

        if (current == NULL)
        {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
        cout << "Berhasil menambahkan data!" << endl;
    }

    // Fungsi untuk menghapus node berdasarkan urutan yang ditentukan
    void hapusDataUrutanTertentu(int urutan)
    {
        if (head == nullptr)
        {
            cout << "Linked List Kosong." << endl;
            return;
        }

        Node *current = head;
        int pos = 0;
        while (current != nullptr && pos < urutan)
        {
            current = current->next;
            pos++;
        }

        if (current == nullptr || current == tail)
        {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        if (current == head)
        {
            head = current->next;
            if (head != nullptr)
                head->prev = nullptr;
        }
        else if (current == tail)
        {
            tail = current->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Data pada urutan " << urutan << " berhasil dihapus!" << endl;
    }

    // Fungsi untuk menghapus semua node dalam linked list
    void deleteAll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void display()
    {
        Node *temp = head;
        cout << "\nNama Produk\tHarga" << endl;
        while (temp != nullptr)
        {
            cout << temp->nama_produk << "   \t" << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyLinkedList produkList;
    string nama_produk, namaBaru;
    int harga, hargaBaru, urutan;

    // Menambahkan data produk sesuai permintaan
    produkList.insertAtEnd("Originote", 60000);
    produkList.insertAtEnd("Somethinc", 150000);
    produkList.insertAtEnd("Skintific", 100000);
    produkList.insertAtEnd("Wardah", 50000);
    produkList.insertAtEnd("Hanasui", 30000);

    // Menampilkan menu
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;

    int choice;
    while (true)
    {
        cout << "\nMasukkan pilihan Anda: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Masukkan nama produk: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            produkList.insertAtEnd(nama_produk, harga);
            cout << "Berhasil menambahkan data!" << endl;
            break;
        }
        case 2:
        {
            cout << "Masukkan nama produk yang akan dihapus: ";
            cin >> nama_produk;
            produkList.deleteNode(nama_produk);
            cout << "Data dengan nama " << nama_produk << " berhasil dihapus!" << endl;
            break;
        }
        case 3:
        {
            cout << "Masukkan nama produk yang akan diupdate: ";
            cin >> nama_produk;
            cout << "Masukkan harga baru: ";
            cin >> hargaBaru;
            cout << "Masukkan nama produk baru: ";
            cin >> namaBaru;
            produkList.updateData(nama_produk, hargaBaru, namaBaru);
            break;
        }
        case 4:
        {
            cout << "Masukkan nama produk: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            cout << "Masukkan urutan(dihitung dari 0): ";
            cin >> urutan;
            produkList.tambahDataUrutanTertentu(nama_produk, harga, urutan);
            break;
        }
        case 5:
        {
            int urutan;
            cout << "Masukkan urutan produk yang akan dihapus(dihitung dari 0): ";
            cin >> urutan;
            produkList.hapusDataUrutanTertentu(urutan);
            break;
        }
        case 6:
        {
            produkList.deleteAll();
            cout << "Semua data telah dihapus!" << endl;
            break;
        }
        case 7:
        {
            produkList.display();
            break;
        }
        case 8:
        {
            cout << "Terima kasih telah menggunakan program." << endl;
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
        }
    }

    return 0;
}
```

Case:

1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
![Screenshot (367)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/d967f6f0-b98d-4181-90c8-18ab21c0ac35)

2. Hapus produk wardah
![Screenshot (370)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/68b3d3f1-6c07-4ce3-8081-e15f3589de35)

3. Update produk Hanasui menjadi Cleora dengan harga 55.000

![Screenshot (371)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/8c9631ad-6f71-430b-ba0d-d0d3bacaf862)

4. Tampilkan menu seperti dibawah ini
![Screenshot (372)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/0158d8e2-be3f-4166-a45d-576e16c3702f)

Kode diatas merupakan penerapan dari double linked list untuk menginputkan nama dan harga produk. Kemudian terdapat 8 menu yang 
bekerja sesuai perintah yang diinputkan pengguna.

## Kesimpulan
-Fungsi dan kegunaan linked list sebagai berikut:
1.Linked list dapat digunakan untuk mengimplementasikan struktur data lain seperti stack, queue, graf, dll.
2.Digunakan untuk melakukan operasi aritmatika pada bilangan long integer
3.Dipakai untuk representasi matriks rongga.
4.Digunakan dalam alokasi file yang ditautkan.
5.Membantu dalam manajemen memori.

-kelebihan linked list:
 1.Struktur data dinamis: Linked list adalah himpunan dinamis sehingga dapat bertambah dan menyusut saat runtime dengan mengalokasikan dan membatalkan alokasi memori.
 2.Operasi penyisipan dan penghapusan: Operasi penyisipan dan penghapusan cukup mudah dalam linked list. Kita tidak perlu menggeser elemen setelah operasi penyisipan atau penghapusan elemen, hanya alamat yang ada di pointer berikutnya saja yang perlu diperbarui.
 3.Implementasi: Struktur data linier seperti stack dan queue seringkali mudah diimplementasikan menggunakan linked list.

-kekurangan linked list:
1.Traversal: Dalam traversal, linked list lebih banyak memakan waktu dibandingkan dengan array. Akses langsung ke elemen tidak bisa dilakukan pada linked list seperti array yang dapat akses elemen berdasarkan indeks.
2.Penggunaan memori: Linked list memerlukan lebih banyak memori dibandingkan dengan array. 
3.Akses Acak: Akses acak tidak bisa dilakukan dalam linked list karena alokasi memorinya yang dinamis.
## Referensi
[1] Mengenal Single Linked List dalam Struktur Data. https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html

[2]rizkidoank. Pengertian Double Linked List. rizkidoank.com. https://www.rizkidoank.com/2016/10/17/double-linked-list/.

[3]Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya. https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html    




