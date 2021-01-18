#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define mkp(a,b) make_pair(a,b)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        vector<bool>vis(wordList.size()+1,0);
        wordList.insert(wordList.begin(),beginWord);
        for(int i=0;i<wordList.size();i++)
            mp[wordList[i]]=i;
        queue<pair<int,int>>Q;
        Q.push(mkp(0,1));vis[0]=true;
        while(!Q.empty()){
            int idx=Q.front().first;
            int stp=Q.front().second;
            Q.pop();
            int len=wordList[idx].length();
            for(int i=0;i<len;i++){
                string tmp=wordList[idx];
                for(char c='a';c<='z';c++){
                    if(mp.count((tmp[i]=c,tmp))){
                        if(tmp==endWord)
                            return stp+1;
                        int nxid=mp[tmp];
                        if(!vis[nxid]){
                            vis[nxid]=true;
                            Q.push(mkp(nxid,stp+1));
                        }
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    return 0;
}
