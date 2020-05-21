#include<vector>
#include<algorithm>
using namespace std;

//(l>>1)+1  不可以 l>>1+1;
//哇。。。。。
class Solution {
public:
    int findKnum(vector<int>& n1, int i, vector<int>& n2, int j, int k){
        if(n1.size()-i>n2.size()-j)
            findKnum(n2, j, n1, i, k);
        if(n1.size()-i==0)
            return n2[j + k - 1];
        if(k==1)
            return min(n1[i], n2[j]);
        int l1 = min((int)n1.size(), i + k / 2), l2 = j + k / 2;
        if(n1[l1-1]<n2[l2-1])
            return findKnum(n1, l1, n2, j, k - (l1 - i));
        else
            return findKnum(n1, i, n2, l2, k - k / 2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        if((s1+s2)%2==0){
            int k1 = findKnum(nums1, 0, nums2, 0, s1 + s2 >> 1);
            int k2 = findKnum(nums1, 0, nums2, 0, (s1 + s2 >> 1) + 1);
            return k1 + k2 / 2.0;
        }else
            return findKnum(nums1, 0, nums2, 0, (s1 + s2 >> 1) + 1);
    }
};