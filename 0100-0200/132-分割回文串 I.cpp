#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define inf 0x3f3f3f3f
    vector<int>p,dp;
    void manacher(string &s){
        p.resize(s.size());
        int idx=0,mx=1;p[0]=1;
        for(int i=1;i<s.size();i++){
            p[i]=mx>i?min(mx-i,p[2*idx-i]):1;
            for(;s[i-p[i]]==s[i+p[i]];p[i]++);
            if(i+p[i]>mx){mx=i+p[i];idx=i;}
        }
    }
    inline bool check(int l,int r){
        ++l;++r;l<<=1;r<<=1;
        return p[(l+r)>>1]*2-1>=r-l+1;
    }
    int solve(string &s,int idx){
        if(idx==s.size())return 0;
        if(dp[idx]!=inf)return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(check(idx,i)){
                dp[idx]=min(dp[idx],1+solve(s,i+1));
            }
        }
        return dp[idx];
    }
    int minCut(string s) {
        string s1="$#";
        int len=s.length();
        for(int i=0;i<len;i++){
            s1.push_back(s[i]);
            s1.push_back('#');
        }
        manacher(s1);
        dp.resize(s.size(),inf);
        return solve(s,0);
    }
};
int main(){
    return 0;
}
