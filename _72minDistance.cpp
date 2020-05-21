#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();

        if(l1*l2==0)
            return l1 + l2;

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

        for (int i = 0; i < l1 + 1; i++){
            dp[i][0] = i;
        }
        for (int i = 0; i < l2 + 1; i++){
            dp[0][i] = i;
        }

        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++){
                int insert1 = dp[i - 1][j] + 1;
                int insert2 = dp[i][j - 1] + 1;
                int tailadd = dp[i - 1][j - 1] + 1;
                if(word1[i-1]==word2[j-1])
                    tailadd -= 1;
                dp[i][j] = min(insert1, min(insert2, tailadd));
            }
        return dp[l1][l2];
    }
};