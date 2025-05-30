class Solution {
public:

    bool isSafe(int row,int col,vector<string> &board,int n){
        int dupr=row;
        int dupc=col;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        row=dupr;
        col=dupc;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=dupr;
        col=dupc;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }

    void f(int col,vector<vector<string>> &ans,vector<string> &board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                f(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        f(0,ans,board,n);
        return ans;
    }
};