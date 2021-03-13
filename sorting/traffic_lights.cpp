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
#define mp make_pair

int main() {
    int x, n, value; cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> ms;
    ms.insert(x);
    for (int _=0; _<n; _++){
        cin >> value;
        auto upper = s.lower_bound(value);
        auto lower = upper;
        --lower;
        ms.erase(ms.find(*upper-*lower));
        ms.insert(*upper-value);
        ms.insert(value-*lower);
        cout <<  *--ms.end() << " ";
        s.insert(value);
    }
}