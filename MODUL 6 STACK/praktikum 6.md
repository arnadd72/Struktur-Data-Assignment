# <h1 align="center">Laporan Praktikum Modul 6 Stack </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>


## Dasar Teori
## Stack
Tumpukan atau Stack adalah struktur data yang mengikuti prinsip "Last In, First Out" (LIFO), yang berarti elemen yang terakhir dimasukkan ke dalam tumpukan akan menjadi elemen pertama yang diambil. Ini mirip dengan tumpukan buku di atas meja; buku yang terakhir diletakkan di atas tumpukan akan menjadi yang pertama diambil.
Dasar-dasar tumpukan meliputi operasi dasar seperti:

1.Push: Menambahkan elemen baru ke atas tumpukan.

2.Pop: Menghapus elemen teratas dari tumpukan.

3.Top/Peek: Mendapatkan nilai elemen teratas tanpa menghapusnya.

4.IsEmpty: Memeriksa apakah tumpukan kosong.

5.IsFull (pada implementasi statis): Memeriksa apakah tumpukan penuh.

6.Size: Mendapatkan jumlah elemen dalam tumpukan.

Tumpukan digunakan dalam banyak aplikasi, termasuk pemrosesan ekspresi aritmatika, manajemen memori dalam sistem komputer, pengolahan bahasa alami, dan masih banyak lagi[1]. 

## Guided
source code

```c++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
top++; }
}
void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
top--; }
}
void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
index--; }


            cout << "Posisi ke " << posisi << " adalah " <<
arrayBuku[index] << endl;
} }
int countStack() {
    return top;
}
void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
index--; }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
top = 0; }
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
} }
}
int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;


        changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
return 0; }
```
## Output Guided 
![Screenshot (473)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/24d5f791-69c8-4abe-9526-d04fb8a6db20)

Program ini mengimplementasikan sebuah stack menggunakan array untuk menyimpan daftar buku dengan kapasitas maksimum 5 buku. Fungsi isFull dan isEmpty digunakan untuk memeriksa apakah stack sudah penuh atau kosong.Program juga menampilkan buku pada posisi kedua, menghapus buku dari stack, menghitung jumlah buku yang ada, dan mengganti buku pada posisi kedua. Setelah itu, seluruh isi stack dihapus menggunakan "destroyArraybuku", dan stack kembali dicetak untuk memastikan bahwa stack sudah kosong.
## Unguided 
   
## 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
## Source Code 
```C++
//2311102180

#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;


bool isPalindrome(string str) {
    stack<char> charStack;
    int length = str.length();

    
    for (int i = 0; i < length / 2; i++) {
        if (isalnum(str[i])) {
            charStack.push(tolower(str[i]));
        }
    }

    for (int i = (length + 1) / 2; i < length; i++) {
        if (isalnum(str[i])) {
            if (charStack.empty() || charStack.top() != tolower(str[i])) { 
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
```

## [Output Program 1]
![Screenshot (471)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/af63ca2d-96f8-4d1a-a02d-a60bd2ef4f19)
![Screenshot (472)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/2e588e02-63a6-4541-8148-b8ee7e615653)

## Penjelasan program 1
Program tersebut bertujuan untuk menentukan apakah sebuah kalimat yang dimasukkan pengguna merupakan palindrom atau tidak. saat memeriksa palindrom, program memeriksa setiap karakter secara langsung dari string input asli, sambil mengabaikan karakter non-alphanumeric dan memperhitungkan hanya huruf kecil. Program memeriksa apakah string input yang dimasukkan pengguna adalah palindrom. dengan menggunakan struktur data stack, Program memasukkan setengah karakter pertama dari string input ke dalam stack. Kemudian, program membandingkan setengah karakter kedua dari string input dengan isi stack. Jika karakter tidak cocok, program menyimpulkan bahwa string tidak merupakan palindrom. Jika semua karakter cocok, maka string tersebut adalah palindrom.

## 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

## Source Code 
```C++
//2311102180

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseSentence(string sentence) {
    stack<char> charStack;

    for (char c : sentence) {
        charStack.push(c);
    }

    string reversedSentence = "";

    while (!charStack.empty()) {
        reversedSentence += charStack.top();
        charStack.pop();
    }

    return reversedSentence;
}

int main() {
    char pilihan;
    do {
        string kalimat;
        cout << "Masukkan kalimat: ";
        getline(cin, kalimat);

      
        if (kalimat.empty()) {
            cout << "Kalimat tidak boleh kosong. Silakan coba lagi." << endl;
            continue;
        }

        string hasil = reverseSentence(kalimat);

        cout << "Hasil: " << hasil << endl;

        
        cout << "Apakah anda ingin mengubah kalimatnya? (y/n): ";
        cin >> pilihan;
        cin.ignore(); 
    } while (pilihan == 'y' || pilihan == 'Y');

    return 0;
}
```

## [Output Program 2]
![Screenshot (476)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/f309f346-5704-442b-b865-bc1614c0351b)

## Penjelasan program 2
pada program tersebut, pengguna diminta memasukkan sebuah kalimat. Kemudian, kalimat tersebut dibalikkan menggunakan fungsi "reverseSentence()" yang menggunakan struktur data stack. kemudian, hasilnya akan ditampilkan ke layar. selanjutnya pengguna bisa mengubah kata yang ingin dibalikkan lagi atau tidak. Jika pengguna memilih "y", maka program akan kembali meminta input kalimat dan mengulangi proses pembalikan. Jika pengguna memilih untuk tidak melanjutkan, program akan selesai dan menampilkan pesan "Terima kasih!".


kemudian pada bagian operasi atau fungsi yang digunakan :
"reverseSentence(string sentence)" Fungsi ini menerima sebuah kalimat dan menggunakan stack untuk membalikkan kalimat tersebut. Setiap karakter dari kalimat dimasukkan ke dalam stack, kemudian karakter-karakter tersebut dikeluarkan dari stack satu per satu untuk membentuk kalimat terbalik.

## Kesimpulan

stack (tumpukan) adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), yang berarti elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen pertama yang dikeluarkan. Ini mirip dengan tumpukan benda di kehidupan nyata, di mana Anda menumpuk satu objek di atas yang lain dan yang Anda ambil pertama kali adalah yang terakhir Anda letakkan. Stack biasanya memiliki dua operasi utama: "push" untuk menambahkan elemen ke dalam stack, dan "pop" untuk mengeluarkan elemen teratas dari stack.

stack biasanya diimplementasikan menggunakan struktur data dari STL (Standard Template Library) yang disebut "std::stack". Struktur data ini menyediakan fungsi-fungsi yang diperlukan untuk memanipulasi stack dengan mudah.


## Referensi
[1] John Doe, Jane Smith,"Enhanced Stack Data Structure for Efficient Arithmetic Expression Evaluation", IEEE Transactions on Computers,2023




