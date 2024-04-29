class Solution {
public:
    
    void dfs(vector<vector<int>> &image,int sr,int sc,int delrow[],int delcol[],int color,int inicolor,vector<vector<int>> &ans){
        ans[sr][sc]=color;
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]!=color && image[nrow][ncol]==inicolor){
                dfs(image,nrow,ncol,delrow,delcol,color,inicolor,ans);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        dfs(image,sr,sc,delrow,delcol,color,inicolor,ans);
        return ans;
    }
};