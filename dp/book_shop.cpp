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
    int n,x; cin >> n >> x;
    vector<pi> books(n);
    int price, pages;
    vi dp(x+1);
    for (int i=0; i<n; i++){
        cin >> price;
        books[i] = mp(price, 0);
    }
    for (int i=0; i<n; i++){
        cin >> pages;
        books[i].second = pages;
    }
    //dp vector keeps the maximum num of pages for each price
    //index = possible price
    //values = maximum pages
    for(auto book: books){
        for (int price = x; price>=book.f; price--){
            if (price - book.f == 0 && dp[price] == 0) dp[price] = book.s;
            else if (dp[price-book.f] != 0)
                dp[price] = max(dp[price], dp[price-book.f] + book.s);
        }
    }
    // for (auto value: dp){
    //     cout << value << " ";
    // }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}