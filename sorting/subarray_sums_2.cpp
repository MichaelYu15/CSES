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

void solve() {
    ll n, x; cin >> n >>x;
    ll count = 0, value, sum = 0;
    map<ll, ll> subarray_sums;
    subarray_sums[0] = 1;
    for (int i=0; i<n;i++){
        cin >> value;
        sum += value;
        if (subarray_sums.count(sum-x)){
            count += subarray_sums[sum-x];
        }
        if(subarray_sums.count(sum)) subarray_sums[sum]++;
        else subarray_sums[sum] = 1;
    }
    cout << count;
    // long long n, x, value, sum = 0; cin >> n>>x;
    // multiset<ll> subarray_sums;
    // subarray_sums.insert(0);
    // long long count = 0;
    // for (int i=0; i<n;i++){
    //     cin >> value;
    //     sum += value;
    //     count += subarray_sums.count(sum-x);
    //     subarray_sums.insert(sum);
    // }
    // cout << count;
}

int main() {
    solve();
    return 0;
}