#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int idx=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[idx])
                nums[++idx]=nums[i];
        }
        return idx+1;
    }
};
int main(){
    return 0;
}
