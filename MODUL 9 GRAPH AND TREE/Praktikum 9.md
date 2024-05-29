# <h1 align="center">Laporan Praktikum Modul 9 Graph and Tree </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori


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
//2311102180
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string namaMahasiswa;
    string nim;
    Node *next;
};

Node *front = nullptr;
Node *back = nullptr;

bool isFull()
{
    return false;
}

bool isEmpty()
{
    return front == nullptr;
}

void enqueueAntrian(string nama, string nim)
{
    Node *newNode = new Node;
    newNode->namaMahasiswa = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{
    if (isEmpty())
    {
        cout << "Queue Kosong" << endl;
        return;
    }

    Node *temp = front;
    front = front->next;
    delete temp;

    if (front == nullptr)
    {
        back = nullptr;
    }
}

int countQueue()
{
    int count = 0;
    Node *current = front;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue()
{
    while (front != nullptr)
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

void viewQueue()
{
    cout << "Data Queue Mahasiswa:" << endl;
    Node *current = front;
    while (current != nullptr)
    {
        cout << "Nama: " << current->namaMahasiswa << ", NIM: " << current->nim << endl;
        current = current->next;
    }
}

int main()
{
    enqueueAntrian("Abdul", "123456789");
    enqueueAntrian("hasyim", "987654321");
    viewQueue();
    dequeueAntrian();
    viewQueue();

    cout << "Jumlah elemen dalam antrean: " << countQueue() << endl;
    enqueueAntrian("Citra", "1122334455");
    enqueueAntrian("Dewi", "5544332211");
    viewQueue();
    cout << "Jumlah elemen dalam antrean: " << countQueue() << endl;
    clearQueue();
    cout << "Antrean setelah clearQueue:" << endl;
    viewQueue();

    return 0;
}

```
## [Output Program 2]
### output Program
![Screenshot (482)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/8b845e2c-084b-465b-9de8-d87a4d2491aa)

Program ini adalah implementasi antrean (queue) menggunakan linked list. Program ini mencakup operasi dasar seperti menambah elemen ke antrean (enqueue), menghapus elemen dari antrean (dequeue), memeriksa apakah antrean kosong (isEmpty), dan menghitung jumlah elemen dalam antrean (countQueue). Selain itu, program ini memiliki fitur tambahan untuk mengosongkan seluruh antrean (clearQueue) dan menampilkan semua elemen dalam antrean (viewQueue). Implementasi ini memungkinkan penanganan dinamis jumlah elemen tanpa batasan kapasitas yang tetap, berbeda dengan implementasi array yang memiliki keterbatasan kapasitas tetap.

## Kesimpulan
Queue dalam C++ adalah struktur data FIFO yang dapat diimplementasikan dengan array atau linked list. Implementasi dengan array memiliki kapasitas tetap, sedangkan linked list memungkinkan penambahan elemen dinamis. Operasi dasar meliputi EnQueue, DeQueue, IsEmpty, IsFull, dan Peek/Front. Penelitian terbaru menyoroti penggunaan queue dalam optimisasi antrian dan jaringan komputer, serta analisis efisiensi memori dan performa algoritma.




## Referensi
[1] I Gede Wira Kusuma Jaya, Ida Bagus Nyoman Wijana Manuaba, "Kadek Ryan Wijaya, I Putu Surya Pratama Wardhana, I Made Andika Saputra, I Gede Aris Gunadi
,"Analisis Komparasi Algoritma Sorting Antara Metode Brute Force dengan Divide and Conquer",Jurnal Ilmu Komputer Indonesia (JIK) Vol: 5, No. 2, November 2020
 
[2] https://josikie.com/queue-pada-bahasa-pemrograman-c/


