#include<bits/stdc++.h>
using namespace std;
/*
思路：构建字典树，搜索碰到'.'时遍历当层的全部字母即可
*/
//start here
class WordDictionary {
public:
    const static int maxnode = 100000, sigma_size = 26;
    int ch[maxnode][sigma_size];
    bool val[maxnode];
    int sz;//结点总数
    int idx(char c) {return c-'a';} // 字符c的编号
    /** Initialize your data structure here. */
    WordDictionary() {
        sz = 1; memset(ch[0], 0, sizeof ch[0]);
    }

    void addWord(string word) {
        int u = 0, n = word.length();
        for(int i = 0; i < n; ++ i)
        {
            int c = idx(word[i]);
            if(!ch[u][c])//结点不存在
            {
                memset(ch[sz], 0, sizeof ch[sz]);
                val[sz] = 0;
                ch[u][c] = sz ++;
            }
            u = ch[u][c];//往下走
        }
        val[u] =true ;//字符串的最后一个字符的附加信息为v
    }

    bool find(string &word,int u,int l){
        if(word[l]!='.'){
            int c=idx(word[l]);
            if(!ch[u][c])return false;
            if(l==word.size()-1)return val[ch[u][c]];
            else return find(word,ch[u][c],l+1);
        }
        else for(int c=0;c<26;c++){
            if(!ch[u][c])continue;
            if(l==word.size()-1){if(val[ch[u][c]])return true;}
            else if(find(word,ch[u][c],l+1))return true;
        }
        return false;
    }

    bool search(string word) {
        if(!word.size())return true;
        return find(word,0,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//

int main(){
    return 0;
}
