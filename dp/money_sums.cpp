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
    int n; cin >> n;
    int max_sum = 0;
    vector<int> denoms(n);
    for (int i=0;i<n;i++){
        cin >> denoms[i];
        max_sum += denoms[i];
    }
    vector<bool> sums(max_sum+1, false);
    sums[0] = true;
    int num_sums = 0;
    for (auto denom: denoms){
        for (int i = max_sum; i>=denom; i--){
            if (sums[i-denom]) {
                sums[i] = true;
            }
        }
    }
    for (int i = 1; i<=max_sum; i++){
        if (sums[i]) {
            num_sums++;
        }
    }
    cout << num_sums << endl;
    for (int i = 1; i<=max_sum; i++){
        if (sums[i]) {
            cout << i << " ";
        }
    }
}