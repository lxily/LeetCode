#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        #define inf 0x3f3f3f3f
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,inf));
        dp[1][1]=grid[0][0];
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(i==1&&j==1)continue;
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        return dp[m][n];
    }
};
int main(){
    return 0;
}
