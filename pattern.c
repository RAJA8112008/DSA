#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the Array size: " << endl;
    cin >> n;

    int arr[n];  // declare array of size n

    // Taking data from user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Displaying array elements
    cout << "You entered: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
