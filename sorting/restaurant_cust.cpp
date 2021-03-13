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
    int n, a, b; cin >> n;
    vector<int> arrive(n);
    vector<int> depart(n);
    for (int i=0; i<n;i++){
        cin >> arrive[i];
        cin >> depart[i];
    }
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());

    int count=0, best=0; a=0; b=0;
    while(a != n && b!= n){
        if(arrive[a] < depart[b]){
            a++;
            count++;
        }
        else{
            b++;
            count--;
        }
        if (count > best) best = count;
    }
    cout << best;
}