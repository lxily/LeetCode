#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ret;int x=1;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++){
            ret.push_back((digits[i]+x)%10);
            x=(digits[i]+x)>=10;
        }
        if(x)ret.push_back(x);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    return 0;
}
