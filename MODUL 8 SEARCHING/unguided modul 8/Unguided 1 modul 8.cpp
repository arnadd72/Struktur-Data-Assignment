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
