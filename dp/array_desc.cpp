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
    int mod = 1e9 + 7;
    int n,m; cin >> n >>m;
    vector<vector<int>> dp(n, vector<int>(m+1,0));
    int x0; cin >> x0;
    if (x0 == 0){
        fill(dp[0].begin(), dp[0].end(), 1);
    }
    else dp[0][x0] = 1;
    
    for(int i =1;i<n;i++){
        cin >> x0;
        if (x0 == 0){
            for(int val = 1; val<=m; val++){
                for (int k : {val-1,val,val+1}) {
                    if (k >= 1 && k <= m) {
                        (dp[i][val] += dp[i-1][k]) %= mod;
                    }
                }
            }
        }
        else{
            for (int k : {x0-1,x0,x0+1}) {
                if (k >= 1 && k <= m) {
                    (dp[i][x0] += dp[i-1][k]) %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        (ans += dp[n-1][j]) %= mod;
    }
    cout << ans << endl;
}

// ll solve(ll a, ll b, ll zeros){
//     if (a == (ll) 0){

//     }
//     else if (b == (ll) 0) {

//     }
//     else{

//     }
// }

// int main() {
//     int n, m; cin >> n >> m;
//     ll a = 0,value, zeros = 0;
//     ll ans = 1;
//     for (int i = 0; i<n-1; i++){
//         cin >> value;
//         if (value == 0) zeros++;
//         else{
//             ans *= solve(a,value, zeros);
//             ans %= (ll) 1e9 + 7;
//             a = value;
//             zeros = 0;
//         }
//     }
//     cin >> value;
//     if (value == 0) zeros++;
//     ans *= solve(a,value, zeros);
//     ans %= (ll) 1e9 + 7;

//     cout << ans << endl;
// }