//
//  1007.cpp
//  
//
//  Created by 李昌洲 on 2017/6/20.
//
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;


struct Edge{
    int from, to;
    int deep;
    Edge* p;
};

queue<Edge*>q;

int countPaths(vector<vector<int> > G) {
    int n = G.size();
    if(0 == n)return 0;
    while(!q.empty())q.pop();
    Edge root;
    root.p = NULL;
    for(int i = 0; i < n; i++){
        if(G[0][i]){
            Edge e, *x;
            e.p = &root;
            e.from = 0;
            e.to = i;
            e.deep = 1;
            x = 
            q.push(e);
            
        }
    }
    
    
    int ans = 0;
    vector<bool> row;
    vector<vector<bool> > flag;
    for(int i = 0; i < n; i++)row.push_back(0);
    for(int i = 0; i < n; i++)flag.push_back(row);
    int NN = n * n;
    while(!q.empty()){
        Edge e = q.front();
        cout << e.p << endl;
        q.pop();
        cout << e.from << " " << e.to << " " << e.deep << endl;
        if(n - 1 == e.to){
            Edge *ee = &e;
            bool isNew = 0;
            while(ee->p){
//                cout << ee->from << " " << ee->to << " " << ee->deep << endl;
                if(!flag[ee->from][ee->to]){
                    flag[ee->from][ee->to] = 1;
                    isNew = 1;
                }
                ee = ee->p;
            }
            if(isNew)ans++;
        }
        for(int i = 0; i < n; i++){
            if(G[e.to][i]){
                Edge *next = new Edge();
                cout << next << endl;
                next->from = e.to, next->to = i, next->deep = e.deep + 1, next->p = &e;
                if(next->deep <= NN)q.push(*next);
            }
        }
        
    }
    cout << "asd" << endl;
    return ans;
}


int main(){
    vector<int> x;
    vector<vector<int> >G;
    x.push_back(0);
    x.push_back(1);
    G.push_back(x);
    x[0] = 1, x[1] = 0;
    G.push_back(x);
    cout << countPaths(G) << endl;
    return 0;
}
