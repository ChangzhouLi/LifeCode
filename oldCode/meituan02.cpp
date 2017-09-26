#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
long long dp[11111];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++)dp[i] = 0;
    dp[0] = 1;
    int a[] = {1, 5, 10, 20, 50, 100};
    for(int i = 0; i < 6; i++){
        for(int j = a[i]; j <= n; j++){
            dp[j] += dp[j - a[i]];
        }
    }

    for(int i = 0; i < n; i++)cout << dp[i] << " ";
    cout << endl;
    return 0;
}
