#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>&ret,vector<int>nums,int p){
        if(p==nums.size()){
            ret.push_back(nums);
            return;
        }
        unordered_map<int,bool>mp;
        for(int i=p;i<nums.size();i++){
            if(i==p||(nums[i]!=nums[i-1]&&!mp[nums[i]])){
                swap(nums[p],nums[i]);
                mp[nums[i]]=true;
                dfs(ret,nums,p+1);
                swap(nums[p],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
    vector<vector<int>>ret=S.permuteUnique(v);
    for(int i=0;i<ret.size();i++){
        printf("%2d: ",i);
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
