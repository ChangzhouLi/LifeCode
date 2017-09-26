//
//  trie.cpp
//  
//
//  Created by 李昌洲 on 2017/6/16.
//
//

#include <stdio.h>
#include <cstring>
#include <string>


#define MAX 256

struct Trie{
    int v;
    Trie* next[MAX];
}

Trie *root;


//生成字典树
void createTrie(char *s){
    int len = strlen(s);
    Trie *p = root, *q;
    for(int i = 0; i < len; i++){
        int id = s[i];
        if(p->next[id] == NULL){
            q = new Trie();
            q->v = 1;
            for(int j = 0; j < MAX; j++){
                q->next[j] = NULL;
            }
            p->next[id] = q;
            p = p->next[id];
        }
        else{
            p = p->next[id];
        }
    }
    p->v = -1;//字符集单词以-1结尾
}


//查找
int findTrie(char *s){
    int len = strlen(s);
    Trie *p = root;
    int ans = 0;
    for(int i = 0; i < len; i++){
        int id = s[i];
        p = p->next[id];
        if(p == NULL){
            continue;
        }
        if(p->v == -1){
            ans++;
            i--;
        }
        p = root;
    }
    if(p->v == -1)ans++;
    return ans;
}

int main(){
    vector<string> keywords;
    string input = "";
    
    
}



