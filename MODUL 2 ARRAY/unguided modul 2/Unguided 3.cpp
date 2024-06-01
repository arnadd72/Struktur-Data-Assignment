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
