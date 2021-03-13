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

bool pair_compare(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main(){
    int n,a,b; cin >> n;
    vector<pi> times;
    for (int i =0; i<n; i++){
        cin >> a >> b;
        times.push_back(mp(a,b));
    }
    sort(times.begin(), times.end(), pair_compare);
    int count = 0;
    // for (int i = 0; i<n; i++){
    //     cout << times[i].first << " " << times[i].second;
    // }
    for(int i=0; i<n; i++){
        count++;
        a = times[i].first;
        b = times[i].second;
        while ( a < b ){
            if (i+1 == n) break;
            
            a = times[i+1].first;
            if (a >= b) break;
            else i++;
        }
    }
    cout << count;
}