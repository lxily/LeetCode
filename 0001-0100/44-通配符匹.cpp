#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s,p;
    vector<vector<int>>dp;
    bool solve(int a,int b,int x,int y){
        if(dp[a][x]!=-1)return dp[a][x];
        if(a>b&&x>y)return true;
        if(x>y)return false;
        int &d=dp[a][x]=0;
        if(a>b){
            if(p[x]=='*')d|=solve(a,b,x+1,y);
            else return d=0;
        }
        else if(s[a]==p[x]||p[x]=='?')
            d|=solve(a+1,b,x+1,y);
        else if(p[x]=='*'){
            d|=solve(a,b,x+1,y);
            d|=solve(a+1,b,x,y);
            d|=solve(a+1,b,x+1,y);
        }
        return d;
    }
    bool isMatch(string s, string p) {
        int ls=s.length(),lp=p.length();
        dp.resize(ls+2,vector<int>(lp+2,-1));
        this->s=s;this->p=p;
        return solve(0,ls-1,0,lp-1);
    }
};
int main(){
    return 0;
}
