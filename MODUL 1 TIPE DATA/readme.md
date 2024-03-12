# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arnanda setya nosa putra</p>

## Dasar Teori

 
Tipe data adalah adalah sebuah pengklasifikasian data berdasarkan jenis data tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah data akan digunakan. Adapun tipe data yang akan dipelajari, sebagai berikut :
1. Tipe data Primitif
2. Tipe data Abstrak
3. Tipe data Koleksi
   
Tipe data Primitif

Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem, tipe data primitif ini disediakan oleh banyak bahasa pemrograman, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit pada tipe data primitif tergantung pada bahasa pemrograman,compiler dan sistem operasinya. Contoh tipe data primitif adalah :

a. Int : adalah tipe data yang digunakan untuk menyimpan bilangan bulat seperti 12, 1, 4, dan sebagainya.

b. Float : tipe data yang digunakan untuk menyimpan bilangan desimal seperti 1.5, 2.1, 3.14, dan sebagainya.

c. Char : berfungsi untuk menyimpan data berupa sebuah huruf. Biasanya digunakan untuk simbol seperti A, B, C dan seterusnya

d. Boolean : tipe data ini digunakan untuk menyimpan nilai boolean yang hanya memiliki dua nilai yaitu true dan false.

Tipe Data Abstrak

Tipe data abstrak atau yang biasa disebut Abstrak Data Tipe(ADT) merupakan tipe data yang dibentuk oleh programer itu sendiri. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data. Fitur Class adalah fitur Object Oriented Program(OPP) pada bahasa C++ yang mirip dengan fitur data structures Struct pada bahasa C. Keduanya​berfungsi​untuk​membungkus​tipe data di dalamnya sebagai anggota. menurut learn.microsoft.com perbedaan antara Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private.

Tipe Data Koleksi

Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. Ada beberapa tipe data koleksi yang umum digunakan dalam pemrograman, dan di antaranya adalah:


​a.Array : Array adalah struktur data statis yang menyimpan elemen-  elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi. 
 
b.Vector : Vector adalah Standard Template Library (STL) jika di dalam      C/C++ memiliki bentuk std::vector . Umumnya, vector mirip seperti array 
yang memiliki kemampuan untuk menyimpan data dalam bentuk elemenelemen yang alokasi memorinya dilakukan otomatis dan bersebelahan.
Kemampuan vector bukan hanya pada jumlah elemen yang dinamis, vector pada C/C++ juga dilengkapi dengan fitur-fitur pelengkap seperti element access, iterators, capacity, modifiers
 
c.Map : Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pad


## Guided 

### 1. [kalkulator]

```C++
#include <iostream>
using namespace std;

int main (){
    char op;
    float num1,num2;
    cin >> op;
    cin >> num1,num2;

switch (op)
{
    case '+':
    cout << num1 + num2;
    break;

   case '-':
    cout << num1 - num2;
    break;
    
    case '*':
    cout << num1 * num2;
    break;
    
    case '/':
    cout << num1 / num2;
    break;

    default:
    cout << "error! operstor is not ccorrect ";
}
return 0;
}
```
#### Output:
![guided 1](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/d35b0e14-34ab-4e43-89e7-3b916d086770)

Program tersebut adalah sebuah kalkulator sederhana yang meminta pengguna untuk memasukkan operator matematika (+, -, *, /) dan dua bilangan. Berdasarkan operator yang dimasukkan, program akan melakukan operasi yang sesuai (penjumlahan, pengurangan, perkalian, atau pembagian) pada dua bilangan tersebut, dan hasilnya akan ditampilkan. Jika operator yang dimasukkan tidak valid, program akan menampilkan pesan kesalahan.

### 2. [data mahasiswa]

```C++
#include <stdio.h>

struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{

    struct Mahasiswa mhs1, mhs2;

    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);

    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
return 0;
}
```
#### Output:
![guided 2](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/9eaf6b32-0790-4f10-bc8a-b07d39d79c1f)

