#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>>&ret,vector<int>now,vector<int>nums,int p){
        if(p==nums.size()){
            ret.push_back(now);
            return;
        }
        solve(ret,now,nums,p+1);
        now.push_back(nums[p]);
        solve(ret,now,nums,p+1);
        now.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ret;
        solve(ret,{},nums,0);
        return ret;
    }
};
int main(){
    return 0;
}
