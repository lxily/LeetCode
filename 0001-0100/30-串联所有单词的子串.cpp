#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(!s.size()||!words.size())return {};
        int lens=s.length();
        int lenw=words[0].length();
        int lena=lenw*words.size();
        unordered_map<string,int>mp,re;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        vector<int>ret;
        for(int i=0;i<=lens-lena;i++){
            re=mp;bool fd=true;
            for(int j=i;j<i+lena;j+=lenw){
                string wd=s.substr(j,lenw);
                if(!re.count(wd)||!(re[wd]--)){
                    fd=false;break;
                }
            }
            if(fd)ret.push_back(i);
        }
        return ret;
    }
};
int main(){
    return 0;
}
