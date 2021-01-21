#include<bits/stdc++.h>
using namespace std;
/*
思路：拓扑排序
BFS主要思想为：每次删除没有入度的节点以及相关联的边，如果最终有节点无法被删除，则说明存在环
*/
//start here
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>deg(numCourses,0);
        vector<vector<int>>G(numCourses);
        #define p prerequisites
        for(int i=0;i<p.size();i++){
            ++deg[p[i][0]];
            G[p[i][1]].push_back(p[i][0]);
        }
        queue<int>Q;
        for(int i=0;i<numCourses;i++)
            if(!deg[i])Q.push(i);
        vector<int>ret;
        while(!Q.empty()){
            int u=Q.front();Q.pop();
            ret.push_back(u);
            for(int i=0;i<G[u].size();i++){
                if(--deg[G[u][i]]==0)
                    Q.push(G[u][i]);
            }
        }
        return ret.size()==numCourses?ret:vector<int>();
    }
};
//

int main(){
    return 0;
}
