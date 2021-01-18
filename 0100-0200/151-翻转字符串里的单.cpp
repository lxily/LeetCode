#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ret="";
        stringstream in(s);
        while(in>>s){
            reverse(s.begin(),s.end());
            ret+=(ret.size()?" ":"")+s;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    return 0;
}
