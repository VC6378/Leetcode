class Solution {
public:

    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &vis){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 or row>=m or col<0 or col>=n or !grid[row][col] or vis[row][col]) return 0;
        int temp=grid[row][col];
        vis[row][col]=1;
        temp+=solve(row+1,col,grid,vis);
        temp+=solve(row-1,col,grid,vis);
        temp+=solve(row,col+1,grid,vis);
        temp+=solve(row,col-1,grid,vis);
        return temp;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(i,j,grid,vis));
            }
        }
        return ans;
    }
};