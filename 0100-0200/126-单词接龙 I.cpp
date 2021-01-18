#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define mkp(a,b) make_pair(a,b)
    vector<int>dist;vector<vector<int>>g;
    void solve(int u,int ed,vector<string>&now,vector<string>&wordList,vector<vector<string>>&ret){
        now.push_back(wordList[u]);
        if(u==ed){
            ret.push_back(now);
            now.pop_back();
            return;
        }
        for(int i=0;i<g[u].size();i++){
            solve(g[u][i],ed,now,wordList,ret);
        }
        now.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        vector<bool>vis(wordList.size()+1,0);
        wordList.insert(wordList.begin(),beginWord);
        for(int i=0;i<wordList.size();i++)
            mp[wordList[i]]=i;
        if(!mp.count(endWord))return {};
        g.resize(wordList.size());
        dist.resize(wordList.size());
        queue<pair<int,int>>Q;
        Q.push(mkp(0,1));
        vis[0]=true;
        dist[0]=1;
        while(!Q.empty()){
            int idx=Q.front().first;
            int stp=Q.front().second;
            Q.pop();
            int len=wordList[idx].length();
            for(int i=0;i<len;i++){
                string tmp=wordList[idx];
                for(char c='a';c<='z';c++){
                    if(wordList[idx][i]!=c&&mp.count((tmp[i]=c,tmp))){
                        int nxid=mp[tmp];
                        if(!vis[nxid]){
                            vis[nxid]=true;
                            dist[nxid]=stp+1;
                            g[idx].push_back(nxid);
                            if(tmp!=endWord)
                                Q.push(mkp(nxid,stp+1));
                        }
                        else if(dist[nxid]==stp+1)
                            g[idx].push_back(nxid);
                    }
                }
            }
        }
        vector<string>now;
        vector<vector<string>>ret;
        solve(0,mp[endWord],now,wordList,ret);
        return ret;
    }
};
int main(){
    return 0;
}
