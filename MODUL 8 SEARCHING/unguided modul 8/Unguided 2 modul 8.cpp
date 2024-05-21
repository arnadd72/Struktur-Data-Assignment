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
