#include<vector>
#include<algorithm>
using namespace std;
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> f(n);
//         for (int i = 0; i < n; i++){
//             f[i] = nums[i];
//             if(i)f[i] = max(f[i - 1] + nums[i], f[i]);
//         }
//         return *max_element(f.begin(), f.end());
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, last = INT_MIN;
        for (int i = 0; i < nums.size();i++){
            int now = max(last, 0);
            last=now+nums[i];
            res = max(res, last);
        }
        return res;
    }
};