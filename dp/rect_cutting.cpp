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
    int a, b; cin >> a>> b;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1, 1e9));

    for (int i = 1; i<=a; i++){
        for (int j=1; j<=b; j++){
            if (i == 1 || j == 1) dp[i][j] = abs(i-j);
            else if (i == j) dp[i][j] = 0;
            else {
                for (int cut = 1; cut < i; cut++){
                    dp[i][j] = min(dp[i][j], dp[cut][j] + dp[i-cut][j] + 1);
                }
                for (int cut = 1; cut < j; cut++){
                    dp[i][j] = min(dp[i][j], dp[i][cut] + dp[i][j-cut] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}