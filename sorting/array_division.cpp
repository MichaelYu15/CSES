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

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll low = 0, high = LLONG_MAX;
    auto isValid = [&] (ll sum){
        ll temp = 0, groups = 1;
        for (auto x: arr){
            if (x > sum) return false;
            else if (temp + x <= sum) temp += x;
            else {
                temp = x;
                groups++;
            }
        }
        return groups <= k;
    };
    ll ans;
    while (low <= high){
        ll mid = (low + high)/2;
        if (isValid(mid)) {
            high = mid - 1;
            ans = mid;
        }
        else {
            low = mid + 1;
        }
    }
    cout << ans;
}