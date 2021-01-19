#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    /*
    //O(n)
    int maxSubArray(vector<int>& nums) {
        int mx=0,tmp=0,smx=INT_MIN
        for(int i=0;i<nums.size();i++){
            tmp+=nums[i];
            if(tmp<=0)tmp=0;
            if(mx<tmp)mx=tmp;
            if(smx<nums[i])smx=nums[i];
        }
        return smx<0?smx:mx;
    }
    */
    //O(nlogn)
    int calc(vector<int>& nums,int l,int r){
        if(l==r)return nums[l];
        if(l+1==r)return max(max(nums[l],nums[r]),nums[l]+nums[r]);
        int m=(l+r)>>1;
        int la=calc(nums,l,m),lta=nums[m],lv=0;
        int ra=calc(nums,m+1,r),rta=nums[m+1],rv=0;
        for(int i=m;i>=l;i--)
            lta=max(lta,lv+=nums[i]);
        for(int i=m+1;i<=r;i++)
            rta=max(rta,rv+=nums[i]);
        //printf("l=%d, r=%d, m=%d, lta=%d, rta=%d, la=%d, ra=%d\n",l,r,m,lta,rta,la,ra);
        return max(max(la,ra),lta+rta);
    }
    int maxSubArray(vector<int>& nums) {
        return calc(nums,0,nums.size()-1);
    }
};
//

int main(){
    return 0;
}

