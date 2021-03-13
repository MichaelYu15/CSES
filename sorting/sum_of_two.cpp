#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int main(){
    int n, x, value;
    cin >> n >> x;
    vector<int> arr(n);
    map<int, int> values;
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++){
        if(values.count(x - arr[i])){
            cout << i+1 << " " << values[x - arr[i]] << "\n";
            return 0;
        }
        values[arr[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << '\n';
}
// int main(){
//     long long n, x, value;
//     cin >> n >> x;
//     vector<long long> arr;
//     for (int i = 0; i<n; i++){
//         cin >> value;
//         arr.push_back(value);
//     }
//     for (int i = 0; i<n; i++){
//         vector<long long>::iterator it = find(arr.begin(), arr.end(), x-arr[i]);
//         if ( it != arr.end()){
//             cout << i+1 << " " << it - arr.begin()+1;
//             return 0;
//         }
//     }
//     cout << "IMPOSSIBLE";
// }
