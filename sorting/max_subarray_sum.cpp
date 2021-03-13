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

int main(){
    int n; cin >> n;
    long long best, value, sum; cin >> best; sum = best;
    for (int i=1; i<n; i++){
        cin >> value;
        best = max((long long)value, best+value);
        if (best > sum) sum = best;
    }
    cout << sum;
    
    // int n; cin >>n;
    // vector<long long> arr(n);
    // long long value;
    // cin >> arr[0];
    // for (int i=1; i<n; i++){
    //     cin >> value;
    //     arr[i] = arr[i-1] + value;
    // }
    // long long max_value = *max_element(arr.begin(), arr.end());
    // vector<long long>::iterator it;
    // it = find (arr.begin(), arr.end(), max_value);
    // int max_index = *it;
    // long long min_value = *min_element(arr.begin(), arr.begin() + max_index);
    // cout << max_value - min_value;
    
    //attempted solution
    //using array of prefix sums

    // int n; cin >>n;
    // vector<long long> arr(n);
    // long long value;
    // cin >> arr[0];
    // for (int i=1; i<n; i++){
    //     cin >> value;
    //     arr[i] = arr[i-1] + value;
    // }
    // long long max_value = arr[0], min_value = 0, min_holder = 0;
    // for(int i = 1; i<n; i++){
    //     if (arr[i] > max_value){
    //         max_value = arr[i];
    //         min_value = min_holder;
    //     }
    //     if (arr[i] < min_holder){
    //         min_holder = arr[i];
    //     }
    // }
    // min_value = max(min_value, (long long)0);
    // cout << max_value - min_value;
}