Program tersebut merupakan contoh penggunaan struktur (struct) dalam bahasa pemrograman C untuk merepresentasikan data mahasiswa. Struktur Mahasiswa memiliki tiga anggota yaitu name untuk menyimpan nama mahasiswa (sebagai string), address untuk menyimpan alamat mahasiswa (sebagai string), dan age untuk menyimpan usia mahasiswa (sebagai integer).
Di dalam fungsi main(), dua variabel bertipe struct Mahasiswa yaitu mhs1 dan mhs2 dideklarasikan. Kemudian, data mahasiswa seperti nama, alamat, dan usia dimasukkan ke dalam masing-masing variabel.
Selanjutnya, data mahasiswa tersebut dicetak ke layar menggunakan fungsi printf() untuk menampilkan informasi masing-masing mahasiswa seperti nama, alamat, dan usia.

### 3. [array]

```C++
#include <iostream>
using namespace std;
int main()
{
    
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
   
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
#### Output:
![guided 3](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/eb6750f7-21ca-4bd7-8f4d-b7ca4fe40678)

Program ini contoh penggunaan array untuk menyimpan sekumpulan data dengan tipe data yang sama dalam satu variabel. terdapat deklarasi dan inisialisasi array nilai 5 elemen yaitu 23, 50, 34, 78, dan 90. Setelah itu, nilai-nilai dari array t dicetak ke layar menggunakan cout untuk menampilkan isi dari masing-masing elemen array. Perlu diperhatikan bahwa indeks array dimulai dari 0, sehingga elemen pertama dari array nilai memiliki indeks 0 (nilai[0]), elemen kedua memiliki indeks 1 (nilai[1]), dan seterusnya.



## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
using namespace std;

// Fungsi integer
void bilangan(int num) {
    cout << "Bilangan integer yang dimasukkan: " << num << endl;

}

// Fungsi karakter
void charakter(char c) {
    cout << "Karakter yang dimasukkan: " << c << endl;
}

int main() {
    int angka;
    char karakter;

    cout << "Masukkan sebuah bilangan integer: ";
    cin >> angka;

    cout << "Masukkan sebuah karakter: ";
    cin >> karakter;

    bilangan(angka);
    charakter(karakter);

    return 0;
}

```
#### Output:

![output unguided 1](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/eae652d9-0d7d-468e-b4d8-201953de1fc7)


1.Program ini terdiri dari dua fungsi,integer untuk menampilkan bilangan integer, dan Character untuk menampilkan karakter.
2.Pada fungsi main, program meminta pengguna untuk memasukkan sebuah bilangan integer dan sebuah karakter.
3.Input bilangan integer dan karakter disimpan dalam variabel angka dan karakter.
4.Selanjutnya, program memanggil fungsi Integer dengan argumen angka dan fungsi Character dengan argumen karakter untuk menampilkan nilai yang dimasukkan pengguna.

Kesimpulan:
Dari program di atas, kita bisa melihat penggunaan tipe data primitif integer (int) dan char (char). Tipe data primitif digunakan untuk menyimpan nilai dasar seperti bilangan bulat (integer) dan karakter. Program-program sederhana seperti ini menunjukkan cara menggunakan tipe data primitif dalam pemrograman, yang merupakan dasar dari banyak aplikasi dan sistem komputer yang kompleks 


#### Full code Screenshot:
![unguided 1](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/861c048c-fea5-4ef6-b14c-02d34e6f6809)

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya ?
Struct dan Class adalah pada akses defaultnya dimana Struct bersifat public dan Class bersifat private.]

