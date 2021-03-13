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

ll n, k;
multiset<ll> high;
multiset<ll> low;
ll med = -1;
ll sHigh, sLow;

void fix(){
    ll m = low.size() + high.size();
    if (low.size() > (m+1)/2){
        ll moving = *low.rbegin();
        high.insert(moving); sHigh += moving;
        low.erase(low.find(moving)); sLow -= moving;
    }
    if (high.size() > m/2){
        ll moving = *high.begin();
        low.insert(moving); sLow += moving;
        high.erase(high.find(moving)); sHigh -= moving;
    }
    med = *low.rbegin();
}

void ins(ll value){
    if (med == (ll) -1){
        med = value;
        low.insert(value);
        sLow += value;
        return;
    }

    if (value <= med) {
        low.insert(value);
        sLow += value;
    }
    else {
        high.insert(value);
        sHigh += value;
    }
    fix();
}

void er(ll value){
    if (value <= med){
        low.erase(low.find(value));
        sLow -= value;
    }
    else {
        high.erase(high.find(value));
        sHigh -= value;
    }
    fix();
}

int main(){
    cin >> n >>k;
    vector<ll> arr(n);
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }

    if (k==1){
        for (int i = 0; i<n; i++){
            cout << 0 << " ";
        } 
        return 0;
    }

    for (int i=0;i<k; i++){
        ins(arr[i]);
    }
    cout << sHigh - med*high.size() + med*low.size()-sLow << " ";
    for (int i=0; i<n-k;i++){
        ins(arr[i+k]);
        er(arr[i]);
        cout << sHigh - med*high.size() + med*low.size()-sLow << " ";
    }
}
// int main() {
//     ll n, k, value; cin >> n >> k;
//     ll cost = 0, prev_median;
//     multiset<ll> s;
//     vector<ll> arr(n);
//     for (int i=0; i<k; i++){
//         cin >> value;
//         s.insert(value);
//         arr[i] = value;
//     }
//     auto it = s.begin();
//     advance(it, (k-1)/2);
//     for (int i = 0; i<k; i++){
//         cost += abs(arr[i] - *it);
//     }
//     cout << cost << " "; prev_median = *it;

//     for (int i = 0; i<n-k; i++){
//         cin >> value;
//         arr[i+k] = value;
//         s.insert(value);
//         if (value < *it) it--;
//         if (arr[i] <= *it) it++;
//         s.erase(s.find(arr[i]));

//         cost += abs(prev_median - *it) * ((k+1)/2);
//         cost -= abs(prev_median - *it) * (k - (k+1)/2);
//         cost -= abs(arr[i]-*it);
//         cost += abs(value-*it);
//         cout << cost << " "; prev_median = *it;
//     }
// }