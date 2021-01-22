#include<bits/stdc++.h>
using namespace std;
/*
思路：动态规划
*/
//start here
class Solution {
public:
    /*
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
    */
    //213
    int calc(vector<int>& nums,bool cancleBegin,bool cancleEnd){
        int l=cancleBegin;
        int r=nums.size()-cancleEnd;
        int f=0,dp[2][2];
        dp[0][0]=0;
        dp[0][1]=nums[l];
        int sz=nums.size();
        for(int i=l+1;i<r;i++){
            dp[f^1][0]=max(dp[f][0],dp[f][1]);
            dp[f^1][1]=dp[f][0]+nums[i];
            f^=1;
        }
        return max(dp[f][0],dp[f][1]);
    }
    int rob(vector<int>& nums) {
        if(!nums.size())
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        return max(calc(nums,true,false),calc(nums,false,true));
    }

};
//

int main(){
    return 0;
}
