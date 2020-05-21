#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(auto &vec : matrix)
            for (int i = 0; i < n / 2; i++)
                swap(vec[i], vec[n - i - 1]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n-i; j++)
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
    }
};