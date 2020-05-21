#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size();){
            int h = height[i], l = i, sum = 0, r = 0;
            int tmp = INT_MIN;
            while(++i<height.size()&&height[i]<h)
                ;
            if(i<height.size())
                r = i;
            else if(l==height.size()-1)
                break;
            else for (int j = l + 1; j < height.size(); j++)
            {
                if(height[j]>tmp)
                    tmp = height[j], r = j, h=tmp;
            }
            for (int j = l + 1; j < r;j++){
                sum += height[j];
            }
                res += (r - l - 1) * h - sum;
            i = r;
        }
        return res;
    }
};