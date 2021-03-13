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

// bool compare_index(pi i, pi j) {return i.second < j.second; }

int main() {
    int n, value; cin >> n;
    stack<pi> values;
    for (int i=0; i<n;i++){
        cin >> value;
        while (!values.empty() && values.top().first >= value){
            values.pop();
        }
        if (values.empty()) cout << 0 << " ";
        else cout << values.top().second << " ";
        values.push(mp(value, i+1));
    }
    // int n, value; cin >> n;
    // set<pi> values;
    // for (int i=0;i<n;i++){
    //     cin >> value;
    //     pi holder = mp(value, i+1);
    //     values.insert(holder);
    //     auto it = values.find(holder); 
    //     if (it == values.begin()) cout << 0 << " ";
    //     else cout << (*max_element(values.begin(), it, compare_index)).second << " ";
    // }
}