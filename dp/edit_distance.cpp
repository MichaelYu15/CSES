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
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i<=a.size(); i++){
        for (int j =0; j<=b.size(); j++){
            if (i) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i && j) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1]));
        }
    }
    cout << dp[a.size()][b.size()] << endl;
}