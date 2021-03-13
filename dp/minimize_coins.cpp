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
    ll n,x; cin >> n >> x;
    vector<ll> coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    vector<ll> value(x+1);
    value[0] = 0;
    for (int sum=1;sum<=x;sum++){
        value[sum] = LLONG_MAX;
        for (auto coin: coins){
            if (sum-coin>=0 && value[sum-coin] != LLONG_MAX){
                value[sum] = min(value[sum], value[sum-coin]+1);
            }
        }
    }
    if (value[x]==LLONG_MAX) cout << -1;
    else cout << value[x];
}