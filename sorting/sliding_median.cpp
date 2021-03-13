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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    int n, k, value; cin >> n >> k;
    multiset<int> s;
    vi arr(n);
    for(int i = 0; i<k; i++){
        cin >> value;
        s.insert(value);
        arr[i] = value;
    }
    auto it = s.begin();
    advance(it, (k - 1)/2 );
    // auto it = s.find_by_order((k-1)/2);
    cout << *it << " ";
    for (int i = 0; i<n-k; i++){
        int first = arr[i];

        cin >> value;
        s.insert(value);
        if (value < *it)
            it--;
        // Erase nums[i-k].
        if (first <= *it)
            it++;
        s.erase(s.find(first));
        arr[i+k] = value;
        // auto it = s.find_by_order((k-1)/2);
        // auto it = s.begin();
        // advance(it, (k-1)/2);
        cout << *it << " ";
    }
}