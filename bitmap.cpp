//
//  bitmap.cpp
//  
//
//  Created by 李昌洲 on 2017/6/16.
//
//

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define SHIFT 5
#define MASK 0x1f


void set(int n, int* arr){
    int ind_loc, bit_loc;
    ind_loc = n >> SHIFT;
    bit_loc = n & MASK;
    arr[ind_loc] |= 1 << bit_loc;
}

void clr(int n, int* arr){
    int ind_loc;
    ind_loc = n >> SHIFT;
    arr[ind_loc] &= 0;
}

int testNum(int n, int* arr){
    int ind_loc = n >> SHIFT;
    int flag = arr[ind_loc] & (1<<(n & MASK));
    return flag;
}
int main(){
    int num;
    int space = 100;
    int arr[space];
    for(int i = 0; i < space; i++){
        clr(i, arr);
    }
    int n = 5;
    while(n--){
        cin >> num;
        set(num, arr);
    }
    while(cin >> num){
        if(testNum(num, arr))cout << "111111" << endl;
        else cout << "failed" << endl;
    }
    return 0;
}
