#include<iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;  // ✅ Moved inside loop
        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1;  // move left for first occurrence
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int Binaryarr[6] = {1, 2, 3, 4, 4, 5};
    int result = firstOccurrence(Binaryarr, 6, 4);
    cout << "index of 4: " << result << endl;
    return 0;
}
