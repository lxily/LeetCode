#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>&ret,vector<int>&nums,int p){
        if(p==nums.size()){
            ret.push_back(nums);
            return;
        }
        for(int i=p;i<nums.size();i++){
            if(i==p||nums[i]!=nums[i-1]){
                swap(nums[p],nums[i]);
                dfs(ret,nums,p+1);
                swap(nums[p],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ret;
        sort(nums.begin(),nums.end());
        if(nums.size())
            dfs(ret,nums,0);
        return ret;
    }
}S;
int main(){
    freopen("in.txt","r",stdin);
    int x;vector<int>v;
    while(cin>>x)v.push_back(x);
    vector<vector<int>>ret=S.permute(v);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
