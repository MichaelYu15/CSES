#include <iostream>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    long long layer, result;
    for (int i = 0; i < n; i++){
        cin >> y >> x;
        layer = max(x,y);
        result = layer * layer;
        if (layer % 2 == 0){
            result -= layer - y;
            result -= x-1;
        }
        else{
            result -= layer - x;
            result -= y-1;
        }
        cout << result << "\n";
    }
}