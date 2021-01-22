#include<bits/stdc++.h>
using namespace std;
/*
思路：manacher求最长的回文前缀
*/
//start here
class Solution {
public:
    int manacher(string str){
        if(str=="")return 0;
        string s="@";
        int len=str.size();
        for(int i=0;i<len;i++){
            s.push_back('#');
            s.push_back(str[i]);
        }
        s.push_back('#');
        len=len*2+1;

        cout<<"str: "<<s<<endl;
        vector<int>p(len,0);
        p[0]=p[1]=1;
        int idx=1,mx=1;
        for(int i=2;i<len;i++){
            if(i<mx)p[i]=min(p[2*idx-i],mx-i);
            else p[i]=1;
            for(;s[i-p[i]]==s[i+p[i]];p[i]++);
            if(i+p[i]>mx){idx=i;mx=i+p[i];}
            if(mx>=len)return p[i]-1;
        }
        return 1;
    }
    string shortestPalindrome(string s) {
        string str=s;reverse(str.begin(),str.end());
        int last=manacher(str),sz=s.size();
        string add=s.substr(last,sz-last);
        reverse(add.begin(),add.end());
        return add+s;
    }
};
//

int main(){
    return 0;
}
