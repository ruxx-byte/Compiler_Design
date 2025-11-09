#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isAlphabet(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isValidLater(char c) {
    return isAlphabet(c) || isDigit(c) || (c == '_');
}

bool isValidFirst(char c) {
    return isAlphabet(c) || (c == '_');
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open sample.txt" << endl;
        return 1;
    }

    string input;
    getline(file, input);
    file.close();

    if (input.empty()) {
        cout << "\"" << input << "\" is NOT a valid identifier." << endl;
        return 0;
    }

    if (!isValidFirst(input[0])) {
        cout << "\"" << input << "\" is NOT a valid identifier." << endl;
        return 0;
    }

    for (int i = 1; i < input.length(); i++) {
        if (!isValidLater(input[i])) {
            cout << "\"" << input << "\" is NOT a valid identifier." << endl;
            return 0;
        }
    }

    cout << "\"" << input << "\" is a valid identifier." << endl;
    return 0;
}
