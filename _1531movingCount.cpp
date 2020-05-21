#include<vector>
using namespace std;

class Solution {
public:
    int get_sum(int x){
        int a = x / 100;
        x %= 100;
        int b = x / 10;
        x %= 10;
        return a + b + x;
    }

    void dfs(vector<vector<bool>>& vec, int i, int j, int m, int n, int k){
        if(i<0||j<0||i>=m||j>=n||get_sum(i) + get_sum(j)>k||vec[i][j])
            return;
        vec[i][j] = true;
        dfs(vec, i - 1, j, m, n, k);
        dfs(vec, i + 1, j, m, n, k);
        dfs(vec, i, j - 1, m, n, k);
        dfs(vec, i, j + 1, m, n, k);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> vec(m, vector<bool>(n, false));
        int res = 0;
        dfs(vec, 0, 0, m, n, k);
        for(auto x : vec)
            for(auto y : x)
                if(y)
                    res++;
        return res;
    }
};

int main(){
    Solution s;
    s.movingCount(2, 3, 1);
    return 0;
}