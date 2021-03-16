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

int switchBit(int val, int index, const int n) {
    val = val ^ (1 << index);
    cout << bitset<16>(val).to_string().substr(16-n, 16) << "\n";
    for (int i = 0; i < index; i++) {
        val = switchBit(val, i, n);
    }
    return val;
}

int main() {
    int n;
    cin >> n;
    int begin = 0;
    cout << bitset<16>(begin).to_string().substr(16-n, 16) << "\n";
    for (int i = 0; i < n; i++) {
        begin = switchBit(begin, i, n);
    }
}