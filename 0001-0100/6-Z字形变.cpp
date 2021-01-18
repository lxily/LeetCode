#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string sr[numRows];
        int i=0,inc=1,idx=0,len=s.length();
        while(i<len){
            sr[idx].push_back(s[i++]);
            if(idx==numRows-1)inc=-1;
            else if(idx==0)inc=1;
            idx+=inc;
        }
        string ret="";
        for(int i=0;i<numRows;i++)
            ret+=sr[i];
        return ret;
    }
};
int main(){
    return 0;
}
