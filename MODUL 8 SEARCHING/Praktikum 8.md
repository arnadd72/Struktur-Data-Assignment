# <h1 align="center">Laporan Praktikum Modul 8 Searching </h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

# Dasar Teori
## Searching




# Guided
## Guided 1
```C++
#include <iostream> 
using namespace std; 
int main() 
{ 
    int n = 10; 
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; 
    int cari = 10; 
    bool ketemu = false; 
    int i; 
    // algoritma Sequential Search 
    for (i = 0; i < n; i++) 
    { 
        if (data[i] == cari) 
        { 
            ketemu = true; 
            break; 
        } 
    } 
    cout << "\t Program Sequential Search Sederhana\n " << endl; 
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl; 
    if (ketemu){ 
        cout << "\n angka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } 
    else 
    { 
        cout << cari << " tidak dapat ditemukan pada data." <<endl; 
    } 
    return 0; 
 
} 
```
## Output Guided 1
![Screenshot (483)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/fb2190cb-0827-46d6-a19e-e737c503d788)

## Guided 2
```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
// Deklarasi array dan variabel untuk pencarian 
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7}; 
int cari; 
 
void selection_sort(int arr[], int n) { 
    int temp, min; 
    for (int i = 0; i < n - 1; i++) { 
        min = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min]) { 
                min = j; 
            } 
        } 
        // Tukar elemen 
        temp = arr[i]; 
        arr[i] = arr[min]; 
        arr[min] = temp; 
    } 
} 
 
void binary_search(int arr[], int n, int target) { 
    int awal = 0, akhir = n - 1, tengah, b_flag = 0; 
     
    while (b_flag == 0 && awal <= akhir) { 
        tengah = (awal + akhir) / 2; 
        if (arr[tengah] == target) { 
            b_flag = 1; 
 
            break; 
        } else if (arr[tengah] < target) { 
            awal = tengah + 1; 
        } else { 
            akhir = tengah - 1; 
        } 
    } 
     
    if (b_flag == 1) 
        cout << "\nData ditemukan pada index ke-" << tengah << 
endl; 
    else 
        cout << "\nData tidak ditemukan\n"; 
} 
 
int main() { 
    cout << "\tBINARY SEARCH" << endl; 
    cout << "\nData awal: "; 
    // Tampilkan data awal 
    for (int x = 0; x < 7; x++) { 
        cout << setw(3) << arrayData[x]; 
    } 
    cout << endl; 
     
    cout << "\nMasukkan data yang ingin Anda cari: "; 
    cin >> cari; 
     
    // Urutkan data dengan selection sort 
    selection_sort(arrayData, 7); 
     
    cout << "\nData diurutkan: "; 
    // Tampilkan data setelah diurutkan 
    for (int x = 0; x < 7; x++) { 
        cout << setw(3) << arrayData[x]; 
    } 
    cout << endl; 
     
    // Lakukan binary search 
    binary_search(arrayData, 7, cari); 
     
    return 0; 
}
```
## Output Guided 2
![Screenshot (488)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/b20cb54a-fbb6-41ea-bb19-ba624ac002ea)

# Unguided 
1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang 
sudah di input dengan menggunakan Binary Search! 

2. Buatlah sebuah program yang dapat menghitung banyaknya huruf  vocal dalam 
sebuah kalimat!

3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak  angka 4 
dengan menggunakan algoritma Sequential Search!

## [Source Code unguided 1]
```C++
//2311102180
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;


void selection_sort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}


void binary_search(const vector<char>& arr, char target) {
    int awal = 0, akhir = arr.size() - 1, tengah;
    bool found = false;

    while (!found && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target) {
            found = true;
            break;
        } else if (arr[tengah] < target) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }

    if (found)
        cout << "\nHuruf '" << target << "' ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nHuruf '" << target << "' tidak ditemukan\n";
}

int main() {
    string kalimat;
    char huruf;
  
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nMasukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "\nMasukkan huruf yang ingin dicari: ";
    cin >> huruf;

    vector<char> charArray(kalimat.begin(), kalimat.end());

    cout << "\nData awal: ";
    for (char c : charArray) {
        cout << setw(3) << c;
    }
    cout << endl;

    selection_sort(charArray);

    cout << "\nData diurutkan: ";
    for (char c : charArray) {
        cout << setw(3) << c;
    }
    cout << endl;
    binary_search(charArray, huruf);

    return 0;
}
```
## [Output unguided 1 ]
![Screenshot (485)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/3228374f-b7d6-4e96-8ff6-f5b227b2a9bf)


Program di atas adalah implementasi dari algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat.Program ini memanfaatkan algoritma Binary Search untuk mencari sebuah huruf dalam sebuah kalimat yang sudah diurutkan.
## [Source Code unguided 2]
```C++
//2311102180
#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string kalimat;
    int count = 0;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    for (int i = 0; i < kalimat.length(); i++) {
        char c = tolower(kalimat[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }

    cout << "Kalimat: \"" << kalimat << "\"" << endl;
    cout << "Jumlah huruf vokal dalam kalimat: " << count << endl;

    return 0;
}
```
## [Output Program 2]
### output Program
![Screenshot (486)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/ada392ad-4721-4cf5-babb-e224432ed433)


Program di atas adalah sebuah program sederhana yang menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna.Selanjutnya, program mengiterasi setiap karakter dalam kalimat yang sudah dimasukkan, mengubahnya menjadi huruf kecil, dan memeriksa apakah karakter tersebut adalah huruf vokal


## [Source Code unguided 3]
```C++
//2311102180
#include <iostream>
using namespace std;

int main() {
    int data[] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int n = sizeof(data) / sizeof(data[0]);
    int angka = 4;
    bool ketemu = false;
    int count = 0;

    // Algoritma Sequential Search untuk menghitung kemunculan angka 4
    for (int i = 0; i < n; i++) {
        if (data[i] == angka) {
            ketemu = true;
            count++;
        }
    }

    cout << "\tSequential Search untuk Menghitung banyaknya Angka 4\n" << endl;
    cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu) {
        cout << "Jumlah angka 4 dalam data: " << count << endl;
    } else {
        cout << "Angka 4 tidak ditemukan dalam data." << endl;
    }

    return 0;
}
```
## [Output Program 3]
### output Program
![Screenshot (487)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/7fecf6c7-66e0-4e7b-b34f-98f2d340a046)

 Program tersebut bertujuan untuk menghitung berapa banyak angka 4 yang muncul dalam sebuah array yang sudah ditentukan.program akan menampilkan hasil jumlah kemunculan angka 4 dalam array tersebut. Jika angka 4 tidak ditemukan sama sekali, program akan memberikan pesan yang sesuai.

## Kesimpulan




## Referensi
[1]
 
[2] 


