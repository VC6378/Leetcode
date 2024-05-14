class Solution {
public:
    
    int f(vector<vector<int>> &grid,int row,int col,int m,int n){
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]==0) return 0;
        int curr=grid[row][col];
        grid[row][col]=0;
        int localmax=curr;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            localmax=max(localmax,curr+f(grid,nrow,ncol,m,n));
        }
        grid[row][col]=curr;
        return localmax;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    maxi=max(maxi,f(grid,i,j,m,n));
                }
            }
        }
        return maxi;
    }
};