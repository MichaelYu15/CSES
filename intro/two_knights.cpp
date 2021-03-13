#include <iostream>
using namespace std;

int main(){
    long long n;
    long long result;
    cin >> n;
    for (long long i = 1; i<=n; i++){
        if (i == 1) result = 0;
        else if (i == 2) result = 6;
        else if (i == 3) {
            // result += 5*(i*i -3)-
            //             (2*i-1)*(i-1) + 2;
            result = 28;
        }
        else {
            result += 3*(i*i -3) + 
                        4*(i*i-4) + 
                        2*(i-4)*(i*i-5) -
                        (2*i-1)*(i-1) + 2;
        }
        cout << result << "\n";
    }
}