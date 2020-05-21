#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0;
        unordered_map<char,int> um;
        for (int i = 0; i < s.size(); ++i)
        {
            if(um.count(s[i])&&um[s[i]]>=left)
                left = um[s[i]]+1;
            res = max(res, i - left + 1);
            um[s[i]] = i;
        }
        return res;
    }
};