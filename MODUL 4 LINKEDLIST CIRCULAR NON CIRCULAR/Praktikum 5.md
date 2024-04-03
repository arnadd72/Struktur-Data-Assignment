<h1 align="center">Laporan Praktikum Modul Circular And Non Circular </h1>
<p align="center">Arvel Mahsa Athallah Firdaus-2311102188-IF-11-E</p>

# Dasar Teori
## Linked List Circular
Linked List Circular adalah jenis struktur data yang menggunakan teknologi Linked List untuk menyimpan data secara linier dan berurutan. Namun, Linked List Circular tidak memiliki awal atau akhir – ini pada dasarnya adalah sebuah cincin dari node. Hal ini membuat Linked List Circular ideal untuk aplikasi yang datanya perlu diproses dalam putaran berkelanjutan, seperti aplikasi atau simulasi waktu nyata.

## Linked List Non Circular
Linked List Non Circular adalah Struktur Data linier, yang terdiri dari sekelompok node yang disimpan di alamat acak. Dalam Linked List Non Circular, elemen-elemen ditautkan menggunakan pointer. Selain itu Linked List Non Circular juga merupakan linked list yang bersifat searah, yaitu dapat dilalui hanya dalam satu arah dimulai dari kepala linked list sampai ke simpul akhir (tail).

# Guided
## Linked List Non Circular
source code
```c++
#include <iostream>
using namespace std;
///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi struct node

struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if (head == NULL)
    return true;
    else
    return false;
}

// tambah depan
void insertDepan(int nilai)
{
    // buat node baru
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
    //Buat Node Baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true )
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
        jumlah ++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
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
        baru = new Node ();
        baru->data = data;

        // transversing
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
        if (head->next !=NULL)
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
        cout << "List Kosong!" << endl;
    }
}

//Hapus Belakang
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
        cout << "List Kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkuan" << endl;
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
            if (nomor == posisi -1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// ubah depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
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

// ubah belakang
void ubahBelakang(int data)
{
    if (isEmpty() == 0)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//hapus list
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

// tampilkan list
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

int main ()
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
    
    insertTengah(7,2);
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

![Screenshot (195)](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/28af9c3f-f997-4110-894c-77348da0a839)

## Linked List Circulsr
Source code

```C++
#include <iostream>
using namespace std;

// PROGRAM SINGLE LINKED LIST CIRCULAR 

// DEKLARASI STRUCT NODE

struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init ()
{
    head = NULL;
    tail = head;
}

//pengecekan
int isEmpty()
{
    if (head == NULL)
    return 1;// true
    else
    return 0;// false
}

//buat node baru
void buatNode(string data)
{
    baru = new Node;
    baru -> data = data;
    baru -> next = NULL;
}

// hitung list
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu -> next;
    }
    return jumlah;
}

// tambah depan
void insertDepan(string data)
{
    // buat node baru
    buatNode (data);

    if(isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru -> next = head;
    }
    else
    {
        while (tail -> next != head)
        {
            tail = tail -> next;
        }
        baru->next = head;
        head = baru;
        tail -> next = head;
    }
}

// tambah belakang 
void insertBelakang(string data)
{
    //buat node baru
    buatNode(data);

    if (isEmpty()==1)
    {
        head = baru;
        tail = head;
        baru-> next = head;
    }
    else
    {
        while (tail -> next != head)
        {
            tail = tail -> next;
        }
        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty()==1)
    {
        head = baru;
        tail = head;
        baru->next=head;
    }
    else
    {
        baru->data = data;
        //transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi -1)
        {
            bantu = bantu ->next;
            nomor ++;
        }
        baru -> next = bantu -> next;
        bantu -> next = baru;
    }
}

