#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    struct Mpair{
        int x,y;
        bool operator < (const Mpair& mp)const{
            return x<mp.x;
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ret;
        int sz=intervals.size();
        if(!sz)return ret;
        vector<Mpair>mp;
        for(int i=0;i<sz;i++)
            mp.push_back({intervals[i][0],intervals[i][1]});
        sort(mp.begin(),mp.end());
        ret.push_back({mp[0].x,mp[0].y});
        for(int i=1,l=0;i<sz;i++){
            if(mp[i].x<=ret[l][1]){
                if(mp[i].y>ret[l][1]){
                    ret[l][1]=mp[i].y;
                }
            }
            else ret.push_back({mp[i].x,mp[i].y}),l++;
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

