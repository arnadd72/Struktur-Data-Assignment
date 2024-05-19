# <h1 align="center">Laporan Praktikum Modul 7 Queue </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori
## Queue
Queue dalam C++ adalah struktur data linear yang mengikuti prinsip FIFO (First In, First Out). Ini berarti elemen yang pertama kali dimasukkan akan menjadi elemen pertama yang dikeluarkan. Queue digunakan dalam berbagai aplikasi seperti manajemen tugas di printer, penjadwalan proses dalam sistem operasi, dan antrian dalam layanan pelanggan.

Implementasi queue dalam C++ sering dilakukan menggunakan array atau linked list. Pada implementasi berbasis array, queue memiliki batas kapasitas yang tetap, sedangkan pada implementasi berbasis linked list, kapasitasnya dapat bertambah sesuai kebutuhan karena node baru bisa ditambahkan secara dinamis[1].

Operasi Dasar Queue 

1.EnQueue: Menambahkan elemen ke bagian belakang antrian.

2.DeQueue: Menghapus elemen dari bagian depan antrian.

3.IsEmpty: Memeriksa apakah antrian kosong.

4.IsFull: Memeriksa apakah antrian penuh (berlaku pada implementasi berbasis array).

5.Peek/Front: Mengambil elemen di depan antrian tanpa menghapusnya.

Implementasi Queue dengan Linked List

Dalam implementasi menggunakan linked list, queue terdiri dari node-node yang dihubungkan satu sama lain. Setiap node memiliki dua komponen: data dan pointer ke node berikutnya. Berikut adalah langkah-langkah dasar dalam implementasi ini:

1.Struct Node: Mendefinisikan struktur node dengan data dan pointer ke node berikutnya.

2.Pointer: Menyimpan alamat node pertama (front) dan node terakhir (rear).

3.Fungsi EnQueue: Menambahkan node baru di akhir linked list.

4.Fungsi DeQueue: Menghapus node dari awal linked list dan mengatur ulang pointer front[2].


# Guided
## Guided 1
```C++
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
## Output Guided 1
![Screenshot (479)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/ec8da461-9921-4ba1-8c4d-046849da1718)
# Unguided 
1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi
linked list

2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM
Mahasiswa

## [Source Code 1]
```C++
//2311102180
#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
struct Node
{
    string data;
    Node *next;
}; // deklarasi node
Node *head, *tail, *newNode, *temp, *del, *current, *count;
// inisalisasi node linked listt
void init()
{
    head = NULL;
    tail = NULL;
}
bool isEmpty()
{ // mengecek apakah linked list nya kososng atau tidak
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tambahAntrean(string data)
{ // Fungsi menambahkan antrian
    newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty())
    { // Kondisi ketika queue kosong
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else
    { // Antrianya ada isi
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void kurangiAntrean()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        if (head->next != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            head = tail = NULL;
        }
    }
}

int hitungQueue()
{ // Fungsi menghitung banyak antrian
    count = head;
    int hitung_antrean = 0;
    while (count != NULL)
    {
        count = count->next;
        hitung_antrean++;
    }
    return hitung_antrean;
}
void bersihkanQueue()
{ // Fungsi menghapus semua antrian
    temp = head;
    while (temp != NULL)
    {
        del = temp;
        temp = temp->next;
        delete del;
    }
    head = tail = NULL;
}

void lihatQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    tambahAntrean("Andi");
    tambahAntrean("Maya");
    lihatQueue();
    cout << "Jumlah antrian = " << hitungQueue() << endl;
    cout << endl;
    kurangiAntrean();
    lihatQueue();
    cout << "Jumlah antrian = " << hitungQueue() << endl;
    cout << endl;
    bersihkanQueue();
    lihatQueue();
    cout << "Jumlah antrian = " << hitungQueue() << endl;
    cout << endl;
    return 0;
}
```
## [Output Program 1 ]
![Screenshot (480)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/3bf21006-30ad-44fa-b629-b9c59abca10c)

Program di atas merupakan implementasi antrean (queue) dengan menggunakan konsep linked list tunggal (single linked list). Dengan menggunakan konsep linked list, pengguna dapat memasukkan antrean sebanyak yang diinginkan tanpa harus mengubah ukuran array. Dalam linked list, perlu dideklarasikan struct dan node serta variabel pointer tambahan seperti yang telah disebutkan. Beberapa konsep yang digunakan dalam fungsi queue diubah dengan menggunakan konsep linked list.
## [Source Code 2]
```C++
// //No2
#include <iostream>
using namespace std;
struct Node
{
    string nama_mhs_188;
    string NIM_mhs_188;
    Node *next;
}; // deklarasi node
Node *head, *tail, *newNode, *temp, *del, *current, *count;

// inisalisasi node linked listt
void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{ // mengecek apakah linked list nya kososng atau tidak
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueAntrian(string nama_mhs_188, string NIM_mhs_188)
{ // Fungsi menambahkan antrian
    newNode = new Node;
    newNode->nama_mhs_188 = nama_mhs_188;
    newNode->NIM_mhs_188 = NIM_mhs_188;
    newNode->next = NULL;

    if (isEmpty())
    { // Kondisi ketika queue kosong
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else
    { // Antrianya ada isi
        tail->next = newNode;
        tail = newNode;
        tail->next = NULL;
    }
}

void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        if (head->next != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            head = tail = NULL;
        }
    }
}

