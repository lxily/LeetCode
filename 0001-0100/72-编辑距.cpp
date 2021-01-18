#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define inf 0x3f3f3f3f
    string s,p;vector<vector<int>>dp;
    int solve(int a,int b,int x,int y){
        if(a>b&&x>y)return 0;
        if(a>b)return y-x+1;
        if(x>y)return b-a+1;
        int &d=dp[a][x];
        if(d!=inf)return d;
        if(s[a]==p[x]){
            d=min(d,solve(a+1,b,x+1,y));//s[a]Æ¥Åäp[x]£¬ºóÐøs[a+1~b]Æ¥Åäp[x+1,y]
        }
        else{
            d=min(d,solve(a+1,b,x+1,y)+1);//Ìæ»»s[a]Æ¥Åäp[x]£¬ºóÐøs[a+1~b]Æ¥Åäp[x+1,y]
        }
        d=min(d,solve(a+1,b,x,y)+1);//½«s[a]É¾³ý£¬ÓÃs[a+1~b]Æ¥Åäp[x~y]
        d=min(d,solve(a,b,x+1,y)+1);//²åÈëÒ»¸ö×Ö·ûÈ¥Æ¥Åäp[x]£¬ºóÐøs[a~b]Æ¥Åäp[x+1~y]
        return d;
    }
    int minDistance(string word1, string word2) {
        int sz1=word1.size();
        int sz2=word2.size();
        if(!sz1&&!sz2)return 0;
        this->s=word1;this->p=word2;
        dp.resize(sz1+1,vector<int>(sz2+1,inf));
        return solve(0,sz1-1,0,sz2-1);
    }
};
int main(){
    return 0;
}
