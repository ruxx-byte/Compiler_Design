#include <iostream>
using namespace std;

int main() {
    char expression[100];
    char operators[] = { '+', '-', '*', '/', '%', '=' };
    int count = 0;

    cout << "Enter an expression: ";
    cin >> expression;  

    for (int i = 0; expression[i] != '\0'; i++) {
        for (int j = 0; j < 6; j++) {
            if (expression[i] == operators[j]) {
                count++;
                cout << "operator" << count << ":  " << expression[i] << endl;
            }
        }
    }

    if (count == 0) {
        cout << "No arithmetic operators found in the input." << endl;
    }

    return 0;
}