//hapus depan
void hapusDepan()
{
    if (isEmpty()== 0)
    {
        hapus = head;
        tail = head;
    }
    if (hapus->next == head)
    {
        head = NULL;
        tail = NULL;

        delete hapus;
    }
    else
    {
        while (tail->next != hapus)
        {
            tail = tail -> next;
        }
        head = head -> next;
        tail -> next = head;
        hapus -> next = NULL;

        delete hapus;
    }
}

//hapus belakang
void hapusBelakang()
{
    if (isEmpty()==0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus -> next;
            }
            while (tail->next != hapus)
            {
                tail = tail -> next;
            }
            tail -> next = head;
            hapus -> next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah (int posisi)
{
    if (isEmpty()==0)
    {
        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu -> next;
            nomor++;
        }
        hapus = bantu->next;
        bantu -> next = hapus -> next;

        delete hapus;
    }
    else
    {
        cout << "List masih kososng !" << endl;
    }
}

//hapus list
void clearList()
{
    if (head != NULL)
    {
        hapus = head -> next;

        while (hapus != head)
        {
            bantu = hapus -> next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!"<< endl;
}

//tampilkan list
void tampil ()
{
    if (isEmpty()==0)
    {
        tail = head;
        do
        {
            cout << tail->data<<ends;
            tail = tail->next;
        }
        while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong !"<< endl;
    }
}

int main ()
{
    init ();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();

    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();

    insertTengah("Sapi",2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;

}
```

## Output Guided 2

![Screenshot (196)](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/8fc7155e-eb67-4d02-87ba-942b93436b9a)

# Unguided 
   [Soal]
   Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM
   mahasiswa, dengan menggunakan input dari user.
# 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa 
berikut contoh tampilan output dari nomor 1:
## Tampilan Menu
![output pertama](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/a3987a16-f6d3-449f-91a2-abf17616574f)

## Tampilan Operasi Tambah
Tambah Depan

![tambah depan](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/68a6e6f4-3102-491a-a978-89cfa6d2b0b1)


Tambah Tengah

![tambah tengah](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/6fecb5f7-001d-4ac9-80ae-ded9c1145b50)

## Tampilan Operasi Hapus
Hapus Belakang

![hapus belakang](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/30a7e6c7-69ab-4d69-91c5-a98523f6295e)

Hapus Tengah

![hapus tengah](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/eaf91a3d-d0aa-4ddc-b0a8-56862434e7f4)

## Tampilan Operasi Ubah
Ubah Belakang

![ubah belakang](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/3a816934-4ba4-487f-9104-b688ab376400)

Ubah Tengah

![ubah tengah](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/ea03d49a-47ae-4ff8-8c29-f6000c3a55da)

## Tampilan Operasi Tampil Data
![tampil data](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/2b132dc6-6c50-4ce1-bbc2-62bb7b4a83da)

# 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![tampil 2](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/f19a6780-da92-4be5-a286-1340068fbbbe)

# 3. Lakukan perintah berikut :
## a) Tambahkan data berikut diantara Farrel dan Denis : Wati 2330004
![tambah antara farrel dan denis](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/c9813584-d65d-4ac1-9d15-d01229c2244c)

## b) Hapus data Denis
![hapus denis](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/926c38e4-f26b-4b47-b057-8aed95d05f07)

## c) Tambahkan data berikut di awal: Owi 2330000
![tambah depan owi](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/5264cb1e-c036-4484-8e4d-6dbb4a08a834)

## d) Tambahkan data berikut di akhir: David 23300100
![tambah belakang david](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/23199a7e-d777-40d8-8d8a-ddbf96d7a2d1)

## e) Ubah data Udin menjadi data berikut: Idin 23300045
![ubah tengah idin](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/feaa1b7a-23eb-4b8a-b9c4-636907ebf728)

## f) Ubah data terakhir menjadi berikut: Lucy 23300101
![ubah belakang lucy](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/ebd9a287-7b2f-4060-ab4b-3816add87aa3)

## g) Hapus data awal
![hapus data awal](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/94411661-5ee4-45c9-8fbd-55f096dcd886)

## h) Ubah data awal menjadi berikut: Bagas 2330002
![ubah data awal bagas](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/bf2427a7-b671-4129-8320-00ffedc73805)

## i) Hapus data akhir
![hapus data akhir](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/bcf2a077-ceeb-468f-8ed3-9759701f91ab)

## j) Tampilkan seluruh data
![tampilkan data mahasiswa](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/8d9b982e-62fb-476e-becf-14397ff68f7a)

## Source Code 
```C++
//TUGAS PROGRAM SINGLE LINKED LIST NON CIRCULAR
// Arvel Mahsa Athallah Firdaus
// 2311102188
// IF-11-E
#include <iostream>
using namespace std;

struct Node
{
    string nama_mahasiswa;
    string NIM_mahasiswa;
    Node *next;
};
Node *head;
Node *tail;

//Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

//Pengecekan
bool isEmpty()
{
    if (head == NULL)
    return true;
    else
    return false;
}

// tambah depan
void tambahDepan(string NIM_mahasiswa, string nama_mahasiswa)
{
    // buat node baru
    Node *baru = new Node;
    baru->NIM_mahasiswa = NIM_mahasiswa;
    baru->nama_mahasiswa = nama_mahasiswa;
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
void tambahBelakang(string NIM_mahasiswa, string nama_mahasiswa)
{
    //Buat Node Baru
    Node *baru = new Node;
    baru->NIM_mahasiswa = NIM_mahasiswa;
    baru->nama_mahasiswa = nama_mahasiswa;
    baru->next = NULL;
    if (isEmpty() == true )
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
        jumlah ++;
        hitung = hitung->next;
    }
    return jumlah;
}

//Tambah Tengah
void tambahTengah(string NIM_mahasiswa, string nama_mahasiswa, int posisi)
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
        baru = new Node ();
        baru->NIM_mahasiswa = NIM_mahasiswa;
        baru->nama_mahasiswa = nama_mahasiswa;

        // transversing
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
        if (head->next !=NULL)
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
        cout << "List Kosong!" << endl;
    }
}

//Hapus Belakang
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
        cout << "Data kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkuan" << endl;
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
            if (nomor == posisi -1)
            {
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// ubah depan
void ubahDepan(string NIM_mahasiswa, string nama_mahasiswa)
{
    if (isEmpty() == 0)
    {
        head->NIM_mahasiswa = NIM_mahasiswa;
        head->nama_mahasiswa = nama_mahasiswa;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

//Ubah tengah
void ubahTengah(string NIM_mahasiswa,string nama_mahasiswa, int posisi)
{
    Node *bantu;
    if (isEmpty() == 0)
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
            bantu->NIM_mahasiswa = NIM_mahasiswa;
            bantu->nama_mahasiswa = nama_mahasiswa;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// ubah belakang
void ubahBelakang(string NIM_mahasiswa, string nama_mahasiswa)
{
    if (isEmpty() == 0 )
    {
        tail->NIM_mahasiswa = NIM_mahasiswa;
        tail->nama_mahasiswa = nama_mahasiswa;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

//hapus list
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
    cout << "List kasil dihapus!" << endl;
}

// tampilkan list
void tampil()
{
    Node *bantu;
    bantu = head;
    int nomor = 1;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << nomor << ".      " << bantu->nama_mahasiswa << "            " << bantu->NIM_mahasiswa << endl;
            bantu = bantu->next;
            nomor++;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main ()
{
int posisi;
string nama_mahasiswa,NIM_mahasiswa;
init();
do{
    system("cls");
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan\n";
    cout << "2. Tambah Belakang\n";
    cout << "3. Tambah Tengah\n";
    cout << "4. Ubah Depan\n";
    cout << "5. Ubah Belakang\n";
    cout << "6. Ubah Tengah\n";
    cout << "7. Hapus Depan\n";
    cout << "8. Hapus Belakang\n";
    cout << "9. Hapus Tengah\n";
    cout << "10. Hapus List\n";
    cout << "11. TAMPILKAN\n";
    cout << "0. KELUAR\n";
    cout << "Pilih Operasi : ";
    int pilih_operasi;
    cin >> pilih_operasi;
    cout << endl;
    switch(pilih_operasi)
    {
        case 0 :
        return 0;

        case 1 :
        cout << "TAMBAH DATA DEPAN \n" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n"<< endl;
        system("pause");
        break;
        

        case 2 :
        cout << "TAMBAH DATA BELAKANG\n" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n" << endl;
        system("pause");
        break;
        

        case 3 :
            cout << "TAMBAH DATA TENGAH\n" << endl;
            cout << "Masukan nama   : ";
            cin >> nama_mahasiswa;
            cout << "Masukan NIM    : ";
            cin >> NIM_mahasiswa;
            cout << "Masukan Posisi : ";
            cin >> posisi;
            tambahTengah(NIM_mahasiswa, nama_mahasiswa, posisi);
            cout << "Data Sukses ditambahkan!\n" << endl;
            system("pause");
            break;
        

        case 4 :
        cout << "UBAH DATA DEPAN\n" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti!\n" << endl;
        system("pause");
        break;
    
        case 5 :
        cout << "UBAH DATA BELAKANG\n" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti\n"<< endl;
        system("pause");
        break;
        

        case 6 :
        cout << "UBAH DATA TENGAH\n" << endl;
        cout << "Masukan nama   : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM    : ";
        cin >> NIM_mahasiswa;
        cout << "Masukan Posisi : ";
        cin >> posisi;
        ubahTengah(NIM_mahasiswa,nama_mahasiswa,posisi);
        cout << "Data nomor " << posisi << " berhasil diganti\n" << endl;
        system ("pause");
        break;
        

        case 7 :
            cout << "HAPUS DATA DEPAN\n" << endl;
            hapusDepan();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 8 :
            cout << "HAPUS DATA BELAKANG\n\n";
            hapusBelakang();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 9 : 
            cout << "HAPUS DATA TENGAH\n\n";
            cout << "Masukan posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            cout << "Data nomor " << posisi << " berhasil dihapus!\n" << endl;
            system("pause");
            break;
        

        case 10 :
           cout << "HAPUS SEMUA DATA \n\n";
           cout << "All data removed\n\n";
           system ("pause");
           clearList();
           break;
        

        case 11 : 
            cout << "DATA MAHASISWA \n\n";
            tampil ();
            cout << endl;
            system("pause");
            break;
        
        default : cout << "Inputan tak valid!" << endl;
    }
  }while(true);
  return 0;
}
```
## Keterangan Code
Code diatas merupakan implementasi dari fungsi struct linked list Non Circular. Code diatas berfungsi untuk menyimpan
data nama dan NIM mahasiswa. Selain itu terdapat beberapa menu yang tersedia dengan fungsi yang berbeda-beda.

## Kesimpulan
1. Linked List Non-Circular: Digunakan ketika data terkait harus disimpan dalam urutan tertentu dan tidak ada kebutuhan
   untuk loop atau akses berulang ke elemen.
   
2. Linked List Circular: Digunakan dalam situasi di mana perlu untuk terus mengulang elemen linked list, misalnya dalam
   implementasi buffer cincin atau algoritma tertentu seperti algoritma Floyd Cycle Detection.
   
## Referensi
[1] simplilearn, "Types of Linked List in Data Structures", 2023, https://www.simplilearn.com/tutorials/data-structure-tutorial/types-of-linked-list, [2 April 2024]

[2] PrepBytes Blog, "Know Everything about Linked List in Data Structure", https://www.prepbytes.com/blog/linked-list/a-brief-introduction-to-linked-lists/, [2 April 2024]



