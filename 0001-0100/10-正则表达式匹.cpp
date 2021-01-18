#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[1001][1001];string s,p;
    int solve(int x,int y,int a,int b){
        if(dp[x][a]!=-1)return dp[x][a];
        int &d=dp[x][a]=0;
        if(x>y&&a>b)return d=1;
        if(x<=y&&a>b)return d=0;
        if(p[a]=='.'||(x<=y&&p[a]==s[x])){
            if(a+1<=b&&p[a+1]=='*'){
                d|=solve(x,y,a+2,b);
                if(x<=y){
                    d|=solve(x+1,y,a,b);
                    d|=solve(x+1,y,a+2,b);
                }
            }
            else if(x<=y){
                d|=solve(x+1,y,a+1,b);
            }
        }
        else if(a+1<=b&&p[a+1]=='*'){
            d|=solve(x,y,a+2,b);
        }
        return d;
    }
    bool isMatch(string s, string p) {
        if(s==p)return true;
        int ls=s.length();
        int lp=p.length();
        this->s=s;this->p=p;
        memset(dp,-1,sizeof dp);
        return solve(0,ls-1,0,lp-1);
    }
}S;
int main(){
    string s="a";
    string p=".*..a";
    cout<<S.isMatch(s,p)<<endl;
    return 0;
}
