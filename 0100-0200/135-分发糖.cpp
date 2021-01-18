#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>dp;
    int solve(int idx,vector<int>&ratings){
        if(dp[idx])return dp[idx];dp[idx]=1;
        if(idx>0&&ratings[idx]>ratings[idx-1]){
            dp[idx]=max(dp[idx],solve(idx-1,ratings)+1);
        }
        if(idx<ratings.size()-1&&ratings[idx]>ratings[idx+1]){
            dp[idx]=max(dp[idx],solve(idx+1,ratings)+1);
        }
        return dp[idx];
    }
    int candy(vector<int>& ratings) {
        if(!ratings.size())return 0;
        dp.resize(ratings.size());
        int ret=0;
        for(int i=0;i<ratings.size();i++)
            ret+=solve(i,ratings);
        return ret;
    }
};
int main(){
    return 0;
}
