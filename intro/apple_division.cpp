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

vector<ll> diff;

void solve(vector<ll> arr, ll group1, ll group2, int index){
    if (index == arr.size()) diff.push_back(abs(group1-group2));
    else{
        solve(arr, group1 + arr[index], group2, index+1);
        solve(arr, group1, group2 + arr[index], index+1);
    }
}

int main() {
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i=0; i<n;i++){
        cin >> arr[i];
    }
    solve(arr, 0,0,0);
    cout << *min_element(diff.begin(), diff.end());
}