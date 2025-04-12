#include<iostream>
using namespace std;

int firstOcurrence(int arr[], int n, int key) {
	int start = 0, end = n - 1;
	int ans = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {

			
			ans = mid;
			end = mid - 1;
		}
		else if (key > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int lastOcurrence(int arr[], int n, int key) {
	int start = 0, end = n - 1;
	int ans = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			ans = mid;
			start = mid + 1;
		}
		else if (key > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	int Binaryarr[6] = {1, 2, 3, 4, 4, 5};

	int first = firstOcurrence(Binaryarr, 6, 4);
	int last = lastOcurrence(Binaryarr, 6, 4);

	cout << "Index of first 4: " << first << endl;
	cout << "Index of last 4: " << last << endl;

	return 0;
}
