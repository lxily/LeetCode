#include<bits/stdc++.h>
using namespace std;
/*
思路：sort、map、分治、随机
题解：Boyer-Moore 投票算法
*/
//start here
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret=0,cnt=0;
        for(int i=0;i<nums.size();++i){
            if(!cnt)ret=nums[i];
            cnt+=(ret==nums[i])-(ret!=nums[i]);
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

