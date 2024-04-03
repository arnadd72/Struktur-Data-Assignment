<h1 align="center">Laporan Praktikum Modul Circular And Non Circular </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori
## Linked List Circular
Circular Linked List merupakan suatu linked list dimana tail (node terakhir) menunjuk ke head (node pertama). Jadi tidak ada pointer yang menunjuk NULL. Ada 2 jenis Circular Linked List, yaitu: Circular Single Linked dan List Circular Double Linked List.[1]

## Linked List Non Circular
Linked list non circular adalah struktur data di mana simpul terakhir tidak menunjuk kembali ke simpul pertama, sehingga tidak membentuk lingkaran atau sirkular. Ini berarti bahwa simpul terakhir memiliki nilai pointer NULL, menandakan akhir dari linked list.[2]

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
![Screenshot (377)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/de9709c0-1723-499f-bc4b-bd3a440e958c)

Kode program di atas merupakan implementasi dari single linked list non-circular dalam bahasa C++. Struktur data linked list non-circular terdiri dari sejumlah simpul (nodes), dimana setiap simpul memiliki dua bagian utama: data dan pointer yang menunjuk ke simpul berikutnya dalam urutan. Program ini mendefinisikan sebuah struct Node yang memiliki dua anggota yaitu data dan next yang merupakan pointer ke simpul berikutnya.

## Linked List Circular
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
![Screenshot (378)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/e8b29a7a-12cc-48be-bdac-7d121e906923)

Program di atas merupakan implementasi dari single linked list circular dalam bahasa C++. Single linked list circular adalah struktur data berurutan yang terdiri dari simpul-simpul yang saling terhubung dengan pointer, dan simpul terakhir menunjuk kembali ke simpul pertama, membentuk lingkaran. Pada program tersebut, terdapat struktur data Node yang memiliki dua anggota yaitu data dan next, yang menunjuk ke simpul berikutnya. Fungsi init() digunakan untuk menginisialisasi linked list

# Unguided 
   [Soal]
   Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM
   mahasiswa, dengan menggunakan input dari user.

## Source Code 
```C++
//2311102180
//TUGAS PROGRAM CIRCULAR LINKEDLIST
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
        cout << "Data dalam List tidak ada!" << endl;
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
        cout << "Data dalam List tidak ada!" << endl;
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
        cout << "Data dalam List tidak ada!" << endl;
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
        cout << "Data dalam List tidak ada!" << endl;
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
    cout << "\t PROGRAM CIRCULAR LINKED LIST" << endl;
    cout << "\t ============================"<<endl;
    cout << "\t      =================="<<endl;
    cout << "\t         PILIH OPSI "<<endl;
    cout << "\t----------------------------"<<endl;
    cout << "\t| 1. Tambah Depan          |"<<endl;;
    cout << "\t| 2. Tambah Belakang       |"<<endl;;
    cout << "\t| 3. Tambah Tengah         |"<<endl;;
    cout << "\t| 4. Ubah Depan            |"<<endl;;
    cout << "\t| 5. Ubah Belakang         |"<<endl;;
    cout << "\t| 6. Ubah Tengah           |"<<endl;;
    cout << "\t| 7. Hapus Depan           |"<<endl;;
    cout << "\t| 8. Hapus Belakang        |"<<endl;;
    cout << "\t| 9. Hapus Tengah          |"<<endl;;
    cout << "\t| 10. Hapus List           |"<<endl;;
    cout << "\t| 11. TAMPILKAN            |"<<endl;;
    cout << "\t| 0. KELUAR                |"<<endl;;
    cout << "\t----------------------------"<<endl;
     cout << "   MASUKKAN OPSI : ";
    int pilih_operasi;
    cin >> pilih_operasi;
    cout << endl;
    switch(pilih_operasi)
    {
        case 0 :
        return 0;

        case 1 :
        cout << "====TAMBAH DATA DEPAN====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n"<< endl;
        system("pause");
        break;
        

        case 2 :
        cout << "====TAMBAH DATA BELAKANG====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        tambahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data Sukses ditambahkan \n" << endl;
        system("pause");
        break;
        

        case 3 :
            cout << "====TAMBAH DATA TENGAH====" << endl;
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
        cout << "====UBAH DATA DEPAN====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahDepan(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti!\n" << endl;
        system("pause");
        break;
    
        case 5 :
        cout << "====UBAH DATA BELAKANG====" << endl;
        cout << "Masukan nama : ";
        cin >> nama_mahasiswa;
        cout << "Masukan NIM  : ";
        cin >> NIM_mahasiswa;
        ubahBelakang(NIM_mahasiswa,nama_mahasiswa);
        cout << "Data berhasil diganti\n"<< endl;
        system("pause");
        break;
        

        case 6 :
        cout << "====UBAH DATA TENGAH====" << endl;
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
            cout << "====HAPUS DATA DEPAN====" << endl;
            hapusDepan();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 8 :
            cout << "====HAPUS DATA BELAKANG===="<< endl;
            hapusBelakang();
            cout << "Data Berhasil Dihapus!\n";
            cout << endl;
            system("pause");
            break;
        

        case 9 : 
            cout << "====HAPUS DATA TENGAH===="<< endl;
            cout << "Masukan posisi : ";
            cin >> posisi;
            hapusTengah(posisi);
            cout << "Data nomor " << posisi << " berhasil dihapus!\n" << endl;
            system("pause");
            break;
        

        case 10 :
           cout << "====HAPUS SEMUA DATA===="<< endl;
           cout << " SEMUA DATA TELAH DIHAPUS \n\n";
           system ("pause");
           clearList();
           break;
        

        case 11 : 
            cout << "====DATA MAHASISWA===="<< endl;
            tampil ();
            cout << endl;
            system("pause");
            break;
        
        default : cout << "====Inputan tak valid!====" << endl;
    }
  }while(true);
  return 0;
}
```
# 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa 
berikut contoh tampilan output dari nomor 1:
## Tampilan Menu
![Screenshot (401)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/37cc794a-12f6-4ffc-bf08-74b2e11a1876)


