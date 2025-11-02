#include <iostream>
using namespace std;

void task2() {
    char exp[100];
    char op[] = { '+', '-', '*', '/', '%', '=' };
    int count = 0;
    cout << "Enter an expression: ";
    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {
        for (int j = 0; j < 6; j++) {
            if (exp[i] == op[j]) {
                count++;
                cout << "operator" << count << ": " << exp[i] << endl;
            }
        }
    }
    if (count == 0)
        cout << "No arithmetic operators found" << endl;
}
