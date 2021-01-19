#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string str="#";
        for(int i=0;i<len;i++){
            str.push_back(s[i]);
            str.push_back('#');
        }
        len=len<<1|1;
        vector<int>p(len,1);
        int mxl=0,idx=0,mx=1,mxid=0;
        for(int i=1;i<len;i++){
            if(mx>i)p[i]=min(p[idx*2-i],mx-i);
            for(;i-p[i]>=0&&i+p[i]<len&&str[i-p[i]]==str[i+p[i]];p[i]++);
            if(i+p[i]>mx)mx=i+p[i],idx=i;
            if(mxl<p[i]-1)mxl=p[i]-1,mxid=i;
        }
        string ret="";
        for(int i=mxid-p[mxid]+1;i<mxid+p[mxid];i++)
            if(str[i]!='#')ret.push_back(str[i]);
        return ret;
    }
};
int main(){
    return 0;
}
