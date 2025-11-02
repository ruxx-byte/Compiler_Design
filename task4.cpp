#include <iostream>
using namespace std;

void task4() {
    string s;
    cout << "Enter an identifier: ";
    cin >> s;
    if (isalpha(s[0]) || s[0] == '_') {
        bool valid = true;
        for (int i = 1; i < s.length(); i++) {
            if (!isalnum(s[i]) && s[i] != '_') {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "Valid Identifier" << endl;
        else
            cout << "Invalid Identifier" << endl;
    } else
        cout << "Invalid Identifier" << endl;
}
