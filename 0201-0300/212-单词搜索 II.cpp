#include<bits/stdc++.h>
using namespace std;
/*
思路：实现带删除操作的字典树，利用字典树进行回溯匹配搜索
*/
//start here
class Solution {
public:
    int n,m;
    vector<string>ans;
    vector<vector<bool>>vis;
    vector<vector<char>> _board;
    const int dir[4][2]={1,0,-1,0,0,1,0,-1};

    //字典树
    const static int maxnode = 100000, sigma_size = 26;
    int ch[maxnode][sigma_size];
    int val[maxnode];
    bool isWord[maxnode];
    int sz;//结点总数
    int idx(char c) {return c-'a';} // 字符c的编号

    Solution() {
        sz = 1; memset(ch[0], 0, sizeof ch[0]);
    }

    void insert(string word) {
        int u = 0, n = word.size();
        for(int i = 0; i < n; ++ i)
        {
            int c = idx(word[i]);
            if(!ch[u][c])//结点不存在
            {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                isWord[sz]=false;
                ch[u][c] = sz ++;
            }
            val[u = ch[u][c]]++;//往下走
        }
        isWord[u] = true ;//字符串的最后一个字符的附加信息为v
    }
    void remove(string word) {
        int u = 0, n = word.size();
        for(int i = 0;i < n; i++){
            int c = idx(word[i]);
            if(!ch[u][c]||!val[ch[u][c]]){
                cout<<"Remove Error!!!\n";
                exit(0);
            }
            val[u = ch[u][c]]--;
        }
        isWord[u]=false;
    }

    bool search(string word) {
        int u = 0, n = word.size();
        for(int i = 0; i < n; ++ i)
        {
            int c = idx(word[i]);
            if(!ch[u][c])return false;
            u = ch[u][c];
        }
        return isWord[u];
    }

    void dfs(string now,int u,int x,int y){
        if(x<0||x>=n||y<0||y>=m)return;
        if(vis[x][y])return;
        vis[x][y]=true;
        now.push_back(_board[x][y]);
        if(isWord[u]){
            ans.push_back(now);
            remove(now);
        }
        for(int i=0;i<4;i++){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            int c=idx(_board[nx][ny]);
            if(!ch[u][c]||!val[ch[u][c]])continue;
            dfs(now,ch[u][c],nx,ny);
        }
        vis[x][y]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        _board = board;
        n=_board.size();
        m=_board[0].size();
        unordered_map<string,bool>appear;
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        for(int i=0;i<words.size();i++){
            if(!appear.count(words[i])){
                insert(words[i]);
                appear[words[i]]=true;
            }
        }
        ans.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=idx(_board[i][j]);
                if(ch[0][c]&&val[ch[0][c]]){
                    dfs("",ch[0][c],i,j);
                }
            }
        }
        return ans;
    }
};
//

int main(){
    return 0;
}
