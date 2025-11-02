#include <iostream>
using namespace std;

void task5() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    float sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Average value = " << sum / n << endl;
}
