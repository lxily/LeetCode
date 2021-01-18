#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int other=target-nums[i];
            if(mp.count(other)){
                return {mp[other],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
int main(){
    return 0;
}
