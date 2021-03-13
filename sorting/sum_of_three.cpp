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

// int sum_two(map<int,int> values, int sum){
//     map<int,int>::reverse_iterator it;
//     for( it = values.rbegin(); it != values.rend(); it++){
//         int val = it->first;
        
//     }
// }

int main(){
    int n, x; cin >> n >> x;
    vector<pi> arr(n);
    int value;
    for (int i = 0; i<n; i++){
        cin >> value;
        arr[i] = mp(value, i+1);
    }
    sort(arr.begin(), arr.end());
    int left, right;
    for (int i = n-1; i>=2; i--){
        if (arr[i].first >= x) continue;

        left = 0; right = i-1;
        while( left != right ){
            if (arr[left].first + arr[right].first == x - arr[i].first){
                cout << arr[left].second << " " << arr[right].second << " " << arr[i].second;
                return 0;
            }
            else if (arr[left].first + arr[right].first > x - arr[i].first) right--;
            else if (arr[left].first + arr[right].first < x - arr[i].first) left++;
        }
    }
    cout << "IMPOSSIBLE";
}