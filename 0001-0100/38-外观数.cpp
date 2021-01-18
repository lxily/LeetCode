#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s[35];
    Solution(){
        s[1]="1";
        for(int i=2;i<=30;i++)
            s[i]=getString(i);
    }
    string getString(int i){
        string p=s[i-1],ret="";
        int len=p.length();
        for(int i=0,t=0;i<len;i++,t=0){
            for(int j=i;j<len&&p[j]==p[i];j++,t++);
            ret.push_back(t+'0');
            ret.push_back(p[i]);
            i+=t-1;
        }
        return ret;
    }
    string countAndSay(int n) {
        return s[n];
    }
};
int main(){
    return 0;
}
