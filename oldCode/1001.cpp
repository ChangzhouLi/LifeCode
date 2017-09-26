//
//  1001.cpp
//  
//
//  Created by 李昌洲 on 2017/6/19.
//
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int assignConferenceRoom(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int La = A.size(), Lb = B.size();
    int i = 0, j = 0, ans = 0;
    while(i < La && j < Lb){
        if(A[i] <= B[j])i++, j++, ans++;
        else j++;
    }
    return ans;
}

int main(){
    vector<int> A, B;
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    B.push_back(10);
    B.push_back(3);
    B.push_back(2);
    cout << assignConferenceRoom(A, B) << endl;
    return 0;
}
