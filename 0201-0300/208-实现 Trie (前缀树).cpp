#include<bits/stdc++.h>
using namespace std;
/*
思路：裸字典树实现
*/
//start here
class Trie {
public:
    const static int maxnode = 100000, sigma_size = 26;
    int ch[maxnode][sigma_size];
    bool val[maxnode];
    int sz;//结点总数
    int idx(char c) {return c-'a';} // 字符c的编号
    /** Initialize your data structure here. */
    Trie() {
        sz = 1; memset(ch[0], 0, sizeof ch[0]);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int u = 0, n = word.length();
        for(int i = 0; i < n; ++ i)
        {
            int c = idx(word[i]);
            if(!ch[u][c])return false;
            u = ch[u][c];
        }
        return val[u];
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int u = 0, n = prefix.length();
        for(int i = 0; i < n; ++ i)
        {
            int c = idx(prefix[i]);
            if(!ch[u][c])return false;
            u = ch[u][c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
//

int main(){
    return 0;
}
