# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center" style="font-size:16px;">Arnanda setya nosa putra</p>
<p align="center" style="font-size:16px;">IF-11-E</p>

## Dasar Teori
<p style="text-align: justify; font-size: 12px;"> 

</p>
  
## Guided

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUR ARRAY 3 DIMENSI 
int main()
{
    //Deklarasi Array
    int arr[2] [3] [3];
    //Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "] [" << y << "] [" << z << "] =";
                cin >> arr[x] [y] [z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array [" << x << "] [" << y << "] [" << z << "] = " << arr[x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilkan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

#### Output
![Screenshot (510)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/ce6e2fc7-5392-40e5-9d4a-5cdbc326b788)

![Screenshot (511)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/ae1610cb-ac36-468d-95a1-a675f87a8d78)

Program di atas mendeklarasikan sebuah array 3 dimensi berukuran 2x3x3, kemudian meminta pengguna untuk menginput nilai untuk setiap elemen array tersebut. Setelah semua nilai diinput, program akan mencetak setiap elemen array beserta indeksnya. Akhirnya, program menampilkan semua nilai array dalam bentuk matriks sesuai dimensi yang sudah ditentukan. Program menggunakan tiga loop bersarang untuk mengakses dan memproses elemen-elemen dalam array tersebut.
<br>

### 2. Program Mencari Nilai Maksimal pada Array

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

#### Output
![Screenshot (514)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/b68a54ac-0b28-4b55-9500-815e31ec61c4)

Program di atas meminta pengguna untuk memasukkan panjang array dan nilai-nilai elemen array tersebut. Setelah semua elemen diinput, program mencari nilai maksimum dalam array beserta lokasinya. Nilai maksimum dan posisi elemen tersebut kemudian ditampilkan kepada pengguna.
<br>

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

#### Source Code
```C++
#include <iostream>
using namespace std;

int main()
{
    int array[10];

    cout << "Masukkan Data Array" << endl;
    for (int i = 0; i < 10; i++) 
    {
        cout << "Array ke-" << (i + 1) << " : ";
        cin >> array[i];
    }

    cout << "Data Array: ";
    for (int i = 0; i < 10; i++)
    {
        cout << array[i];
        if (i < 9) cout << ", ";
    }
    cout << endl;

    cout << "Nomor Genap: ";
    for (int i = 0; i < 10; i++)
    {
        if (array[i] % 2 == 0)
        {
            cout << array[i];
            if (i < 9) cout << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    for (int i = 0; i < 10; i++)
    {
        if (array[i] % 2 != 0)
        {
            cout << array[i];
            if (i < 9) cout << ", ";
        }
    }
    cout << endl;

    return 0;
}

  
```

#### Output
![Screenshot (516)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/9dd4095c-6bdd-44f7-be4b-aee1cfd10b4e)


#### Deskripsi Program
Program di atas meminta pengguna untuk menginput 10 angka ke dalam sebuah array, kemudian menampilkan seluruh isi array tersebut, diikuti dengan menampilkan angka-angka genap dan ganjil yang terdapat dalam array. Program menggunakan loop untuk menerima input, menampilkan data array, serta memisahkan dan menampilkan angka genap dan ganjil. Indeks array dimulai dari 0 hingga 9, dan setiap elemen array diperiksa untuk menentukan apakah elemen tersebut genap atau ganjil sebelum ditampilkan.

### 2. Buatlah program Input Array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Source Code
```C++
#include <iostream>
using namespace std;

int main()
{
    int x, y, z;

    cout << "Masukkan Ukuran Array [x][y][z] : ";
    cin >> x >> y >> z;

    int array[x][y][z];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array [" << i << "][" << j << "][" << k << "] = ";
                cin >> array[i][j][k];
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "Data Array:" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Array [" << i << "][" << j << "][" << k << "] = " << array[i][j][k] << endl;
            }
        }
    }
    cout << endl;

    cout << "Array dalam bentuk matriks:" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Lapisan " << i + 1 << ":" << endl;
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << array[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << "Rata-rata setiap lapisan 2D:" << endl;
    for (int i = 0; i < x; i++)
    {
        int sum = 0;
        int count = 0;
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                sum += array[i][j][k];
                count++;
            }
        }
        cout << "Rata-rata lapisan " << i + 1 << ": " << static_cast<float>(sum) / count << endl;
    }
    cout << endl;

    int maks = array[0][0][0];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if (array[i][j][k] > maks)
                {
                    maks = array[i][j][k];
                }
            }
        }
    }
    cout << "Nilai maksimum dari seluruh array: " << maks << endl;

    return 0;
}

```

#### Output
![Screenshot (517)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/58f788e8-fe1c-4285-bef7-7641adbd937e)
![Screenshot (518)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/821ba4d3-fcef-4e7d-8698-b60b1529e8b6)


#### Deskripsi Program
Program di atas meminta pengguna untuk menentukan ukuran array tiga dimensi dan mengisi nilai-nilai elemen dalam array tersebut. Setelah ukuran array ditentukan dan nilai-nilai diinput, program menampilkan setiap elemen array dengan indeks masing-masing.program menghitung dan menampilkan rata-rata dari setiap lapisan dua dimensi dalam array tiga dimensi tersebut. Selain itu, program juga mencari dan menampilkan nilai maksimum dari seluruh elemen array. Dengan demikian, selain menampilkan struktur dan isi dari array, program ini juga menyediakan analisis tambahan berupa rata-rata tiap lapisan dan nilai maksimum keseluruhan.

### 3. BUatlah program menu untuk mencari nilai Maksimum, Minimim, dan Nilai rata-rata dari suatu array dengan input yang dimasukkan oleh user!

#### Source Code
```C++
#include <iostream>
using namespace std;

void menu()
{
    cout << "====== Menu ======" << endl;
    cout << "1. Input Array" << endl;
    cout << "2. Tampilkan Array" << endl;
    cout << "3. Cari Nilai Minimum" << endl;
    cout << "4. Cari Nilai Maksimum" << endl;
    cout << "5. Hitung Rata-Rata" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukkan Pilihan Anda: ";
}

int minimum(int isi[], int size)
{
    int min = isi[0];
    for (int x = 1; x < size; x++)
    {
        if (isi[x] < min)
        {
            min = isi[x];
        }
    }
    return min;
}

int maksimum(int isi[], int size)
{
    int max = isi[0];
    for (int x = 1; x < size; x++)
    {
        if (isi[x] > max)
        {
            max = isi[x];
        }
    }
    return max;
}

float rata(int isi[], int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += isi[i];
    }
    return total / size;
}

int main()
{
    int pil;
    int *bil = nullptr;
    int size = 0;
    char opsi;
    bool isArrayInput = false;

    do
    {
        menu();
        cin >> pil;
        cout << endl;

        switch (pil)
        {
            case 1:
                cout << "Masukkan jumlah elemen array: ";
                cin >> size;
                delete[] bil;
                bil = new int[size];
                cout << "Masukkan bilangan yang Anda inginkan" << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << "Bilangan ke-" << i + 1 << " : ";
                    cin >> bil[i];
                }
                isArrayInput = true;
                break;

            case 2:
                if (isArrayInput)
                {
                    cout << "Data Array yang sudah dimasukkan:" << endl;
                    for (int b = 0; b < size; b++)
                    {
                        cout << bil[b] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "Anda belum menginput array." << endl;
                }
                break;

            case 3:
                if (isArrayInput)
                {
                    cout << "Nilai Minimum: " << minimum(bil, size) << endl;
                }
                else
                {
                    cout << "Anda belum menginput array." << endl;
                }
                break;

            case 4:
                if (isArrayInput)
                {
                    cout << "Nilai Maksimum: " << maksimum(bil, size) << endl;
                }
                else
                {
                    cout << "Anda belum menginput array." << endl;
                }
                break;

            case 5:
                if (isArrayInput)
                {
                    cout << "Nilai Rata-rata adalah: " << rata(bil, size) << endl;
                }
                else
                {
                    cout << "Anda belum menginput array." << endl;
                }
                break;

            case 6:
                cout << "Keluar dari program." << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        if (pil != 6)
        {
            cout << "Apakah Anda ingin memilih menu yang lain? [y/n]: ";
            cin >> opsi;
            cout << endl;
        }

    } while (pil != 6 && (opsi == 'y' || opsi == 'Y'));

    if (bil != nullptr)
    {
        delete[] bil;
    }

    cout << "Selesai." << endl;
    return 0;
}

```

#### Output
![Screenshot (519)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/7a3d5caf-5473-49bc-93d1-497bfd5de173)
![Screenshot (520)](https://github.com/arnadd72/Struktur-Data-Assignment/assets/149177348/7000440d-56ca-4f7d-883f-421dbe4af1ba)


#### Deskripsi Program
Program di atas adalah sebuah program yang menyediakan berbagai pilihan menu untuk pengguna, termasuk input array, menampilkan array, mencari nilai minimum dan maksimum, menghitung rata-rata, serta keluar dari program. Pengguna diminta untuk memilih menu yang diinginkan dengan memasukkan nomor pilihan, dan program akan menangani pilihan tersebut sesuai dengan fungsinya masing-masing. Program menggunakan array dinamis untuk menyimpan elemen-elemen array yang diinput oleh pengguna, sehingga ukuran array dapat disesuaikan dengan jumlah elemen yang diinginkan. Selain itu, program juga memberikan pesan kesalahan jika pengguna mencoba mengakses fitur yang memerlukan input array tanpa terlebih dahulu menginput array. Setelah selesai, program akan mengeluarkan pesan "Selesai" dan berakhir.

## Kesimpulan
<div style="text-align: justify; font-size: 12px;"> 
Array adalah sebuah struktur data yang terdiri dari serangkaian elemen dengan jenis data yang sama, di mana elemen-elemen ini disimpan secara berurutan dalam memori komputer. Jenis array yang umum digunakan meliputi array satu dimensi, array dua dimensi, dan array multidimensi, di mana setiap elemen diidentifikasi oleh indeks yang dimulai dari 0.

Penggunaan array memiliki keuntungan karena memungkinkan penyimpanan banyak nilai dengan satu nama variabel, serta dapat menyimpan data dalam lebih dari satu dimensi. Hal ini membuat array sangat berguna dalam pemrograman untuk menyederhanakan manajemen data dan mengurangi penggunaan variabel. Selain itu, array mempermudah proses pengolahan data seperti pengurutan, pencarian nilai ekstrim, dan perhitungan rata-rata.

penggunaan array juga memiliki kelemahan, di mana alokasi memori yang tepat dan pengelolaan memori yang efisien menjadi kunci untuk mencegah kesalahan atau kebocoran memori. Oleh karena itu, pemahaman yang baik tentang penggunaan dan manajemen array sangat diperlukan untuk menghindari masalah yang mungkin terjadi dalam program yang dibuat.
<div/>
  
## Referensi
[1] 
[2]



