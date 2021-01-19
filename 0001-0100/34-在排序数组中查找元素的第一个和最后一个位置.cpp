#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int sz=nums.size();
        if(!sz)return {-1,-1};
        int llo=0,rlo=sz-1;
        while(llo<rlo){
            int m=(llo+rlo)>>1;
            if(nums[m]>=target)rlo=m;
            else llo=m+1;
        }
        if(nums[llo]!=target)return {-1,-1};
        int lhi=0,rhi=sz-1;
        while(lhi<rhi){
            int m=lhi+((rhi-lhi+1)>>1);
            if(nums[m]>target)rhi=m-1;
            else lhi=m;
        }
        return {llo,lhi};
    }
};
int main(){
    return 0;
}
