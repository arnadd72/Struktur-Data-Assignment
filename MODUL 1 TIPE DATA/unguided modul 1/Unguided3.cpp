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