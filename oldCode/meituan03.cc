#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[10001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    int ans = 0;

    for(int i = 0; i < n; i++){
        int w = 1;
        for(int j = i - 1; j >= 0; j--)if(a[j] >= a[i])w++;else break;
        for(int j = i + 1; j < n; j++)if(a[j] >= a[i])w++; else break;
        if(ans < w * a[i])ans = w * a[i];
    }
    cout << ans << endl;
    return 0;
}
