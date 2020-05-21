#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string res;
        for (int i = 0; i < s.size(); i++){
            if(s[i]==' ')
                continue;
            else{
                int h = i, l = 1;
                while(i+1<s.size()&&s[++i]!=' ')
                    l++;
                words.push_back(s.substr(h, l));
            }
        }
        if(words.empty())
            return res;
        for (int i = words.size() - 1; i > 0; i--){
            res += words[i];
            res += " ";
        }
        res += words[0];
        return res;
    }
};