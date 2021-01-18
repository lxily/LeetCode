#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getSpace(int n){
        string ret="";
        while(n--)ret.push_back(' ');
        return ret;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ret;
        int sz=words.size();
        for(int i=0;i<sz;i++){
            int j=i,len=0;
            while(j<sz&&len+words[j].size()+j-i<=maxWidth)
                len+=words[j].size(),j++;
            int cnt=j-i-1,space=maxWidth-len;
            int base=space/cnt,pre=space%cnt;
            //前pre个间隔放base+1个空格
            string tmp=words[i];
            if(j==sz){//最后一行
                for(int k=i+1;k<j;k++){
                    tmp.push_back(' ');
                    tmp+=words[k];
                }
                tmp+=getSpace(space-cnt);
            }
            else{
                for(int t=0,k=i;k<j;k++,t++){
                    tmp+=getSpace(base+(t<pre));
                    tmp+=words[k];
                }
            }
            ret.push_back(tmp);i=j-1;
        }
    }
};
int main(){
    return 0;
}
