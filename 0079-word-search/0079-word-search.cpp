class Solution {
public:
    
    bool f(vector<vector<char>> &board,string word,int row,int col,int ind){
        if(ind==word.size()) return true;
        int n=board.size();
        int m=board[0].size();
        if(row<0 || row>=n || col<0 || col>=m || word[ind]!=board[row][col]) return false;
        char temp=board[row][col];
        board[row][col]='0';
        if(f(board,word,row-1,col,ind+1) or f(board,word,row+1,col,ind+1) or f(board,word,row,col+1,ind+1) or f(board,word,row,col-1,ind+1)) return true;
        board[row][col]=temp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(f(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};