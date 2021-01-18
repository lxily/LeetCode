#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<string>&ret,string now,int sum,int l,int p,int n){
        if(p==n){
            ret.push_back(now);
            return;
        }
        if(sum-1>=0)
            dfs(ret,now+')',sum-1,l,p+1,n);
        if(l+1<=n>>1)
            dfs(ret,now+'(',sum+1,l+1,p+1,n);
    }
    vector<string> generateParenthesis(int n) {
        if(!n)return {};
        vector<string>ret;
        dfs(ret,"",0,0,0,n<<1);
        return ret;
    }
};
int main(){
    return 0;
}
