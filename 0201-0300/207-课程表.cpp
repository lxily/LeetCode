#include<bits/stdc++.h>
using namespace std;
/*
˼·�����������ж�����ͼ���Ƿ��л�
�������ѽ��ʱ����Ҫ˼��Ϊ�����ѵ�һ������ջ�еĽڵ㣬��˵�����ڻ�
*/
//start here
class Solution {
public:
    vector<int>vis;
    vector<vector<int>>graph;
    bool topoSort(int u){
        vis[u]=-1;
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            if(vis[v]<0)return false;
            else if(!vis[v]&&!topoSort(v)){
                return false;
            }
        }
        vis[u]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        vis=vector<int>(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]&&!topoSort(i))return false;
        }
        for(int i=0;i<numCourses;i++){
            cout<<vis[i]<<" ";
        }cout<<endl;
        return true;
    }
};
//

int main(){
    return 0;
}
