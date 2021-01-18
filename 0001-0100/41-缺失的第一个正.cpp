#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        for(int i=0;i<nums.size()-1;i++){
            int idx=i,val=nums[i];
            while(val>=0&&val<nums.size()&&val!=idx){
                int nxv=nums[val];
                nums[val]=val;
                idx=val;val=nxv;
            }
        }
        int ret=1;
        for(;ret<nums.size();ret++)
            if(nums[ret]!=ret)break;
        return ret;
    }
};
int main(){
    return 0;
}
