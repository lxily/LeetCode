#include<bits/stdc++.h>
using namespace std;
/*
˼·������ת��
*/
//start here
class Solution {
public:
    int titleToNumber(string s) {
        long long ret=0;
        for(int i=0;i<s.size();++i){
            ret=ret*26+(s[i]-'A')+1;
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

