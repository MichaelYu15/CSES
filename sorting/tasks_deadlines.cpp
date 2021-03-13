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
    long long n, a, d; cin >> n;
    vector<pair<ll, ll>> tasks(n);
    for (int i=0; i<n; i++){
        cin >> a >> d;
        tasks[i] = mp(a,d);
    }
    sort(tasks.begin(), tasks.end());
    long long reward = 0, time = 0;
    for (auto task: tasks){
        time += task.first;
        reward += task.second - time;
    }
    cout << reward;
}