#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define FOR(i,a,b) for(int i=a;i<b;i++)
    bool valid(string s){
        if(s=="0")return true;
        if(s[0]=='0')return false;
        int ret=0,len=s.length();
        for(int i=0;i<len;i++)
            ret=ret*10+s[i]-'0';
        return ret>=0&&ret<256;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12)return {};
        vector<string>ret;
        FOR(i,1,4)FOR(j,1,4)
            FOR(x,1,4)FOR(y,1,4){
                if(i+j+x+y!=s.size())continue;
                string s1=s.substr(0,i);
                string s2=s.substr(i,j);
                string s3=s.substr(i+j,x);
                string s4=s.substr(i+j+x,y);
                if(valid(s1)&&valid(s2)&&valid(s3)&&valid(s4))
                    ret.push_back(s1+"."+s2+"."+s3+"."+s4);
            }
        return ret;
    }
};
int main(){
    return 0;
}
