#include<iostream>
using namespace std;

// This function calculates the sum of elements in the array
int totalsum(int num[], int n) {
    int isum = 0; // Variable to store the total sum
    for(int i = 0; i < n; i++) {
        isum += num[i]; // Adding each element to isum
    }
    return isum; // Return the final sum
}

int main() {
    int n; // To store how many elements we want in the array
    cin >> n; // User inputs the size of the array

    int arr[n]; // Declaring an array of size n

    // Taking n elements as input from the user
    for(int i = 0; i < n; i++) {
        cin >> arr[i]; // Store each number in the array
    }

    // Call the totalsum function and store the result in 'result'
    int result = totalsum(arr, n);

    // Print the final result
    cout << result << endl;

    return 0;
}
