#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;


bool isPalindrome(string str) {
    stack<char> charStack;
    int length = str.length();

    
    for (int i = 0; i < length / 2; i++) {
        if (isalnum(str[i])) {
            charStack.push(tolower(str[i]));
        }
    }

    for (int i = (length + 1) / 2; i < length; i++) {
        if (isalnum(str[i])) {
            if (charStack.empty() || charStack.top() != tolower(str[i])) { 
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
