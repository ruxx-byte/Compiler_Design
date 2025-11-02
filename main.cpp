#include <iostream>
using namespace std;

// function declarations
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int main() {
    int choice;

    cout << "Select a task to run (1-7): ";
    cin >> choice;

    switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
