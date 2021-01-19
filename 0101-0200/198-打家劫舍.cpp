#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    //198
    int rob(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int f=0,dp[2][2];
        dp[0][0]=0;
        dp[0][1]=nums[0];
        int sz=nums.size();
        for(int i=1;i<sz;i++){
            dp[f^1][0]=max(dp[f][0],dp[f][1]);
            dp[f^1][1]=dp[f][0]+nums[i];
            f^=1;
        }
        return max(dp[f][0],dp[f][1]);
    }
};
//

int main(){
    return 0;
}

