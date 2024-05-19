# <h1 align="center">Laporan Praktikum Modul Queue </h1>
<p align="center">Arvel Mahsa Athallah Firdaus-2311102188-IF-11-E</p>

# Dasar Teori
## Pengertian Queue
Antrian (Queue) adalah kumpulan data dimana penambahan elemen hanya bisa
dilakukan pada suatu ujung yaitu rear atau tail atau belakang, dan penghapusan dilakukan melalui
ujung yang lainnya yaitu front atau head atau depan. Antrian FIFO (First In First Out) adalah
elemen yang lebih dulu disisipkan merupakan elemen yang akan lebih dulu diambil.
Operasi-operasi dasar dari sebuah queue :

1. Enqueue : proses penambahan elemen di posisi belakang
   
2. Dequeue : proses pengambilan elemen di posisi depan

Selain operasi dasar di atas, ada pula operasi-operasi lain yang dapat dilakukan terhadap
sebuah queue yaitu :

1. Operasi pemeriksaan queue kosong (fungsi kosong)

2. Operasi pemeriksaan queue penuh (fungsi penuh).
   
3. Operasi inisialisasi queue (fungsi inisialisasi) 

## Karakteristik
Hal-hal/karakteristik yang penting dalam pengelolaan antrian adalah :

1. Elemen antrian : Item-item data yang terdapat/diorganisasikan pada antrian

2. Front : Elemen terdepan dari antrian

3. Tail : Elemen terakhir dari antrian

4. Panjang Antrian : Yaitu banyaknya (jumlah) elemen pada antrian,

   ada dua jenis panjang :

a. Panjang aktual : merepresentasikan banyak item data pada antrian pada suatu saat.

b. Kapasitas antrian : panjang maksimum yang diizinkan pada antrian

5. Status : Merepresentasikan kondisi antrian pada satu saat,

   terdapat 3 jenis status pada antrian, yaitu :

a. Kosong

Bila tidak ada elemen pada antrian, pada kondisi ini tidak mungkin
dilakukan operasi DeQueue terhadap antrian. DeQueue pada
antrian/queue kosong menyebabkan kondisi keselahan Underflow

b. Isi tapi tidak penuh

Bila paling sedikit terdapat satu elemen pada antrian dan paling
banyak (n-1) elemen, dimana n adalah kapasitas antrian.

c. Penuh

Bila jumlah elemen pada antrian mencapai kapasitas antrian.
Pada kondisi ini tidak mungkin dilakukan operasi EnQueue
terhadap antrian. Penambahan elemen baru (EnQueue)
menyebabkan kondidi overflow.
Untuk implementasi struktur data antrian pada program dapat dilakukan
dengan 2 cara, yaitu :

1. Array

2. Linked List 

# Guided
## Guided 1
```C++
//Arvel_2311102188
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
![Screenshot (244)](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/c41ab00e-9765-465c-8980-cc6d1fdcc65d)


# Unguided 
1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi
linked list

2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM
Mahasiswa

## [Source Code 1]
```C++
// no 1
// Arvel Mahsa
//2311102188
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
![output nomor 1](https://github.com/arvelmahsa/Struktur-Data-Assignment/assets/161669026/08ad7b6d-6191-4246-9a2a-397938a66146)

Program diatas adalah penerapan queue dengan konsep single linked list. Dengan konsep linked list user dapat menginputkan
antrean sebanyak mungkin tanpa harus mengubah jumlah array. Dalam linked list perlu mendeklarasikan struct dan node serta 
variabel pointer tambahan seperti diatas. Beberapa konsep yang digunakan pada fungsi queue diganti menggunakan konsep 
linked list.

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
Queue adalah struktur data linier yang mengikuti prinsip First In First Out, elemen yang pertama kali diinputkan akan menjadi elemen yang pertama kali dikeluarkan. Contoh Konsep antrian seperti antrian di kasir atau di loket tiket, dimana orang yang datang pertama akan dilayani terlebih dahulu.
Selain itu Queue bisa menggunakan fungsi Linked List.

## Referensi
[1] Pengertian Queue. 

[file:///C:/Users/Acer/Downloads/ranita%20sari(1).pdf](https://repository.unikom.ac.id/41990/1/pertemuan%203.pdf)

[2] Karakteristik Queue. 

Nixon Erzed, Karakteristik Queue, Struktur data Array pada
STACK dan QUEUE, (8), Halaman 13.
https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F87682%2Fmod_resource%2Fcontent%2F1%2F08_7228_ccs120_112018_pdf.pdf

