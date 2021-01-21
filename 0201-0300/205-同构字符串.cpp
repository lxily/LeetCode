#include<bits/stdc++.h>
using namespace std;
/*
思路：对应位置进行映射，判断是否有冲突
*/
//start here
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()>t.size())swap(s,t);
        unordered_map<char,char>mpst;
        unordered_map<char,char>mpts;
        for(int i=0;i<s.size();i++){
            if(mpst.count(s[i])+mpts.count(t[i])==1)return false;
            if(!mpst.count(s[i])){
                mpst[s[i]]=t[i];
                mpts[t[i]]=s[i];
            }
            if(mpst[s[i]]!=t[i])return false;
        }
        return true;
    }
};
//

int main(){
    return 0;
}