## Tampilan Operasi Tambah
Tambah Depan
![Screenshot (380)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/9caebc81-fd15-43fb-b40a-472b8805a161)

Tambah Tengah
![Screenshot (383)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/d93920cb-52df-4256-ac20-4e6f20fcf177)

## Tampilan Operasi Hapus
Hapus Belakang
![Screenshot (384)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/43a8f32b-094f-4fd2-9ec7-dbd26cc39d53)

Hapus Tengah
![Screenshot (385)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/72c6501e-83e5-4659-84c0-233dfc638671)

## Tampilan Operasi Ubah
Ubah Belakang
![Screenshot (386)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/82219cc7-2ed4-4cb2-95fd-6a0054ccbb2e)

Ubah Tengah
![Screenshot (390)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/561485ab-0f85-4a95-b3b2-70f316241625)

## Tampilan Operasi Tampil Data
![Screenshot (402)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/f29b8f90-3ea3-4123-83ef-f6c3b5922e40)

# 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Screenshot (389)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/3c2fb16d-0ce1-4b37-9654-9c48e6fcb6d1)

# 3. Lakukan perintah berikut :
## a) Tambahkan data berikut diantara Farrel dan Denis : Wati 2330004
![Screenshot (390)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/e4491e9c-563c-4c1a-b907-6c3beda3eff9)

## b) Hapus data Denis
![Screenshot (391)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/5d50e447-903f-4456-836d-fb7c80e1aa15)

## c) Tambahkan data berikut di awal: Owi 2330000
![Screenshot (392)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/28aadfd2-6ad7-48a5-9e24-66cd91f31d20)

## d) Tambahkan data berikut di akhir: David 23300100
![Screenshot (393)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/414711ab-24e6-4198-9861-c7cc3d6a3f7d)

## e) Ubah data Udin menjadi data berikut: Idin 23300045
![Screenshot (394)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/73a42191-a7f9-4b31-8fd8-5c45156e75fd)

## f) Ubah data terakhir menjadi berikut: Lucy 23300101
![Screenshot (395)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/6b63d512-2b9a-49b4-bca5-b2f3318cc538)

## g) Hapus data awal
![Screenshot (396)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/99cdbf95-d2e0-4b43-a510-d3ceee0847aa)

## h) Ubah data awal menjadi berikut: Bagas 2330002
![Screenshot (397)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/1ac88dc4-af4b-4a09-9a5b-686d65c5f7f0)

## i) Hapus data akhir
![Screenshot (399)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/9355a85b-f974-419d-9a6d-5848a25d62b4)

## j) Tampilkan seluruh data
![Screenshot (400)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/dbacf065-f972-42d6-ac99-5396f03bbc60)

## Keterangan Code
Kode di atas adalah implementasi dari program circular linked list dalam bahasa C++. Program ini memiliki struktur data linked list yang terdiri dari simpul-simpul (nodes) yang memiliki dua string yaitu "nama mahasiswa" dan "NIM mahasiswa". Program ini memiliki menu utama untuk memilih operasi-operasi yang ingin dilakukan pada linked list, seperti menambah, mengubah, menghapus, atau menampilkan data.

## Kesimpulan
Dalam pemilihan antara linked list circular dan non-circular tergantung pada kebutuhan spesifik aplikasi. Linked list circular cocok untuk situasi di mana perlu dilakukan iterasi siklus atau ketika aplikasi memerlukan akses cepat ke simpul awal setelah mencapai simpul terakhir. Sementara itu, linked list non-circular lebih umum digunakan dan lebih sederhana dalam implementasinya untuk kebutuhan yang tidak memerlukan sifat siklik dari linked list. 

## Referensi
[1] M. Bahrul Ulum, S.kom, M.Kom. 2019. Modul Kuliah Struktur Data Linked List. available: https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul%20Struktur%20Data-Linked%20List.pdf 

[2] S. Aggarwal, M. Gupta, "Performance Comparison of Circular and Non-Circular Linked Lists," 2020 5th International Conference on Intelligent Computing and Control Systems (ICICCS), Madurai, India, 2020.



