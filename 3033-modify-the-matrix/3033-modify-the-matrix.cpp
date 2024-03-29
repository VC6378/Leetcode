class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> maxi;
        for(int i=0;i<n;i++){
            int hehe=-1;
            for(int j=0;j<m;j++){
                hehe=max(hehe,matrix[j][i]);
            }
            maxi.push_back(hehe);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=maxi[j];
                }
            }
        }
        return matrix;
    }
};