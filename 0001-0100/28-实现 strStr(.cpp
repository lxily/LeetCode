#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
    //±©Á¦
    int strStr(string haystack, string needle) {
        if(!needle.size())return 0;
        if(haystack.size()<needle.size())return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            bool fd=true;
            for(int j=0;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]){
                    fd=false;break;
                }
            }
            if(fd)return i;
        }
        return -1;
    }
    */
    //kmp
    void getNext(string s,int len,vector<int>&nxt){
        int i,j;
        j=nxt[0]=-1;
        i=0;
        while(i<len){
            while(j!=-1&&s[i]!=s[j])j=nxt[j];
            nxt[++i]=++j;
        }
    }
    int strStr(string haystack, string needle) {
        if(!needle.size())return 0;
        int i=0,j=0;
        vector<int>nxt(needle.size()+10);
        getNext(needle,int(needle.size()),nxt);
        while(i<haystack.size()){
            while(j!=-1&&haystack[i]!=needle[j])j=nxt[j];
            ++i;++j;
            if(j>=needle.size())return i-needle.size();
        }
        return -1;
    }
};
int main(){
    return 0;
}
