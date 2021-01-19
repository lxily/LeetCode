#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s,p;
    vector<vector<vector<vector<int>>>>dp;
    bool solve(int l,int r,int L,int R){
        if(l>r)return true;
        if(l==r&&s[l]==p[L])return true;
        int &d=dp[l][r][L][R];
        if(d!=-1)return d;
        else     d=0;
        for(int i=l;i<r;i++){
            int d1=solve(l,i,L,L+i-l);
            int d2=solve(i+1,r,L+i-l+1,R);
            int d3=solve(l,i,R-(i-l),R);
            int d4=solve(i+1,r,L,R-(i-l)-1);
            if(d|=(d1&&d2)||(d3&&d4))return d;
        }
        return d;
    }
    bool isScramble(string s1, string s2) {
        int sz1=s1.size();
        int sz2=s2.size();
        if(sz1!=sz2)return false;
        if(!sz1)return true;
        this->s=s1;this->p=s2;
        dp.resize(sz1,vector<vector<vector<int>>>(sz1,vector<vector<int>>(sz1,vector<int>(sz1,-1))));
        return solve(0,sz1-1,0,sz2-1);
    }
};
int main(){
    return 0;
}
