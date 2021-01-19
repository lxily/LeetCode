#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define FOR(i,a,b) for(int i=a;i<b;i++)
    const static int maxn=55;
    int resOfMap[maxn];
    bool vis[3][maxn<<1];
    vector<string> getMap(int n){
        string R="";
        vector<string>ret;
        FOR(i,0,n)R.push_back('.');
        FOR(i,0,n)ret.emplace_back(R);
        FOR(i,0,n)ret[i][resOfMap[i]]='Q';
        return ret;
    }
    void search(vector<vector<string>> &ret,int N,int dep){
        if(dep==N){
            ret.push_back(getMap(N));
            return;
        }
        FOR(i,0,N){
            if(!vis[0][i]&&!vis[1][dep+i]&&!vis[2][dep-i+N]){
                vis[0][i]=vis[1][dep+i]=vis[2][dep-i+N]=true;
                resOfMap[dep]=i;search(ret,N,dep+1);
                vis[0][i]=vis[1][dep+i]=vis[2][dep-i+N]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ret;
        search(ret,n,0);
        return ret;
    }
}S;
int main(){
    vector<vector<string>>ret=S.solveNQueens(8);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<endl;
        }cout<<endl;
    }
    return 0;
}
