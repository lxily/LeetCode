#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º¹þÏ£
*/
//start here
class Solution {
public:
    #define ull unsigned long long
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)return {};
        unsigned long long randSeed=113;
        vector<ull>weight(26,3);
        vector<ull>exponent(15,1);
        for(int i=1;i<26;i++)weight[i]=weight[i-1]*26;
        for(int i=1;i<15;i++)exponent[i]=exponent[i-1]*randSeed;
        ull hashValue=0;
        for(int i=0;i<10;i++){
            hashValue=hashValue*randSeed+weight[s[i]-'A'];
        }
        unordered_map<ull,int>mp;
        unordered_map<ull,string>rec;
        vector<ull>allValue;
        mp[hashValue]++;
        rec[hashValue]=s.substr(0,10);
        allValue.push_back(hashValue);

        for(int i=10;i<s.size();i++,mp[hashValue]++){
            hashValue-=weight[s[i-10]-'A']*exponent[9];
            hashValue=hashValue*randSeed+weight[s[i]-'A'];
            if(!mp.count(hashValue)){
                allValue.push_back(hashValue);
                rec[hashValue]=s.substr(i-9,10);
            }
        }

        vector<string>ret;
        for(int i=0;i<allValue.size();i++){
            if(mp[allValue[i]]>1){
                ret.push_back(rec[allValue[i]]);
            }
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

