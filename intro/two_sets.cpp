#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

long long sum_numbers(long long n);

int main() {
    long long n;
    cin >> n;
    if (sum_numbers(n) % 2 == 1){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        long long skip = 0, next, value = sum_numbers(n)/2;
        vector<int> arr;
        vector<int> arr2;
        for (long long i = n; i> 0; i--){
            if (skip == i) continue;
            else if (value == 0) arr2.push_back(i);
            else if (value >= i) {
                value -= i;
                arr.push_back(i);
            }
            else {
                arr2.push_back(i);
                arr.push_back(value);
                skip = value;
                value = 0;
            }
        }
        
        cout << arr.size() << "\n";
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << "\n" << arr2.size() << "\n";
        for (int i = 0; i < arr2.size(); i++){
            cout << arr2[i] << " ";
        }
    }
}

long long sum_numbers(long long n){
    return n*(n+1) / 2;
}