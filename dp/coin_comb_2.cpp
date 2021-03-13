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
    int n,x; cin >> n >> x;
    vi coins(n);
    vector<ll> dp(x+1);
    for (int i=0; i<n; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    sort(coins.begin(), coins.end());
    for(auto coin: coins){
        for (int sum=1; sum<=x; sum++){
            if(sum-coin >= 0){
                dp[sum] += dp[sum-coin];
                dp[sum] %= (ll) 1e9+7;
            }
        }
    }
    cout << dp[x];
}
// int main(){
//     int n,x; cin >> n >> x;
//     vi coins(n);
//     vector<vector<ll>> values(n);
//     for (int i=0; i<n; i++){
//         cin >> coins[i];
//         values[i] = vector<ll>(x+1);
//         values[i][0] = 1;
//     }
//     sort(coins.begin(), coins.end());
//     for (int sum = 1; sum <= x; sum ++){
//         if (sum % coins[0] == 0) values[0][sum] = 1;
//         else values[0][sum] = 0;
//         for (int i=1; i<n; i++){
//             values[i][sum] = 0;
//             if (sum-coins[i] >= 0){
//                 values[i][sum] += values[i][sum-coins[i]] + values[i-1][sum-coins[i]];
//                 values[i][sum] %= (ll) 1e9+7;
//             }
//         }
//     }
//     ll ans = 0;
//     for (int i=0;i<n;i++){
//         ans += values[i][x];
//     }
//     cout << ans << " ";
// }