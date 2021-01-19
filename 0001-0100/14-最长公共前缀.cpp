#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        int l=0;
        for(l=0;l<strs[0].size();l++){
            bool match=true;
            char ch=strs[0][l];
            for(int i=1;i<strs.size();i++){
                if(l>=strs[i].size()||strs[i][l]!=ch){
                    match=false;break;
                }
            }
            if(!match)break;
        }
        return strs[0].substr(0,l);
    }
};
int main(){
    return 0;
}
