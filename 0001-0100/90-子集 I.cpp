#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>>&ret,vector<int>nums,vector<int>now,int pos,int pre,bool get){
        if(pos==nums.size()){
            ret.push_back(now);
            return;
        }
        if(nums[pos]==pre){
            if(get){
                now.push_back(nums[pos]);
                solve(ret,nums,now,pos+1,pre,true);
                now.pop_back();
            }
            solve(ret,nums,now,pos+1,pre,false);
        }
        else{
            now.push_back(nums[pos]);
            solve(ret,nums,now,pos+1,nums[pos],true);
            now.pop_back();
            solve(ret,nums,now,pos+1,nums[pos],false);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        #define inf 0x3f3f3f3f
        vector<vector<int>>ret;
        solve(ret,nums,{},0,inf,false);
        return ret;
    }
};
int main(){
    return 0;
}
