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
    int n, x; cin >> n >> x;
    vector<pi> arr(n);
    int value;
    for (int i = 0; i<n; i++){
        cin >> value;
        arr[i] = mp(value, i+1);
    }
    sort(arr.begin(), arr.end());
    int left, right;
    for (int i = n-1; i>=3; i--){
        for (int j = i-1; j>=2; j--){
            left = 0; right = j-1;
            while( left != right ){
                if (arr[left].f + arr[right].f == x - arr[j].f - arr[i].f){
                    cout << arr[left].s << " " << arr[right].s << " " << arr[i].s << " "<< arr[j].s;
                    return 0;
                }
                else if (arr[left].f + arr[right].f > x - arr[i].f - arr[j].f) right--;
                else if (arr[left].f + arr[right].f < x - arr[i].f - arr[j].f) left++;
            }
        }
    }
    cout << "IMPOSSIBLE";
}