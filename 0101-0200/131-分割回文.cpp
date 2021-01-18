#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>p;
    void manacher(string &s){
        p.resize(s.size());
        int idx=0,mx=1;p[0]=1;
        for(int i=1;i<s.size();i++){
            p[i]=mx>i?min(mx-i,p[2*idx-i]):1;
            for(;s[i-p[i]]==s[i+p[i]];p[i]++);
            if(i+p[i]>mx){mx=i+p[i];idx=i;}
        }
    }
    inline bool check(int l,int r){
        ++l;++r;l<<=1;r<<=1;
        return p[(l+r)>>1]*2-1>=r-l+1;
    }
    void solve(string &s,int idx,vector<string>&now,vector<vector<string>>&ret){
        if(idx==s.size()){
            ret.push_back(now);
            return;
        }
        string tmp="";
        for(int i=idx;i<s.size();i++){
            tmp.push_back(s[i]);
            if(check(idx,i)){
                now.push_back(tmp);
                solve(s,i+1,now,ret);
                now.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        string s1="$#";
        int len=s.length();
        for(int i=0;i<len;i++){
            s1.push_back(s[i]);
            s1.push_back('#');
        }
        //$#a#b#c#d#
        //0->1+1,1->1+3,2->1+5: i->1+(i*2+1)=(i+1)*2
        manacher(s1);
        vector<string>now;
        vector<vector<string>>ret;
        solve(s,0,now,ret);
        return ret;
    }
};
int main(){
    return 0;
}
