#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz=nums.size();
        if(!sz)return 0;
        int l=0,r=sz-1;
        while(l<r){
            int m=l+((r-l+1)>>1);
            if(nums[m]>target)r=m-1;
            else l=m;
        }
        return nums[l]<target?l+1:l;
    }
};
int main(){
    return 0;
}
