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
