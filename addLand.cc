#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int pa[10000000];//size >= m * n;
bool flag[10000000];

int findpa(int id){
   return pa[id] == id? id: pa[id] = findpa(pa[id]);
}

int main(){

    int n,m,k,a,b, ans;
    vector<pair<int,int> > dir;
    dir.push_back(pair<int, int>(-1, 0));
    dir.push_back(pair<int, int>(1, 0));
    dir.push_back(pair<int, int>(0, -1));
    dir.push_back(pair<int, int>(0, 1));

    while(cin >>n >>m >>k){
        for(int i = 0;i <= n * m; ++i) pa[i] = i, flag[i] = false;
        vector<int> ansList;
        ans =0;
        while(k--){
             cin >>a >>b;

             int index = a * m + b + 1;
             if(a < 0 || b < 0 || a >= n || b >= m) continue;
             flag[index] = 1;
             ++ans;
             for(int i = 0;i < dir.size(); ++i){
                 int x,y,pa1,pa2,id2;
                 x = a + dir[i].first;
                 y = b + dir[i].second;
                 id2 = x * m + y + 1;
                 if(x < 0 || y < 0 || x >=n || y >= m || !flag[id2]) continue;

                 pa1 = findpa(index);
                 pa2 = findpa(id2);
                 if(pa1 != pa2){
                     --ans;
                     pa[pa1] = pa2;
                 }
             }
            ansList.push_back(ans);
        }
        cout << ansList[0];
        for(int i = 1; i < ansList.size(); i++)cout << " " << ansList[i];
        cout << endl;
    }
    return 0;
}