int hitungQueue()
{ // Fungsi menghitung banyak antrian
    count = head;
    int hitung_antrean = 0;
    while (count != NULL)
    {
        count = count->next;
        hitung_antrean++;
    }
    return hitung_antrean;
}
void bersihkanQueue()
{ // Fungsi menghapus semua antrian
    temp = head;
    while (temp != NULL)
    {
        del = temp;
        temp = temp->next;
        delete del;
    }
    head = tail = NULL;
}

void lihatQueue()
{ // Fungsi melihat antrian
    cout << "<<< Data antrian mahasiswa >>>\n " << endl;
    temp = head;
    int nomor = 1;
    while (temp != NULL)
    {
        cout << temp->nama_mhs_188 << ", " << temp->NIM_mhs_188 << " Antrian Nomor : "<< nomor << endl;
        temp = temp->next;
        nomor++;
    }
    cout << endl;
    cout << endl;
}

int main()
{
    int number;
    string nama_mhs_188, NIM_mhs_188;
    while(true)
    {system("cls");
    cout << " MENU ANTREAN MAHASISWA\n\n";
    cout << " 1. Tambahkan     Antrian\n ";
    cout << "2. Hapus Antrian pertama\n";
    cout << " 3. Hitung        Antrian\n";
    cout << " 4. Bersihkan     Antrian\n";
    cout << " 5. Lihat         Antrian\n\n";
    cout << "Choose Number : ";
    cin>> number;
    cout << endl;
    switch(number)
    {
        case 1 : 
        cout << "Masukan Nama Mahasiswa : ";
        cin >> nama_mhs_188;
        cout << "Masukan NIM  Mahasiswa : ";
        cin >> NIM_mhs_188;
        enqueueAntrian(nama_mhs_188,NIM_mhs_188);
        cout << "Antrean berhasil ditambahkan \n\n";
        system("pause");
        break;

        case 2 :
        dequeueAntrian();
        cout << "Antrian Pertama Berhasil Dihapus\n\n";
        system("pause");
        break;

        case 3 :
        cout << "Jumlah Antrean Sekarang : " << hitungQueue() << endl;
        system("pause");
        break;

        case 4 : 
        bersihkanQueue();
        cout << "Antrean Telah Dibersihkan\n\n ";
        system("pause");
        break;

        case 5 :
        lihatQueue();
        system("pause");
        break;

        default :
        cout << "Choose correct number!";
        system ("pause");
        break;
    }
 }
    return 0;
}
```
## [Output Program 2]
### Tampilan Menu Program
![menu ](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/9076f254-4f85-4d14-8e1a-fda615adf381)

### Tampilan Menu Tambahkan Queue
![menu tambah antrean](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/a0d5b75a-03b7-4972-8291-bbe996eb85d7)

### Tampilan Menu Lihat Queue
![menu lihat sebelum dihapus](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/f1280d97-2686-4937-9cf6-42afce00f475)

### Tampilan Menu Hapus Queue
![menu hapus](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/c50457ae-3085-4d61-af8f-12ca34b3d040)

### Tampilan Menu Lihat Queue (Setelah Dihapus)
![menu lihat setelah dihapus](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/b3a8ed54-2e70-4e12-abda-4f8000ba7524)

### Tampilan Menu Hitung Queue (Setelah Dihapus)
![menu hitung setelah dihapus](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/d43c7abd-be14-4e9b-94db-cb69c5cfad97)

### Tampilan Menu Bersihkan Queue
![menu bersihkan](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/8f4ee9b2-473f-4df1-9aa0-217521af50b1)

### Tampilan Menu Lihat Queue (Setelah Dibersihkan)
![tampilan menu lihat setelah dibersihkan](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/417f9626-bd3d-43e4-9ae0-a277eff13093)

Program diatas merupakan penerapan dari nomor 1 dimana konsep queue dari Array diganti dengan linked list. Konsep queue dibuat
menu seperti diatas, kemudian pada fungsi yang akan dijalankan menggunakan konsep single linked list.

## Kesimpulan
Queue dalam C++ adalah struktur data FIFO yang dapat diimplementasikan dengan array atau linked list. Implementasi dengan array memiliki kapasitas tetap, sedangkan linked list memungkinkan penambahan elemen dinamis. Operasi dasar meliputi EnQueue, DeQueue, IsEmpty, IsFull, dan Peek/Front. Penelitian terbaru menyoroti penggunaan queue dalam optimisasi antrian dan jaringan komputer, serta analisis efisiensi memori dan performa algoritma.




## Referensi
[1] I Gede Wira Kusuma Jaya, Ida Bagus Nyoman Wijana Manuaba, "Kadek Ryan Wijaya, I Putu Surya Pratama Wardhana, I Made Andika Saputra, I Gede Aris Gunadi
,"Analisis Komparasi Algoritma Sorting Antara Metode Brute Force dengan Divide and Conquer",Jurnal Ilmu Komputer Indonesia (JIK) Vol: 5, No. 2, November 2020
 
[2] https://josikie.com/queue-pada-bahasa-pemrograman-c/


