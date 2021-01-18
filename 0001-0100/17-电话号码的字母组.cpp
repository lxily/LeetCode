#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<char>ch[10];
    Solution(){
        for(int i=2;i<=6;i++)
            ch[i]={'a'+(i-2)*3,'b'+(i-2)*3,'c'+(i-2)*3};
        ch[7]={'p','q','r','s'};
        ch[8]={'t','u','v'};
        ch[9]={'w','x','y','z'};
    }
    void dfs(vector<string>&ret,string now,string digits,int p){
        if(p==digits.size()){
            ret.push_back(now);return;
        }
        int num=digits[p]-'0';
        for(int j=0;j<ch[num].size();j++){
            dfs(ret,now+ch[num][j],digits,p+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return {};
        vector<string>ret;
        dfs(ret,"",digits,0);
        return ret;
    }
};
int main(){
    return 0;
}
