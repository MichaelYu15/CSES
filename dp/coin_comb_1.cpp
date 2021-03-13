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
    int n, x; cin >> n >> x;
    vector<ll> coins(n), values(x+1);
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    values[0] = 1;
    for(int sum=1; sum<=x; sum++){
        values[sum] = 0;
        for (auto coin: coins){
            if (sum-coin >= 0){
                values[sum] += values[sum-coin];
                values[sum] %= (ll) 1e9+7;
            }
        }
    }
    cout << values[x];
}