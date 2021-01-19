#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int len=str.length(),ret=0,i=0;
        while(i<len&&str[i]==' ')i++;
        int sgn=i<len&&str[i]=='-'?-1:1;
        if(str[i]=='-'||str[i]=='+')i++;
        while(str[i]>='0'&&str[i]<='9'){
            if(sgn<0&&ret*10ll-str[i]+'0'<INT_MIN)
                return INT_MIN;
            if(sgn>0&&ret*10ll-str[i]-'0'>INT_MAX)
                return INT_MAX;
            ret=ret*10+sgn*(str[i]-'0');
        }
        return ret;
    }
};
int main(){
    return 0;
}
