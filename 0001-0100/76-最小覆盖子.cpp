#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int szS=s.length();
        int szT=t.length();
        if(!szS||!szT)return "";
        int l=0,r=0,L=-1,R=-1;
        vector<int>cntT(256,0);
        vector<int>cntS(256,0);
        for(int i=0;i<t.size();i++)
            cntT[t[i]]++;
        int nowMatch=0;
        while(l+t.size()<=szS){
            while(r<szS&&nowMatch!=szT){
                int alph=s[r++];
                if(cntT[alph]){
                    if(cntS[alph]<cntT[alph])
                        nowMatch++;
                    cntS[alph]++;
                }
            }
            if(nowMatch!=szT)break;
            while(l<szS&&nowMatch==szT){
                int alph=s[l++];
                if(cntT[alph]){
                    if(cntS[alph]==cntT[alph])
                        nowMatch--;
                    cntS[alph]--;
                }
            }
            L=l-1,R=r-1;
        }
        return L==-1?"":s.substr(L,R-L+1);
    }
};
int main(){
    return 0;
}
