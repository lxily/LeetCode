#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2)return true;
        int mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i>mx)return false;
            mx=max(mx,i+nums[i]);
            if(mx>=nums.size()-1)
                return true;
        }
        return true;
    }
};
int main(){
    return 0;
}
