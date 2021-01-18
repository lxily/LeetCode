#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)return false;
        int sz=nums.size();
        int l=0,r=sz-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(nums[m]==target)return true;
            if(nums[m]==nums[r]){r--;continue;}
            if(nums[m]>target){
                if(nums[m]>nums[r]){        //m在旋转后的左半边
                    if(target>nums[r])r=m-1;
                    else l=m;
                }
                else{
                    if(target>nums[r])l=m;
                    else r=m-1;
                }
            }
            else if(nums[m]<target){
                if(nums[m]>nums[r]){        //m在旋转后的左半边
                    l=m;
                }
                else{
                    if(target>nums[r])r=m-1;
                    else l=m;
                }
            }
        }
        return nums[l]==target?true:false;
    }
};
int main(){
    return 0;
}
