#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)return -1;
        int sz=nums.size();
        int l=0,r=sz-1;
        while(l<r){
            int m=l+(r-l+1)/2;
            if(nums[m]>target){
                if(nums[m]>nums[sz-1]){//×ó±ß
                    if(target>nums[sz-1])r=m-1;
                    else l=m;
                }
                else{
                    if(target>nums[sz-1])l=m;
                    else r=m-1;
                }
            }
            else if(nums[m]<target){
                if(nums[m]>nums[sz-1]){//×ó±ß
                    l=m;
                }
                else{
                    if(target>nums[sz-1])r=m-1;
                    else l=m;
                }
            }
            else return m;
        }
        return nums[l]==target?l:-1;
    }
};
int main(){
    return 0;
}
