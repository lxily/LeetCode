#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int ret=0,len=s.length();
        for(int l=0,i=0;i<len;i++){
            while(mp[s[i]])--mp[s[l++]];
            ++mp[s[i]];
            if(ret<i-l+1)ret=i-l+1;
        }
        return ret;
    }
}S;
int main(){
    return 0;
}
