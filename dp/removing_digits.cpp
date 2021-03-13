#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int max_digit(int n){
    vector<int> digits;
    int digit;
    while(n != 0){
        digit = n%10;
        digits.push_back(digit);
        n /= 10;
    }
    return *max_element(digits.begin(), digits.end());
}
int main() {
    int n; cin >> n;
    int steps = 0;
    while(n != 0){
        steps++;
        n -= max_digit(n);
    }
    cout << steps;
    // ll steps = 0;
    // if (n%10 != 0) steps++;
    // steps += (ll) 2 * (n / 10);
    // cout << steps;
}