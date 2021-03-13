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

pair<int, int> reduce_max(vector<int> arr, int i, int j){
    if (arr[i] > arr[j]) return mp(i+1,j);
    else return mp(i,j-1);
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll> (n+1, 0));
    for(int i=n-1; i>=0; i--){
        for (int j=i+1; j<=n; j++){
            if (j-i == 1) dp[i][j] = arr[i];
            else if (j-i == 2) dp[i][j] = max(arr[i], arr[i+1]);
            else {
                pair<int, int> first = reduce_max(arr, i, j-1);
                pair<int, int> second = reduce_max(arr, i+1, j);
                dp[i][j] = max(dp[i][j], arr[j] + dp[first.f][first.s]);
                dp[i][j] = max(dp[i][j], arr[i] + dp[second.f][second.s]);
                cout << dp[i][j] << " " << i << " " << j << endl;
            }
        }
    }
    cout << dp[0][n] << endl;
}