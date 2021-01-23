#include<bits/stdc++.h>
using namespace std;
/*
思路：保留每个数字最近出现的索引
*/
//start here
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                if(i-mp[nums[i]]<=k)return true;
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};
//

int main(){
    return 0;
}
