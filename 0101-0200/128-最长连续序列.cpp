#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=true;
        int ret=0;
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]])continue;
            int l=nums[i],r=nums[i];
            while(mp.count(++r))mp[r]=false;
            while(mp.count(--l))mp[l]=false;
            if(ret<r-l-1)ret=r-l-1;
        }
        return ret;
    }
};
int main(){
    return 0;
}
