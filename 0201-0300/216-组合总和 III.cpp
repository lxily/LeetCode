#include<bits/stdc++.h>
using namespace std;
/*
思路：深搜+回溯
*/
//start here
class Solution {
public:
    vector<bool>vis;
    void dfs(int n,int k,int bit,vector<int>& now,vector<vector<int>>& ans){
        if(!n&&!k&&now.size()){
            ans.push_back(now);
            return;
        }
        if(k==0)return;
        for(int i=bit+1;i<=9;i++){
            if(vis[i]||n<i)continue;
            vis[i]=true;
            now.push_back(i);
            dfs(n-i,k-1,i,now,ans);
            now.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        if(n>55||k>9)return ans;
        vis=vector<bool>(10,false);
        vector<int>now;
        dfs(n,k,0,now,ans);
        return ans;
    }
};
//

int main(){
    return 0;
}
