#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j > 0; j--) {  // Decrement j, not i
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
