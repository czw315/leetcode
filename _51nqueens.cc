class Solution {
public:
    vector<int> cols, lobs, robs;
    void dfs(vector<vector<string>>& res, vector<string>& vec, int row, int n){
        if(row==n){
            res.push_back(vec);
            return;
        }
        bool insert_ok=false;
        for(int i=0;i<n;i++){
            if(cols[i]==0&&lobs[row+i]==0&&robs[row-i+n-1]==0){
                insert_ok=true;
                vec[row][i]='Q';
                cols[i]=lobs[row+i]=robs[row-i+n-1]=1;
                dfs(res, vec, row+1, n);
                vec[row][i]='.';
                cols[i]=lobs[row+i]=robs[row-i+n-1]=0;
            }
        }
        if(!insert_ok){
            for(int i=0;i<n;i++)
                if(vec[row-1][i]=='Q'){
                    vec[row-1][i]='.';
                    cols[i]=lobs[row-1+i]=robs[row-1-i+n-1]=0;
                    break;
                }
            return;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string str(n, '.');
        vector<string> vec(n, str);
        cols.resize(n);
        lobs.resize(2*n-1);
        robs.resize(2*n-1);
        dfs(res, vec, 0, n);
        return res;
    }
};
