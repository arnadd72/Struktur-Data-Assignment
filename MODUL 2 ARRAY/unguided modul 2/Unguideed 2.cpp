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
