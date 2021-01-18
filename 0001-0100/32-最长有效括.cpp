#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char,int>>S;
        int ret=0;
        for(int i=0;i<s.size();i++){
            if(S.empty()||s[i]=='('){
                S.push(make_pair(s[i],i));
            }
            else if(s[i]==')'&&S.top().first=='('){
                pair<char,int>O=S.top();S.pop();
                if(S.empty())ret=i+1;
                else{
                    ret=max(ret,i-S.top().second);
                }
            }
            else S.push(make_pair(s[i],i));
        }
        return ret;
    }
};
int main(){
    return 0;
}
