#include <iostream>
using namespace std;

int main() {
    long long n, a, b, diff;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a >> b;
        diff = max(a,b) - min(a,b);
        if (min(a,b) - diff < 0) cout << "NO" << "\n";
        else if ((min(a,b) - diff) % 3 == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}