#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define inf 0x3f3f3f3f
    int threeSumClosest(vector<int>& nums, int target) {
        int ret=-1,delta=inf;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(delta>abs(nums[l]+nums[r]+nums[i]-target))
                    ret=nums[l]+nums[r]+nums[i];
                    delta=abs(nums[l]+nums[r]+nums[i]-target);
                if(nums[l]+nums[r]+nums[i]>target){
                    r--;while(l<r&&nums[r]==nums[r+1])r--;

                }
                else if(nums[l]+nums[r]+nums[i]<target){
                    l++;while(l<r&&nums[l]==nums[l-1])l++;
                }
                else return target;
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
