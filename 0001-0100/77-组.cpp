#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>>&ret,vector<int>now,int n,int k,int p){
        if(now.size()==k){
            ret.push_back(now);
            return;
        }
        if(k-now.size()>n-p+1)
            return;
        for(int i=p;i<=n;i++){
            now.push_back(i);
            solve(ret,now,n,k,i+1);
            now.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ret;
        if(n&&k)solve(ret,{},n,k,1);
        return ret;
    }
};
int main(){
    return 0;
}
