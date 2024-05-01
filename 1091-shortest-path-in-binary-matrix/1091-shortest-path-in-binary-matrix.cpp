class Solution {
public:
    
    bool check(int nrow,int ncol,int n,vector<vector<int>> &grid){
        return (nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]) return -1;
        int res=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=2;
        
        vector<pair<int, int>> dirc = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1},
                                       {-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}};
        int ans=0;
        while(!q.empty()){
            int si=q.size();
            ans++;
            for(int i=0;i<si;i++){
                auto node=q.front();
                q.pop();
                int row=node.first;
                int col=node.second;
                if(row==n-1 && col==n-1) return ans;
                for(int i=0;i<8;i++){
                    int nrow=row+dirc[i].first;
                    int ncol=col+dirc[i].second;
                    if(check(nrow,ncol,n,grid)){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};