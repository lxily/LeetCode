#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sz1=s1.length();
        int sz2=s2.length();
        if(sz1+sz2!=s3.size())
            return false;
        if(!sz1)return s2==s3;
        if(!sz2)return s1==s3;
        s1="#"+s1;s2="#"+s2;
        vector<vector<bool>>dp(sz1+1,vector<bool>(sz2+1,false));
        dp[0][0]=true;
        for(int i=0;i<=sz1;i++){
            for(int j=0;j<=sz2;j++){
                if(!i&&!j)continue;
                if(i&&j){
                    if(s1[i]==s3[i+j-1])dp[i][j]=dp[i][j]|dp[i-1][j];
                    if(s2[i]==s3[i+j-1])dp[i][j]=dp[i][j]|dp[i][j-1];
                }
                if(!i&&s2[j]==s3[j-1])  dp[i][j]=dp[i][j]|dp[i][j-1];
                if(!j&&s1[i]==s3[i-1])  dp[i][j]=dp[i][j]|dp[i-1][j];
            }
        }
        return dp[sz1][sz2];
    }
};
int main(){
    return 0;
}
