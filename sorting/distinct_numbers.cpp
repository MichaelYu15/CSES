#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int main(){
    int n, value;
    cin >> n;
    vector<int> visited;
    for (int i=0; i<n; i++ ){
        cin >> value;
        visited.push_back(value);
    }
    sort(visited.begin(), visited.end());
    int count = 1, prev = visited[0];
    for (int i=1; i<n; i++ ){
        if (visited[i] != prev){
            count++;
            prev = visited[i];
        }
    }
    cout << count;
}