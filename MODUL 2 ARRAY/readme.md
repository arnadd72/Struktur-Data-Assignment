# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Arnanda setya nosa putra</p>
<p align="center">231102180</p>
<p align="center">IF 11 E</p>

## Dasar Teori

Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. Berikut ini adalah beberapa jenis array :
1) Array Satu Dimensi
Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu.
Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {1, 2, 3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya hingga indeks 4 merujuk pada elemen kelima.
Contoh :
```C++
   #include <iostream>
using namespace std;
int main() {
   int arr[5] = {9, 3, 5, 2, 1}; //deklarasi array
   cout<< arr[1] << endl;
   cout<< arr[4];
}
```
 Output :
 Praktikum Struktur Data dan Algoritma 1

    3 1
 3) Array Dua Dimensi
Array dua dimensi adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris, sementara indeks kolom menunjukkan posisi elemen dalam kolom.
Contoh :
```C++
   #include <iostream>
using namespace std;
int main() {
  int arr[2][2] = {{3, 2}, {2, 5}};
  for (int i=0; i<2; i++) { //baris
    for(int j=0; j<2; j++) { //kolom
      cout<< arr[i][j] << ends;
};
    cout << endl;
  };
}
```
 Output :
5) Array Mutidimensi
Array multidimensi memiliki kesamaan dengan array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array empat dimensi, array lima dimensi, dan seterusnya.
Contoh :
```C++
#include <iostream>
using namespace std;
int main() {
  int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8,
5, 2}, {9, 2 ,7}}};
  for (int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      for(int k=0; k<3; k++) {
        cout<< arr[i][j][k] << ends;
};
      cout<< endl;
    };
    cout<< endl;
  };
}
```
 Output :
    287 651
852 927

4) Array Empat Dimensi
Contoh :
```C++ 
int arr [3][2][4][4];
```
5) Array Lima Dimensi
Contoh :
```C++
    int arr [2][4][4][3][3];
```
## Guided 

### 1. [array 3 dimensi]

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI int main()
{
// Deklarasi array int arr[2][3][3]; // Input elemen for (int x = 0; x {
for (int y = 0; {
< 2; x++)
y < 3; y++)
for (int z = 0; z < 3; z++) {
cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
cin >> arr[x][y][z]; }
}
cout << endl; }
// Output Array
for (int x = 0; x < 2; x++) {
for (int y = 0; y < 3; y++) {
for (int z = 0; z < 3; z++) {
cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
} }
}
cout << endl;
// Tampilan array for (int x = 0; x {
for (int y = 0; {
< 2; x++)
y < 3; y++)
for (int z = 0; z < 3; z++)
{
cout << arr[x][y][z] << ends;
}
cout << endl; }
cout << endl; }
```
Program di atas adalah sebuah program dalam bahasa C++ yang mengimplementasikan operasi pada array tiga dimensi.

### 2. [nilai maksimum array]
```C++
#include <iostream>
using namespace std;

int main()
{
    int maks,a,i = 1,lokasi;
    cout << "masukan panjang array : ";
    cin >> a;
    int array[a];
    cout << "masukan" << a << "angka\n";
    for (i= 0; i < a; i++)
    {
        cout << "array ke "<< (i) << ": ";
        cin >> array[i];

    }
    maks = array [0];
    for (i = 0; i < a;i++);
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi= i;
        }
    }
    cout<< "nilai maksimum adalah"<< maks << "berada di array ke"<<lokasi<<endl;
}
```
Program di atas adalah sebuah program C++ yang meminta pengguna untuk memasukkan panjang array (jumlah elemen), kemudian meminta pengguna untuk memasukkan angka-angka yang akan dimasukkan ke dalam array. Setelah itu, program akan mencari nilai maksimum dari array yang telah dimasukkan dan menampilkan nilai maksimum beserta lokasinya di dalam array.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
#include <iostream>

using namespace std;

int main() {
    
    
    int arr[] = {1, 2, 3, 4, 5 ,6 ,7 ,8 ,9 ,10};

    cout << "Data array: ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Nomor genap: ";
    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Nomor ganjil: ";
    for (int i = 0; i < 10; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

```
#### Output:
![Screenshot (342)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/fc071f33-9807-46c0-870f-98ea068cbe54)

Program di atas adalah sebuah program C++ yang menampilkan data array, serta memisahkan angka genap dan ganjil dari array tersebut.

#### Full code Screenshot:
![Screenshot (341)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/da26b93e-c91c-4648-bf91-120133d4fe1f)








### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
using namespace std;

int input;
int bil[10];
int minim, maksim;
double rata;

int main(){

    while(true){
    cout << "\t"  << "MENU" << endl;
    cout << "1. INPUT ARRAY" << endl;
    cout << "2. TAMPIL ARRAY" << endl;
    cout << "3. CARI NILAI MINIMMUM" << endl;
    cout << "4. CARI NILAI MAKSIMUM" << endl;
    cout << "5. HITUNG RATA - RATA" << endl;

    cout << "MASUKAN PILIHAN : ";
    cin >> input;

    cout << endl;

    switch (input)
    {
    case 1 : 
        {
            for(int i = 0; i < 10; i++){
                cout << "MASUKAN BILANGAN KE - " << i + 1 << " : ";
                cin >> bil[i];
            }
            cout << endl;
        break;
        }
    case 2 : 
        {
            cout << "ARRAY YANG DI INPUT : ";
            for (int i = 0; i < 10; i++){
                cout << bil[i] << " ";
            }
        cout << endl;
        }
    cout << endl;
    break;
    case 3 :
        {
            minim = bil[0];
            for(int i = 0; i < 10; i++){
                if(bil[i] < minim){
                    minim = bil[i];
                }
            }
            cout << "NILAI MINIMUM DARI ARRAY TERSEBUT : " << minim << endl;
            cout << endl;
        }
    break;
    case 4 :
        {
            maksim = bil[0];
            for (int i = 0; i < 10; i++){
                if(bil[i] > maksim){
                    maksim = bil[i];
                }
            }
            cout << "NILAI MAKSIMUM DARI ARRAY TERSEBUT : " << maksim << endl;
            cout << endl;
        }
    break;
    case 5 :
        {
            for(int i = 0; i < 10; i++){
                rata += bil[i] / 12;
            }
            cout << "RATA - RATA DARI ARRAY TERSEBUT : " << rata;
        }
        cout << endl;
        cout << endl;
        break;
    }
}
    return 0;
}
```
#### Output:

![Screenshot (343)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/975e4572-af02-4a5f-8a66-42a21a8216b1)

Program di atas adalah sebuah program C++ yang menampilkan data array, serta memisahkan angka genap dan ganjil dari array tersebut.

#### Full code Screenshot:
![Screenshot (344)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/27600b5f-f423-4a76-a533-478a7019926f)
![Screenshot (345)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/2cb70694-b6f3-4efa-903c-bd10b99cea39)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
