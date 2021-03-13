#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool arr[n] = { false };
    int holder;
    for (int i = 0; i<n-1;i++) {
        cin >> holder;
        arr[holder-1] = true;
    }
    for (int i = 0; i<n; i++) {
        if (arr[i] == false) {
            cout << i+1;
        }
    }
}