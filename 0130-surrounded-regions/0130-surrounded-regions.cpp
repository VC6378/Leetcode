class Solution {
public:

    void dfs(vector<vector<int>> &vis,vector<vector<char>> &board,int row,int col,int m,int n){
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+row;
            int ncol=delcol[i]+col;

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(vis,board,nrow,ncol,m,n);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n));

        //first row
        for(int i=0;i<n;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(vis,board,0,i,m,n);
            }
        }

        //last row
        for(int i=0;i<n;i++){
            if(!vis[m-1][i] && board[m-1][i]=='O'){
                dfs(vis,board,m-1,i,m,n);
            }
        }

        //first column
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(vis,board,i,0,m,n);
            }
        }

        //last column
        for(int i=0;i<m;i++){
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(vis,board,i,n-1,m,n);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};