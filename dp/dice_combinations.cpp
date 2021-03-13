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

int main() {
    ll n; cin >> n;
    vector<ll> arr(n+1);
    arr[0] = 1;
    for (int sum = 1; sum <=n; sum++){
        arr[sum] = 0;
        for (int roll = 1; roll <= 6; roll++){
            if (sum-roll >= 0) {
                arr[sum] += arr[sum-roll];
                arr[sum] %= (ll) 1e9 + 7;
            }
        }
    }
    cout << arr[n] << " ";
}