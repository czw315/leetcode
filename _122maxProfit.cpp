#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int res = 0;
        for (int i = 0; i < prices.size()-1;i++)
            res += max(prices[i + 1] - prices[i], 0);
        return res;
    }
};