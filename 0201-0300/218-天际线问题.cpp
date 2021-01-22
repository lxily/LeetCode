#include<bits/stdc++.h>
using namespace std;
/*
˼·����ɢ���Ժ�ȷ��ÿһ��������λ�ã����λ�ú�ǰһ���㲻ͬʱ���õ�Ϊһ���ؼ���
ÿ�������λ�õ�ȷ��������multiset��θ��£�Ҳ�������߶���ά���������ֵȻ�󵥵��ѯ
*/
//start here
class Solution {
public:
    //��ɢ��
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
