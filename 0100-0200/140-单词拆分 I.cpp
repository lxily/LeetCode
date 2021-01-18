#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    unordered_map<string,bool>mp;
    bool solve(string s,int l,string now,vector<string>&ret){
        if(l==s.size()){
            ret.push_back(now);
            return true;
        }
        if(dp[l]==0)return false;
        string p="";
        for(int i=l;i<s.size();i++){
            p.push_back(s[i]);
            if(mp.count(p)&&solve(s,i+1,now+(now.size()?" ":"")+p,ret)){
                dp[l]=true;
            }
        }
        return dp[l]==-1?dp[l]=false:dp[l];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
            mp[wordDict[i]]=true;
        dp.resize(s.size(),-1);
        vector<string>ret;
        solve(s,0,"",ret);
        return ret;
    }
};
int main(){
    return 0;
}
