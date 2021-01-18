#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string ret="";
        int len=path.length();
        for(int i=0;i<len;i++){
            if(ret.empty())ret.push_back(path[i]);
            else{
                if(path[i]=='/'){
                    if(ret[ret.size()-1]=='/')continue;
                    else ret.push_back('/');
                }
                else if(path[i]=='.'){
                    if(i+1<len&&path[i+1]=='.'){//"../"or"/.."
                        if(i+2>=len||path[i+2]=='/'){
                            if(ret.size()>1){
                                ret.pop_back();
                                while(ret[ret.size()-1]!='/')
                                    ret.pop_back();
                                if(ret.size()>1)
                                    ret.pop_back();
                            }
                            i++;
                        }
                        else{
                            while(i<len&&path[i]!='/')
                                ret.push_back(path[i++]);
                            i--;
                        }
                    }
                    else{
                        if(i+1>=len||path[i+1]=='/')
                            if(ret.size()>1)ret.pop_back();
                        else{
                            while(i<len&&path[i]!='/')
                                ret.push_back(path[i++]);
                            i--;
                        }
                    }
                }
                else ret.push_back(path[i]);
            }
        }
        if(ret.size()>1&&ret[ret.size()-1]=='/')
            ret.pop_back();
        return ret;
    }
};
int main(){
    return 0;
}
