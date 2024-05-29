# <h1 align="center">Laporan Praktikum Modul 9 Graph and Tree </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori









# Guided
## Guided 1
```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
string simpul[7] = { 
    "Ciamis",  
    "Bandung",  
    "Bekasi",  
    "tasikmalaya", 
    "Cianjur",  
    "Purwokerto",  
    "Yogyakarta"  
}; 
 
int busur[7][7] = { 
    {0, 7, 8, 0, 0, 0, 0}, 
    {0, 0, 5, 0, 0, 15, 0}, 
    {0, 6, 0, 0, 5, 0, 0}, 
    {0, 5, 0, 0, 2, 4, 0}, 
    {23, 0, 0, 10, 0, 0, 8}, 
    {0, 0, 0, 0, 7, 0, 3}, 
    {0, 0, 0, 0, 9, 4, 0} 
}; 
 
 
void tampilGraph(){ 
    for (int baris = 0; baris <7; baris ++){ 
        cout <<" " << setiosflags (ios::left)<<setw (15) 
        << simpul [baris] << " : "; 
        for (int kolom = 0; kolom<7; kolom++){ 
            if (busur[baris][kolom]!=0){ 
                cout << " " << simpul[kolom]<< "(" << busur[baris][kolom] 
<< ")"; 
            } 
        } 
        cout << endl; 
    }       
} 
 
int main(){ 
    tampilGraph(); 
    return 0; 
} 
```
## Output Guided 1
![Screenshot (492)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/17f5e7cb-2a16-4373-acf0-b10f5caf8f6f)

Program ini mendefinisikan dan menampilkan graf berarah sederhana yang merepresentasikan beberapa kota di Indonesia dan jarak antar kota tersebut.
Setiap elemen dalam array merepresentasikan jarak dari kota pada indeks baris ke kota pada indeks kolom, dengan nilai nol menunjukkan bahwa tidak ada jalur langsung antara dua kota tersebut,Jika ditemukan jarak yang bukan nol, maka nama kota tujuan dan jaraknya akan ditampilkan.