```C++
#include <iostream>
using namespace std;

// Definisi struct untuk menampilkan data mahasiswa
struct Mahasiswa {
    string nama;
    int umur;
};
// Definisi class untuk menampilkan data mobil
class Mobil {
private:
    string merek;
    int tahunProduksi;
public:
    // Konstruktor untuk membuat objek Mobil
    Mobil(string merek, int tahunProduksi) {
        this->merek = merek;
        this->tahunProduksi = tahunProduksi;
    }
    // Metode untuk menampilkan informasi mobil
    void tampilkanInfo() {
        cout << "Merek mobil: " << merek << endl;
        cout << "Tahun produksi: " << tahunProduksi << endl;
    }
};
int main() {
    // Menggunakan struct Mahasiswa
    Mahasiswa mhs;
    mhs.nama = "Budi";
    mhs.umur = 20;
    cout << "Nama mahasiswa: " << mhs.nama << endl;
    cout << "Umur mahasiswa: " << mhs.umur << endl;
    // Menggunakan class Mobil
    Mobil mobil("Toyota", 2020);
    mobil.tampilkanInfo();

    return 0;
}

```
#### Output:
![output unguided 2](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/dc10c1e9-1202-4606-a622-d5096a7308b1)


Fungsi dari Class dan Struct Struct digunakan untuk mendefinisikan tipe data yang berisi sekumpulan variabel, sedangkan class digunakan untuk mendefinisikan tipe data yang berisi variabel dan fungsi-fungsi yang terkait. Struct dan class membantu dalam mengorganisasi dan merepresentasikan data dan fungsionalitas dalam program.
	:
Program ini menggunakan struct Mahasiswa untuk merepresentasikan data mahasiswa dengan 2 anggota yaitu nama dan umur. dan menggunakan class Mobil untuk merepresentasikan mobil dengan dua atribut yaitu merek dan tahunProduksi. Dalam class Mobil, terdapat konstruktor untuk inisialisasi objek dan metode tampilkan Info untuk menampilkan informasi mobil.


#### Full code Screenshot:
![unguided 2](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/8683b443-0e11-49c7-b83a-88e80ad7c3e7)


### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map?]

```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
map<string, int> umur;

umur["steven"] = 19;
umur["morgan"] = 18;
umur["alex"] = 20;

    cout << "Umur steven: " << umur["steven"] << endl;
    cout << "Umur morgan: " << umur["morgan"] << endl;
    cout << "Umur alex: " << umur["alex"] << endl;
return 0;
}
```
#### Output:
![output unguided 3](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/85a80324-9264-4b3d-9a7b-63aacd38cc94)


Pada ini menggunakan fungsi map dari library <map> untuk membuat sebuah map yang
memilik key bertipe string dan value bertipe int.

Array adalah struktur data statis yang menyimpan elemen-elemen dengan tipe data yang sama. Elemen-elemen tersebut dapat diakses dengan menggunakan indeks. Array memiliki ukuran tetap yang ditentukan saat deklarasi. Sedangkan
Map terasa mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. Pada map, indeks tersebut diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.

#### Full code Screenshot:
![unguided 3](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/635efd28-85eb-414f-bceb-b3f1eefd7daf)



## Kesimpulan
Tipe data primitif adalah jenis data dasar yang tersedia dalam bahasa pemrograman, seperti integer, float, boolean, dan character. Tipe data primitif ini digunakan untuk menyimpan data sederhana dan umumnya dikelompokkan berdasarkan jenis data yang mereka wakili. Tipe data primitif biasanya memiliki ukuran tetap dan nilai default yang ditentukan.
Tipe data abstrak adalah jenis data yang digunakan untuk mewakili suatu konsep atau objek dalam program, seperti stack, queue, dan list. Tipe data abstrak ini memiliki operasi dan perilaku khusus yang terkait dengan konsep atau objek yang mereka wakili, namun implementasinya tersembunyi dari pengguna. Pengguna hanya perlu menggunakan operasi dan perilaku yang didefinisikan untuk tipe data abstrak tanpa harus memahami bagaimana tipe data abstrak tersebut diimplementasikan.
Tipe data koleksi adalah jenis data yang digunakan untuk menyimpan kumpulan data, seperti array, list, set, dan map. Tipe data koleksi ini memungkinkan pengguna untuk menyimpan dan mengakses banyak data dalam satu waktu. Tipe data koleksi umumnya terdiri dari banyak elemen atau item yang dapat diakses
secara individu melalui indeks atau kunci. Beberapa tipe data koleksi juga memiliki operasi khusus yang dapat digunakan untuk memanipulasi elemen dalam koleksi.

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
