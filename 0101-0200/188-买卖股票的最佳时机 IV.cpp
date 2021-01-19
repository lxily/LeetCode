#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    /*
    //123
    #define inf 0x3f3f3f3f
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        if(!sz)return 0;
        int ret=0;
        vector<int>lmax(prices.size()+1,0);
        vector<int>rmax(prices.size()+1,0);
        for(int i=1,_min=prices[0];i<sz;i++){
            lmax[i]=max(lmax[i-1],prices[i]-_min);
            if(_min>prices[i])_min=prices[i];
        }
        for(int i=sz-1,_max=prices[sz-1];i>=0;i--){
            rmax[i]=max(rmax[i+1],_max-prices[i]);
            if(_max<prices[i])_max=prices[i];
            ret=max(ret,lmax[i]+rmax[i+1]);
        }
        return max(ret,rmax[0]);
    }
    */
    //188
    #define inf 0x3f3f3f3f
    int maxProfitWithKEqualInf(vector<int>& prices) {
        prices.insert(prices.begin(),inf);
        int sz=prices.size();
        if(!sz)return 0;
        int ret=0;
        vector<vector<int>>dp(sz, vector<int>(2,0));
        dp[0][1]=dp[0][0]=-inf;
        for(int i=1;i<sz;i++)
            dp[i][0]=0,dp[i][1]=max(dp[i-1][1],-prices[i]);
        for(int i=1;i<sz;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[sz-1][0];
    }
    int maxProfit(int k, vector<int>& prices) {

        prices.insert(prices.begin(),inf);
        int sz=prices.size();
        if(!sz)return 0;
        if(k>=floor(sz/2.0))
            return maxProfitWithKEqualInf(prices);
        vector<vector<vector<int>>>dp(sz, vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int i=0;i<=k;i++)
            dp[0][i][1]=dp[0][i][0]=-inf;
        for(int i=1;i<sz;i++)
            dp[i][0][0]=0,dp[i][0][1]=max(dp[i-1][0][1],-prices[i]);

        int ret=0,f=0;
        for(int i=1;i<sz;i++){
            for(int kth=1;kth<=k;kth++){
                dp[i][kth][0]=max(dp[i-1][kth][0],dp[i-1][kth-1][1]+prices[i]);
                dp[i][kth][1]=max(dp[i-1][kth][1],dp[i-1][kth][0]-prices[i]);
            }
        }

        for(int i=1;i<=k;i++)
            ret=max(ret,dp[sz-1][i][0]);
        return ret;
    }
};
//

int main(){
    return 0;
}

