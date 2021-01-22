#include<bits/stdc++.h>
using namespace std;
/*
思路：离散化以后确定每一个点的最高位置，最高位置和前一个点不同时，该点为一个关键点
每个点最高位置的确定可以用multiset逐次更新，也可以用线段树维护区间最大值然后单点查询
*/
//start here
class Solution {
public:
    //离散化
    vector<int>_hashValue;
    int getId(int x){
        return lower_bound(_hashValue.begin(),_hashValue.end(),x)-_hashValue.begin();
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        for(int i=0;i<n;i++){
            _hashValue.push_back(buildings[i][0]);
            _hashValue.push_back(buildings[i][1]);
        }
        sort(_hashValue.begin(),_hashValue.end());
        _hashValue.erase(unique(_hashValue.begin(),_hashValue.end()),_hashValue.end());

        int m=_hashValue.size();
        vector<int>begAdd[m];
        vector<int>endAdd[m];
        vector<int>mxHeight(m,0);

        for(int i=0;i<n;i++){
            int x1=getId(buildings[i][0]);
            int x2=getId(buildings[i][1]);
            begAdd[x1].push_back(buildings[i][2]);
            endAdd[x2].push_back(buildings[i][2]);
        }

        multiset<int>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<begAdd[i].size();j++){
                st.insert(begAdd[i][j]);
            }
            for(int j=0;j<endAdd[i].size();j++){
                st.erase(st.find(endAdd[i][j]));
            }
            mxHeight[i]=st.size()?*(--st.end()):0;
        }

        int preHeight=0;
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            if(mxHeight[i]!=preHeight){
                ans.push_back({_hashValue[i],preHeight=mxHeight[i]});
            }
        }
        return ans;
    }
};
//

int main(){
    return 0;
}
