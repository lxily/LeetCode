#include<bits/stdc++.h>
using namespace std;
/*
思路：进制转化
*/
//start here
class Solution {
public:
    string convertToTitle(int n) {
        vector<int>alpha;
        while(n){
            alpha.push_back(n%26?n%26:26);
            n=(n-1)/26;
        }
        string ret="";
        for(int i=alpha.size()-1;i>=0;--i){
            ret.push_back(alpha[i]-1+'A');
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

