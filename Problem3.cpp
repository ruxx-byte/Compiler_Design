#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    cout << "Enter a line: ";
    getline(cin, input);

    if (input.length() >= 2 && input[0] == '/' && input[1] == '/') {
        cout << "It is a Single Line Comment." << endl;
    }
    else if (input.length() >= 4 && input[0] == '/' && input[1] == '*' &&
             input[input.length() - 2] == '*' && input[input.length() - 1] == '/') {
        cout << "It is a Multi Line Comment." << endl;
    }
    else {
        cout << "It is NOT a Comment Line." << endl;
    }

    return 0;
