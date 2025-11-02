#include <iostream>
using namespace std;

void task1() {
    string s;
    cout << "Enter input: ";
    cin >> s;
    bool numeric = true;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            numeric = false;
            break;
        }
    }
    if (numeric)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric Constant" << endl;
}
