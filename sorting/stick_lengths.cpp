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
    long long n; cin >> n;
    vector<long long> sticks(n);
    for (int i = 0; i<n; i++){
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());
    long long median;
    // if (sticks.size() % 2 == 1) median = sticks[sticks.size() / 2];
    // else median = sticks[sticks.size()/2];
    median = sticks[sticks.size()/2];
    long long cost = 0;
    for (auto length: sticks){
        cost += abs(length-median);
    }
    cout << cost;
}