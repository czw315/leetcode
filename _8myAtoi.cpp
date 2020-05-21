#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
            return 0;
        long long res = 0, sign = 1;
        int i = 0;
        while (i < str.size() && isspace(str[i]))
            i++;
        if(i==str.size())
            return 0;
        if (isalpha(str[i]))
            return 0;
        else if (str[i] == '-')
            sign = -1;
        else if (str[i] == '+')
            sign = 1;
        else if(isdigit(str[i]))
            res = str[i]-'0';
        else 
            return 0;
        while(++i<str.size()&&isdigit(str[i])){
            res = res * 10 + str[i]-'0';
            if(res>INT_MAX+1ll)
                break;
        }
        res *= sign;
        if(res>INT_MAX)
            return INT_MAX;
        if(res<INT_MIN)
            return INT_MIN;
        return res;
        }
};