#include <iostream>
using namespace std;

int main() {
    long long n, divisor = 5, ans = 0;
    cin >> n;
    while (divisor <= n ){
        ans += n / divisor;
        divisor *= 5;
    }
    cout << ans;
}