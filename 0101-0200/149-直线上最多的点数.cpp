#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define mkp(a,b) make_pair(a,b)
    struct pair_hash{
        template<class T1, class T2>
        size_t operator() (const pair<T1, T2>& p) const{
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    int gcd(int a,int b){return !b?a:gcd(b,a%b);}
    int maxPoints(vector<vector<int>>& points) {
        if(!points.size())return 0;
        int ret=0,sz=points.size();
        unordered_map<pair<int,int>,int,pair_hash>mp;
        for(int i=0;i<sz;i++){
            int same=0,mx=0;mp.clear();
            for(int j=0;j<sz;j++){
                int x=points[i][0]-points[j][0];
                int y=points[i][1]-points[j][1];
                int d=gcd(x<0?-x:x,y<0?-y:y);
                if(d==0){same++;continue;}
                mx=max(mx,++mp[mkp(x/d,y/d)]);
            }
            ret=max(ret,mx+same);
        }
        return ret;
    }
};
int main(){
    return 0;
}
