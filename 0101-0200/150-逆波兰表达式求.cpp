#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getVal(string &s){
        int ret=0,f=1;
        if(s[0]=='-')f=-1;
        for(int i=s[0]=='-';s[i];i++)
            ret=ret*10+s[i]-'0';
        return f*ret;
    }
    bool isOp(string op){
        return op.size()==1&&(op[0]=='+'||op[0]=='-'||op[0]=='*'||op[0]=='/');
    }
    int calc(int x,int y,char op){
        switch(op){
            case '+':return x+y;
            case '-':return x-y;
            case '*':return x*y;
            case '/':return x/y;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>ret;
        int len=tokens.size();
        for(int i=0;i<len;i++){
            if(isOp(tokens[i])){
                int x=ret.top();ret.pop();
                int y=ret.top();ret.pop();
                ret.push(calc(y,x,tokens[i][0]));
            }
            else ret.push(getVal(tokens[i]));
        }
        return ret.top();
    }
};
int main(){
    return 0;
}
