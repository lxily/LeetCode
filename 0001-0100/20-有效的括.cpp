#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')S.push(s[i]);
            else{
                if(S.empty())return false;
                if(s[i]==')'&&S.top()=='('||
                   s[i]==']'&&S.top()=='['||
                   s[i]=='}'&&S.top()=='{')
                    S.pop();
                else return false;
            }
        }
        return S.size()==0;
    }
};
int main(){
    return 0;
}
