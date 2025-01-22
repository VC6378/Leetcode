class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        int m=water.size();
        int n=water[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(water[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        int dr[]={0,+1,0,-1};
        int dc[]={+1,0,-1,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==-1){
                    ans[nrow][ncol]=1+ans[row][col];
                    q.push({nrow,ncol});
                }
            }

        }

        return ans;
    }
};