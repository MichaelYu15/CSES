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
    int n, m, k; cin >> n >> m >> k;
    vector<vi> applicants(n, vi(2, 0));
    vi apartments(m);
    for (int i = 0; i < n; i++) {
        cin >> applicants[i][0];
    }
    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }
    sort(apartments.begin(), apartments.end());
    sort(applicants.begin(), applicants.end());
    auto it = applicants.begin();
    int currAparment;
    int res = 0;
    for (int i = 0; i < m; i++) {
        currAparment = apartments[i];
        while (currAparment - (*it)[0] > k || (*it)[1] == 1) {
            it++;
            if (it == applicants.end()) {
                cout << res;
                return 0;
            }
        }
        if (abs(currAparment - (*it)[0]) <= k) {
            res++;
            (*it)[1] = 1;
        }
    }
    cout << res;
}