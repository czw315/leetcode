#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string str;
        int l = s.size();
        int h = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++){
            if(i==0||i==numRows-1){
                int start = i;
                while(start<l)
                    str += s[start], start += h;
            }else{
                int s1 = i, s2 = 2 * numRows - i - 2;
                while(s1<l||s2<l){
                    if(s1<l)
                        str += s[s1], s1 += h;
                    if(s2<l)
                        str += s[s2], s2 += h;
                }
            }
        }
        return str;
    }
};