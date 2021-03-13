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

bool ok[1000][1000];
ll dp[1000][1000];

int main(){
    int n, index = 0; cin>>n;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        index = 0;
        for (auto it = s.begin(); it< s.end(); it++){
            if (*it == '*') ok[i][index] = false;
            else ok[i][index] = true;
            index++;
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (!ok[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= (ll) 1e9+7;
        }
    }
    cout << dp[n-1][n-1];
}