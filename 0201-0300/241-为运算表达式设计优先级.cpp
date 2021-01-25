#include<bits/stdc++.h>
using namespace std;
/*
思路：带回溯的表达式求值，每次遇到运算符的时候，可以选择直接放入，或者先计算前面的运算符（传参比较耗时，可以优化）
*/
//start here
class Solution {
public:
    #define inf 0x3f3f3f3f
    vector<int>ret;
    void cal(stack<int>&nums,stack<char>&opts){
        int x=nums.top();nums.pop();
        int y=nums.top();nums.pop();
        int res=inf;
        switch (opts.top()){
            case '+': res=y+x;break;
            case '-': res=y-x;break;
            case '*': res=y*x;break;
        }
        if(res==inf){cout<<"Error!!!\n";exit(0);}
        nums.push(res);opts.pop();
    }
    void dfs(string input,int idx,stack<int>nums,stack<char>opts){
        if(idx==input.size()){
            while(opts.size())cal(nums,opts);
            ret.push_back(nums.top());
            return;
        }
        if(isdigit(input[idx])){
            int res=0;
            for(;isdigit(input[idx]);idx++){
                res=res*10+(input[idx]-'0');
            }
            nums.push(res);idx--;
        }
        else {
            stack<int>tmpNums=nums;
            stack<char>tmpOpts=opts;
            while(tmpOpts.size()){
                cal(tmpNums,tmpOpts);
                tmpOpts.push(input[idx]);
                dfs(input,idx+1,tmpNums,tmpOpts);
                tmpOpts.pop();
            }
            opts.push(input[idx]);
        }
        dfs(input,idx+1,nums,opts);
    }
    vector<int> diffWaysToCompute(string input) {
        dfs(input,0,{},{});return ret;
    }
};
//

int main(){
    return 0;
}
