#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
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

bool isKeyword(const string &str) {
    string keywords[] = {
        "int","float","double","char","bool","void",
        "if","else","while","for","return","switch",
        "case","break","continue","true","false"
    };

    for (string k : keywords)
        if (k == str)
            return true;

    return false;
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open sample.txt" << endl;
        return 1;
    }

    string input((istreambuf_iterator<char>(file)),
                 (istreambuf_iterator<char>()));
    file.close();

    vector<string> tokens;
    string current = "";

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (isspace(c)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            continue;
        }

        string ops = "+-*/%(){};=,<>";
        if (ops.find(c) != string::npos) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
            tokens.push_back(string(1, c));
            continue;
        }

        current += c;
    }

    if (!current.empty())
        tokens.push_back(current);

    for (string tok : tokens) {
        if (isKeyword(tok))
            cout << tok << "  ---> KEYWORD\n";

        else if (isValidFirst(tok[0])) {
            bool valid = true;
            for (int i = 1; i < tok.length(); i++)
                if (!isValidLater(tok[i])) valid = false;

            if (valid)
                cout << tok << "  ---> IDENTIFIER\n";
            else
                cout << tok << "  ---> UNKNOWN TOKEN\n";
        }

        else if (isdigit(tok[0])) {
            bool numeric = true;
            for (char c : tok)
                if (!isdigit(c)) numeric = false;

            if (numeric)
                cout << tok << "  ---> NUMBER\n";
            else
                cout << tok << "  ---> UNKNOWN TOKEN\n";
        }

        else
            cout << tok << "  ---> UNKNOWN TOKEN\n";
    }

    return 0;
}
