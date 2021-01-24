#include<bits/stdc++.h>
using namespace std;
/*
思路：用栈进行表达式求值
*/
//start here
class Solution {
public:
    map<char,int>mp;
    stack<int>nums;
    stack<char>opts;
    void calc(){
        char opt=opts.top();opts.pop();
        int x=nums.top();nums.pop();
        int y=nums.top();nums.pop();
        int res;
        switch(opt){
            case '+':res=y+x;break;
            case '-':res=y-x;break;
            case '*':res=y*x;break;
            case '/':res=y/x;break;
            default: cout<<"Error!!!\n";
        }
        nums.push(res);
    }
    int calculate(string s) {
        if(s[0]=='-')s="0"+s;
        mp['+']=mp['-']=1;
        mp['*']=mp['/']=2;mp['(']=3;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(isdigit(s[i])){
                int res=0;
                for(;isdigit(s[i]);i++){
                    res=res*10+(s[i]-'0');
                }
                nums.push(res);i--;
            }
            else if(s[i]==')'){
                while(s[i]!='(')calc();
                opts.pop();
            }
            else if(opts.empty()||mp[opts.top()]<mp[s[i]]){
                opts.push(s[i]);
            }
            else{
                while(!opts.empty()&&mp[opts.top()]>=mp[s[i]]){
                    calc();
                }
                opts.push(s[i]);
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
