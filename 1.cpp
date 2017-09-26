class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[0].size();
        if(m == 0 || n == 0)return false;
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            int x = array[i][j];
            if(x < target)i++;
            else if(x > target)j--;
            else return true;
        }
        return false;
    }
};
