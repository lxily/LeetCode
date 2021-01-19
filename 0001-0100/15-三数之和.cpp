#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                bool lm=false,rm=false;
                if(nums[l]+nums[r]>-nums[i]){
                    rm=true;
                }
                else if(nums[l]+nums[r]<-nums[i]){
                    lm=true;
                }
                else{
                    lm=rm=true;
                    ret.push_back({nums[i],nums[l],nums[r]});
                }
                if(lm){l++;while(l<r&&nums[l]==nums[l-1])l++;}
                if(rm){r--;while(l<r&&nums[r]==nums[r+1])r--;}
            }
        }
        return ret;
    }
}S;
int main(){
    return 0;
}
