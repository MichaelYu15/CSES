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
void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(){
    int n, x; cin >> n >> x;
    vi arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int a = 0, b=0, sum, count = 0;
    sum = arr[a];
    while (b < n){
        if (sum == x){
            count++; a++; b++;
            sum -= arr[a-1];
            sum += arr[b];
        }
        else if (sum > x){
            a++; sum -= arr[a-1];
        }
        else{
            b++;
            sum += arr[b];
        }
    }
    cout << count;
}