#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        #define inf 0x3f3f3f3f
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<m;k++){//��i������
                        if(k<j&&!matrix[i][k])break;//ǰ����0����Ҫ�ٴθ�ֵ
                        if(matrix[i][k])matrix[i][k]=inf;
                    }
                    for(int k=0;k<m;k++){//��i������
                        if(k<i&&!matrix[k][j])break;//ǰ����0����Ҫ�ٴθ�ֵ
                        if(matrix[k][j])matrix[k][j]=inf;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)
                if(matrix[i][j]==inf)matrix[i][j]=0;
    }
};
int main(){
    return 0;
}
