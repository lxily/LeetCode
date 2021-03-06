#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int>mp;
    void dfs(vector<vector<int>>&ret,vector<int>& candidates,int target,int sum,int pos,vector<int>now){
        if(sum==target&&now.size()){
            ret.push_back(now);
            return;
        }
        if(pos==candidates.size())return;
        int i=0;
        for(;i<=mp[candidates[pos]]&&sum+i*candidates[pos]<=target;i++){
            if(i)now.push_back(candidates[pos]);
            dfs(ret,candidates,target,sum+i*candidates[pos],pos+1,now);
        }
        for(;i>1;i--)now.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ret;
        for(int i=0;i<candidates.size();i++)
            mp[candidates[i]]++;
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        reverse(candidates.begin(),candidates.end());
        dfs(ret,candidates,target,0,0,{});
        return ret;
    }
};
int main(){
    return 0;
}
