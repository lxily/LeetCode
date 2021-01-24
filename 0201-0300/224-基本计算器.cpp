#include<bits/stdc++.h>
using namespace std;
/*
思路：用栈进行表达式求值，注意边界情况
更好的实现见：227-基本计算器Ⅱ
*/
//start here
class Solution {
public:
    stack<int>nums;
    stack<char>opts;
    void calc(){
        char opt=opts.top();opts.pop();
        int x=nums.top();nums.pop();
        int y=nums.top();nums.pop();
        nums.push(opt=='+'?y+x:y-x);
    }
    int calculate(string s) {
        if(s[0]=='-')s="0"+s;//前导负号
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(isdigit(s[i])){
                int res=0;
                for(;isdigit(s[i]);i++){
                    res=res*10+(s[i]-'0');
                }i--;
                nums.push(res);
            }
            else if(s[i]=='('){
                opts.push('(');
            }
            else if(s[i]=='-'||s[i]=='+'){
                if(!opts.empty()&&opts.top()!='(')calc();
                opts.push(s[i]);
            }
            else {
                if(opts.top()!='(')calc();
                opts.pop();
            }
        }
        while(!opts.empty())calc();
        return nums.top();
    }
};
//

int main(){
    return 0;
}
