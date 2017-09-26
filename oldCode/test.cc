#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
using namespace std;

int mycmp(set<int> a, set<int> b){
    set<int>::iterator ia = a.begin(), ib = b.begin();
    while(ia != a.end() && ib != b.end()){
        if((*ia) == (*ib)){
            ia++;
            ib++;
        }
        else return 1;
    }
    if(ia != a.end())return 1;
    if(ib != b.end())return 1;
    return 0;
}

int main(){
    int n;
    while(cin >> n){
        map<int, set<int> >myHash;
        myHash.clear();
        int x, y, num;
        int LMIN = INT_MAX, LMAX = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> num >> x >> y;
            if(x < LMIN) LMIN = x;
            if(y > LMAX) LMAX = y;
            for(int j = x; j <=y; j++){
                set<int>myset = myHash[j];
                myset.insert(num);
                myHash[j] = myset;
            }
        }
        set<int> last = myHash[LMIN];
        int Be = LMIN;
        set<int> cur;
        for(int i = LMIN + 1; i <= LMAX; i++){
            cur = myHash[i];
            if(mycmp(last, cur)){
                cout << "range [" << Be << " ~ " << i - 1 << "]:{";
                for(set<int>::iterator ind = last.begin(); ind != last.end(); ind++)cout << *ind << " ";
                cout << "}" << endl;
                last = cur;
                Be = i;
            }
        }
        cout << "range[" << Be << " ~ " << LMAX << "]:{";
        for(set<int>::iterator ind = last.begin(); ind != last.end(); ind++)cout << *ind << " ";
        cout << "}" << endl;

    }
    return 0;
}
