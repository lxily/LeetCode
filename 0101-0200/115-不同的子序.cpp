#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()<t.size())return 0;
        if(!s.size())return !t.size();
        if(!t.size())return 1;
        int ss=s.size(),st=t.size();
        vector<vector<long long>>dp(ss+1,vector<long long>(st+1,0));
        for(int i=0;i<=ss;i++)dp[i][0]=1;
        for(int i=1;i<=ss;i++){
            for(int j=1;j<=st;j++){
                dp[i][j]=dp[i-1][j];
                if(s[i-1]==t[j-1]){
                    dp[i][j]+=dp[i-1][j-1];
                }
            }
        }
        return dp[ss][st];
    }
};
int main(){
    return 0;
}
