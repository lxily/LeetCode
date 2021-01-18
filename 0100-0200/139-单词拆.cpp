#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    unordered_map<string,bool>mp;
    bool solve(string &s,int l){
        if(l==s.size())return true;
        if(dp[l]!=-1)return dp[l];
        string p="";
        for(int i=l;i<s.size();i++){
            p.push_back(s[i]);
            if(mp.count(p)&&solve(s,i+1)){
                return dp[l]=true;
            }
        }
        return dp[l]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
            mp[wordDict[i]]=true;
        dp.resize(s.size(),-1);
        return solve(s,0);
    }
};
int main(){
    return 0;
}
