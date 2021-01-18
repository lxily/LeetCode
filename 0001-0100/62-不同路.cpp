#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        dp[1][1]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(i==1&&j==1)continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[m][n];
    }
};
int main(){
    return 0;
}
