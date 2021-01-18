#include<bits/stdc++.h>
using namespace std;
//思路：二分，不断缩小峰值区间
//start here
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l+1<r){
            int m=(l+r)>>1;
            if(nums[m]>nums[max(0,m-1)]){
                l=m;
            }
            else{
                r=m;
            }
        }
        return l==r?l:nums[l]>nums[r]?l:r;
    }
};
//

int main(){
    return 0;
}

