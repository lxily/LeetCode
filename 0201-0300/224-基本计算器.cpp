#include<bits/stdc++.h>
using namespace std;
/*
˼·����ջ���б��ʽ��ֵ��ע��߽����
���õ�ʵ�ּ���227-������������
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
        if(s[0]=='-')s="0"+s;//ǰ������
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
