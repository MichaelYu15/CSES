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

int valid_time(long long time, vector<long long> machines, long long goal){
    long long count = 0;
    for (int i = 0; i<machines.size(); i++){
        count += time / machines[i];
    }
    if (count >= goal) return true;
    else return false;
}

int main() {
    long long n, t; cin >> n >> t;
    vector<long long> machines(n);
    for (int i=0; i<n; i++){
        cin >> machines[i];
    }
    long long max_time = *min_element(machines.begin(), machines.end()) * t;
    long long min_time = 0, curr;
    while (min_time != max_time){
        curr = (min_time+max_time) / 2;
        if (valid_time(curr, machines, t)) max_time = curr;
        else min_time = curr + 1;
    }
    // while (min_time != max_time){
    //     curr = (min_time+max_time) / 2;
    //     long long count = 0;
    //     for (int i = 0; i<machines.size(); i++){
    //         count += curr / machines[i];
    //     }
    //     if (count >= t) max_time = curr;
    //     else min_time = curr + 1;
    // }
    cout << max_time;
}