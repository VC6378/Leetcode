class Solution {
public:

    bool f(vector<vector<char>> &board,int i,int j,string &word,int ind){
        if(ind==word.size()) return true;
        int m=board.size();
        int n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[ind]) return false;
        char temp = board[i][j];
        board[i][j]='0';
        if(f(board,i-1,j,word,ind+1) || f(board,i+1,j,word,ind+1) || f(board,i,j+1,word,ind+1) || f(board,i,j-1,word,ind+1)) return true;
        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(f(board,i,j,word,0)) return true;
            }
        }
        return false;
    }
};