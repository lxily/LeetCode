#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define ull unsigned long long
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ull w[26]={1};
        for(int i=2;i<26;i++)
            w[i]=w[i-1]*113;
        vector<pair<ull,string>>p;
        for(int i=0;i<strs.size();i++){
            ull _hash=0;
            for(int j=0;j<strs[i].size();j++){
                _hash+=w[strs[i][j]-'a'];
            }
            p.push_back({_hash,strs[i]});
        }
        sort(p.begin(),p.end());
        vector<vector<string>>ret;
        for(int i=0;i<p.size();i++){
            vector<string>tmp;
            if(i==0||p[i].first==p[i-1].first)
                tmp.push_back(p[i].second);
            else
                ret.push_back(tmp);
        }
        return ret;
    }
};
int main(){
    return 0;
}
