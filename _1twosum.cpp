#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
//哈希表的运用
/**
 * 
 */

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> m;                      //empty hashmap,m.at()返回映射值的引用
//         for (int i = 0; i < nums.size(); i++)           //没有的话会抛出std::out_of_range类型异常
//         {
//             if(m.find(target-nums[i])!=m.end())         //find()可以用来判断有没有该关键字
//                 return {m[target - nums[i]], i};        //count()可以用来统计出现的次数，但是
//             else                                        //不可能重复，所以只会有1或者0
//                 m[nums[i]]=i;                           //在map或者unordered_map中下标可以直接插入
//         }                                               //假如没有该pair时
//         return {-1, -1};
//     }
// };



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size();i++){
            if(map.find(target-nums[i])!=map.end())
                return {map[target - nums[i]], i};
            else
                map[nums[i]] = i;
        }
        return {-1, -1};
    }
};