#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    //123
    #define inf 0x3f3f3f3f
    int maxProfit(vector<int>& prices) {
        int sz=prices.size();
        if(!sz)return 0;
        int ret=0,rmax=0;
        vector<int>lmax(prices.size()+1,0);
        //vector<int>rmax(prices.size()+1,0);
        for(int i=1,_min=prices[0];i<sz;i++){
            lmax[i]=max(lmax[i-1],prices[i]-_min);
            if(_min>prices[i])_min=prices[i];
        }
        for(int i=sz-1,_max=prices[sz-1];i>=0;i--){
            ret=max(ret,lmax[i]+rmax);
            rmax=max(rmax,_max-prices[i]);
            if(_max<prices[i])_max=prices[i];
        }
        return max(ret,rmax);
    }
};
//

int main(){
    return 0;
}

