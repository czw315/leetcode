#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int h1 = 0, h2 = 0;
        for (int i = 0; i < prices.size();i++){
            int tmp = prices[i];
            while(i!=prices.size()-1&&prices[i+1]>=prices[i])
                i++;
            int th = prices[i] - tmp;
            if(th>h2)
                if(th>h1)
                    h2 = h1, h1 = th;
                else
                    h2 = th;
        }
        return h1 + h2;
    }
};