## Guided 2
```C++
#include <iostream> 
using namespace std; 
 
// PROGRAM BINARY TREE 
// Deklarasi Pohon 
struct Pohon { 
    char data; 
    Pohon *left, *right, *parent; //pointer 
}; 
 
//pointer global 
Pohon *root; 
 
// Inisialisasi 
void init() { 
    root = NULL; 
} 
 
bool isEmpty() { 
    return root == NULL; 
} 
 
Pohon *newPohon(char data) { 
    Pohon *node = new Pohon(); 
    node->data = data; 
    node->left = NULL; 

    node->right = NULL; 
    node->parent = NULL; 
    return node; 
} 
 
void buatNode(char data) { 
    if (isEmpty()) { 
        root = newPohon(data); 
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << 
endl; 
    } else { 
        cout << "\nPohon sudah dibuat" << endl; 
    } 
} 
 
Pohon *insertLeft(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return NULL; 
    } else { 
        if (node->left != NULL) { 
            cout << "\nNode " << node->data << " sudah ada child kiri!" 
<< endl; 
            return NULL; 
        } else { 
            Pohon *baru = newPohon(data); 
            baru->parent = node; 
            node->left = baru; 
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl; 
            return baru; 
        } 
    } 
} 
 
Pohon *insertRight(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return NULL; 
    } else { 
        if (node->right != NULL) { 
            cout << "\nNode " << node->data << " sudah ada child kanan!" 
<< endl; 
            return NULL; 
        } else { 
            Pohon *baru = newPohon(data); 
            baru->parent = node; 
            node->right = baru; 
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl; 
 
            return baru; 
        } 
    } 
} 
 
void update(char data, Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ingin diganti tidak ada!!" << endl; 
        else { 
            char temp = node->data; 
            node->data = data; 
            cout << "\nNode " << temp << " berhasil diubah menjadi " << 
data << endl; 
        } 
    } 
} 
 
void retrieve(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ditunjuk tidak ada!" << endl; 
        else { 
            cout << "\nData node : " << node->data << endl; 
        } 
    } 
} 
 
void find(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    } else { 
        if (!node) 
            cout << "\nNode yang ditunjuk tidak ada!" << endl; 
        else { 
            cout << "\nData Node : " << node->data << endl; 
            cout << "Root : " << root->data << endl; 
 
            if (!node->parent) 
                cout << "Parent : (tidak punya parent)" << endl; 
            else 
                cout << "Parent : " << node->parent->data << endl; 
 
            if (node->parent != NULL && node->parent->left != node && 
node->parent->right == node) 
                cout << "Sibling : " << node->parent->left->data << endl; 
 
            else if (node->parent != NULL && node->parent->right != node 
&& node->parent->left == node) 
                cout << "Sibling : " << node->parent->right->data << 
endl; 
            else 
                cout << "Sibling : (tidak punya sibling)" << endl; 
 
            if (!node->left) 
                cout << "Child Kiri : (tidak punya Child kiri)" << endl; 
            else 
                cout << "Child Kiri : " << node->left->data << endl; 
 
            if (!node->right) 
                cout << "Child Kanan : (tidak punya Child kanan)" << 
endl; 
            else 
                cout << "Child Kanan : " << node->right->data << endl; 
        } 
    } 
} 
 
// Penelusuran (Traversal) 
// preOrder 
void preOrder(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            cout << " " << node->data << ", "; 
            preOrder(node->left); 
            preOrder(node->right); 
        } 
    } 
} 
 
// inOrder 
void inOrder(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            inOrder(node->left); 
            cout << " " << node->data << ", "; 
            inOrder(node->right); 
        } 
    } 
} 
 
// postOrder 
void postOrder(Pohon *node) { 
 
 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            postOrder(node->left); 
            postOrder(node->right); 
            cout << " " << node->data << ", "; 
        } 
    } 
} 
 
// Hapus Node Tree 
void deleteTree(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        if (node != NULL) { 
            if (node != root) { 
                if (node->parent->left == node) 
                    node->parent->left = NULL; 
                else if (node->parent->right == node) 
                    node->parent->right = NULL; 
            } 
            deleteTree(node->left); 
            deleteTree(node->right); 
 
            if (node == root) { 
                delete root; 
                root = NULL; 
            } else { 
                delete node; 
            } 
        } 
    } 
} 
 
// Hapus SubTree 
void deleteSub(Pohon *node) { 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
    else { 
        deleteTree(node->left); 
        deleteTree(node->right); 
        cout << "\nNode subtree " << node->data << " berhasil dihapus." 
<< endl; 
    } 
} 
 
// Hapus Tree 
void clear() {  
 
 
    if (isEmpty()) 
        cout << "\nBuat tree terlebih dahulu!!" << endl; 
    else { 
        deleteTree(root); 
        cout << "\nPohon berhasil dihapus." << endl; 
    } 
} 
 
// Cek Size Tree 
int size(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!!" << endl; 
        return 0; 
    } else { 
        if (!node) { 
            return 0; 
        } else { 
            return 1 + size(node->left) + size(node->right); 
        } 
    } 
} 
 
// Cek Height Level Tree 
int height(Pohon *node) { 
    if (isEmpty()) { 
        cout << "\nBuat tree terlebih dahulu!" << endl; 
        return 0; 
    } else { 
        if (!node) { 
            return 0; 
        } else { 
            int heightKiri = height(node->left); 
            int heightKanan = height(node->right); 
 
            if (heightKiri >= heightKanan) { 
                return heightKiri + 1; 
            } else { 
                return heightKanan + 1; 
            } 
        } 
    } 
} 
 
// Karakteristik Tree 
void characteristic() { 
    int s = size(root); 
    int h = height(root); 
    cout << "\nSize Tree : " << s << endl; 
    cout << "Height Tree : " << h << endl; 
    if (h != 0) 
 
 
        cout << "Average Node of Tree : " << s / h << endl; 
    else 
        cout << "Average Node of Tree : 0" << endl; 
} 
 
int main() { 
    init(); 
    buatNode('A'); 
 
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, 
*nodeJ; 
 
    nodeB = insertLeft('B', root); 
    nodeC = insertRight('C', root); 
    nodeD = insertLeft('D', nodeB); 
    nodeE = insertRight('E', nodeB); 
    nodeF = insertLeft('F', nodeC); 
    nodeG = insertLeft('G', nodeE); 
    nodeH = insertRight('H', nodeE); 
    nodeI = insertLeft('I', nodeG); 
    nodeJ = insertRight('J', nodeG); 
 
    update('Z', nodeC); 
    update('C', nodeC); 
    retrieve(nodeC); 
    find(nodeC); 
    cout << "\nPreOrder :" << endl; 
    preOrder(root); 
    cout << "\n" << endl; 
    cout << "InOrder :" << endl; 
    inOrder(root); 
    cout << "\n" << endl; 
    cout << "PostOrder :" << endl; 
    postOrder(root); 
    cout << "\n" << endl; 
    characteristic(); 
    deleteSub(nodeE); 
    cout << "\nPreOrder :" << endl; 
    preOrder(root); 
    cout << "\n" << endl; 
    characteristic(); 
}

```
## Output Guided 2
![Screenshot (493)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/6755ec99-c69d-4644-a9ca-55d3f457f839)
![Screenshot (494)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/b1997619-94c6-445f-87ab-c453c0b47f1a)

Program ini mengimplementasikan struktur data pohon biner (binary tree) dengan berbagai operasi dasar seperti penambahan node, penghapusan node, penelusuran (traversal), dan pemeriksaan karakteristik Tree.program ini juga menyediakan fungsi untuk memperbarui nilai suatu node, menampilkan data dari node tertentu, mencari node beserta informasinya seperti root, induk, sibling, dan anak. Fungsi penelusuran pre-order, in-order, dan post-order juga diimplementasikan untuk menampilkan data node dalam urutan tertentu. Program juga mencakup fungsi untuk menghapus seluruh Tree atau sub-Tree, serta menghitung ukuran dan tinggi Tree.

# Unguided 
1. Buatlah program graph dengan menggunakan inputan user untuk menghitung 
jarak dari sebuah kota ke kota lainnya.

2.  Modifikasi guided tree diatas dengan program menu menggunakan input data tree 
dari user dan berikan fungsi tambahan untuk menampilkan node child dan 
descendant dari node yang diinput kan!

## [unguided 1]
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


