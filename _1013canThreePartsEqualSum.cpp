#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = accumulate(A.begin(), A.end(), 0);
        if(s%3 != 0)
            return false;
        int r = s / 3, t1 = 0;
        for (int i = 0; i < A.size()-2;i++){
            t1 += A[i];
            if(t1!=r)
                continue;
            else {
                int t2 = 0;
                for (int j = i + 1; j < A.size()-1;j++){
                    t2 += A[j];
                    if(t2!=r)
                        continue;
                    else{
                        int t3 = 0;
                        for (int z = j + 1; z < A.size();z++){
                            t3 += A[z];
                            if(t3!=r)
                                continue;
                            else if (t3 == r &&z == A.size() - 1)
                                return true;
                        }
                    }
                }
            }   
        }
        return false;
    }
};