# <h1 align="center">Laporan Praktikum Modul 9 Graph and Tree </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori

# Graph
  Graf adalah struktur data yang terdiri dari sekumpulan simpul (node atau vertex) dan sekumpulan busur (edge) yang menghubungkan pasangan simpul tersebut. Graf dapat digolongkan menjadi beberapa jenis, seperti graf berarah (directed graph) di mana busurnya memiliki arah, dan graf tak berarah (undirected graph) di mana busurnya tidak memiliki arah. Graf juga bisa berbobot (weighted graph), di mana setiap busur memiliki bobot tertentu yang mungkin merepresentasikan jarak, biaya, atau nilai lainnya[1]. 

# Tree
  Pohon(Tree) adalah jenis khusus dari graf yang tidak mengandung siklus dan memiliki satu simpul akar (root) serta simpul-simpul lainnya yang terhubung dalam hierarki. Setiap simpul dalam pohon dapat memiliki sejumlah anak, tetapi setiap anak hanya memiliki satu induk. Pohon biner adalah jenis pohon di mana setiap simpul memiliki paling banyak dua anak, yaitu anak kiri dan anak kanan. Pohon banyak digunakan dalam berbagai aplikasi, termasuk struktur data seperti heap, BST (Binary Search Tree), dan representasi hierarki data seperti file system[2]. 



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
```
## [Output Program 1 ]
![Screenshot (496)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/f76f6a83-ee40-4e3a-a509-ccfb80e52e50)

rogram ini memungkinkan pengguna untuk memasukkan data tentang graf dengan jumlah simpul yang ditentukan oleh pengguna. Program dimulai dengan meminta pengguna untuk memasukkan jumlah simpul yang akan dimasukkan ke dalam graf. Setelah itu, program meminta pengguna untuk memasukkan nama untuk setiap simpul dan bobot antara setiap pasangan simpul.Setelah semua data dimasukkan, program mencetak graf yang dihasilkan dalam bentuk tabel, di mana baris dan kolom mewakili simpul, dan setiap sel menunjukkan bobot antara simpul-simpul yang sesuai.


## [unguided 2]
```C++
#include <iostream>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // Pointer
};

// Pointer global
Pohon *root2311102180;

// Inisialisasi
void init() {
    root2311102180 = NULL;
}

bool isEmpty() {
    return root2311102180 == NULL;
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
        root2311102180 = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
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
            cout << "\nNode " << node->data << " sudah memiliki child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri dari " << node->data << endl;
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
            cout << "\nNode " << node->data << " sudah memiliki child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan dari " << node->data << endl;
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
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
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
            cout << "Root : " << root2311102180->data << endl;

            if (!node->parent)
                cout << "Parent : (tidak memiliki parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;

            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak memiliki sibling)" << endl;

            if (!node->left)
                cout << "Child Kiri : (tidak memiliki child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;

            if (!node->right)
                cout << "Child Kanan : (tidak memiliki child kanan)" << endl;
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
            if (node != root2311102180) {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);

            if (node == root2311102180) {
                delete root2311102180;
                root2311102180 = NULL;
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
        cout << "\nNode subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else {
            deleteTree(root2311102180);
    cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
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
    int s = size(root2311102180);
    int h = height(root2311102180);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}

// Menampilkan Child dari Sebuah Node
void displayChild(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nChild dari node " << node->data << " adalah:";
            if (node->left) {
                cout << " " << node->left->data;
            }
            if (node->right) {
                cout << " " << node->right->data;
            }
            cout << endl;
        }
    }
}

// Menampilkan Descendant dari Sebuah Node
void displayDescendant(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nDescendant dari node " << node->data << " adalah:";
            // Gunakan rekursi untuk mencetak descendant
            if (node->left) {
                cout << " " << node->left->data;
                displayDescendant(node->left);
            }
            if (node->right) {
                cout << " " << node->right->data;
                displayDescendant(node->right);
            }
            cout << endl;
        }
    }
}

int main() {
    init();
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root2311102180);
    nodeC = insertRight('C', root2311102180);
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
    preOrder(root2311102180);
    cout << "\n" << endl;
    cout << "InOrder :" << endl;
    inOrder(root2311102180);
    cout << "\n" << endl;
    cout << "PostOrder :" << endl;
    postOrder(root2311102180);
    cout << "\n" << endl;
    characteristic();
    displayChild(nodeE);
    displayDescendant(nodeB);
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root2311102180);
    cout << "\n" << endl;
    characteristic();
}


```
## [Output Program 2]
### output Program
![Screenshot (482)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/8b845e2c-084b-465b-9de8-d87a4d2491aa)






## Kesimpulan
Graf dan pohon adalah dua struktur data fundamental dalam pemrograman C++. Graf merepresentasikan hubungan umum antar objek, sedangkan pohon merepresentasikan hubungan hierarki(tingkatan atau lapisan). Implementasi dan manipulasi graf dan pohon dalam C++ sangat penting untuk berbagai aplikasi dalam komputasi, dari algoritma graf hingga manajemen data yang efisien.



## Referensi
[1]J. F. Meyer and R. J. Vetter, "Graph Algorithms and Data Structures for C++ Developers," IEEE Transactions on Computers, vol. 68, no. 6, pp. 989-1002, 2019.

[2] L. Nyland and J. Prins, "Parallel Tree Traversal in C++ with Task-Based Programming," ACM Transactions on Parallel Computing, vol. 8, no. 4, pp. 32-45, 2021.

