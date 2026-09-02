#include <bits/stdc++.h>
using namespace std;

// Step 1: Inorder traversal of array representation of CBT
void inorder(vector<int>& arr, vector<int>& in, int n, int index) {
    if (index >= n) return;
    inorder(arr, in, n, 2 * index + 1);
    in.push_back(arr[index]);
    inorder(arr, in, n, 2 * index + 2);
}

// Step 2: Count min swaps to sort
int minSwapsToSort(vector<int>& in) {
    int n = in.size();
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {in[i], i};

    sort(v.begin(), v.end());
    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        // Already visited or in correct place
        if (visited[i] || v[i].second == i)
            continue;

        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            cycleSize++;
        }
        if (cycleSize > 1)
            swaps += (cycleSize - 1);
    }
    return swaps;
}

// Step 3: Main function
int minSwaps(vector<int>& arr) {
    vector<int> in;
    inorder(arr, in, arr.size(), 0);
    return minSwapsToSort(in);
}

int main() {
    vector<int> arr = {5, 6, 7, 8, 9, 10, 11};
    cout << minSwaps(arr);
    return 0;
}
