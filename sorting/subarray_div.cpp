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
    ll n, value, sum = 0, count = 0; cin >> n;
    map<ll, ll> prefix_sums;
    prefix_sums[0] = 1;
    for (int i = 0; i<n; i++){
        cin >> value;
        sum += value;
        sum %= n; sum += n; sum %= n;
        if(prefix_sums.count(sum)) {
            count += prefix_sums[sum];
            prefix_sums[sum]++;
        }
        else{
            prefix_sums[sum] = 1;
        }
    }
    cout << count;
}