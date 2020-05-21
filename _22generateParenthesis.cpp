#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, int l, int r, string s,int n){
        if(s.length()==n){
            res.push_back(s);
            return;
        }
        if(r<l)
            return;
        if(l)
            dfs(res, l - 1, r, s + "(", n);
        if(r)
            dfs(res, l, r - 1, s + ")", n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, n, n, "", n);
        return res;
    }
};