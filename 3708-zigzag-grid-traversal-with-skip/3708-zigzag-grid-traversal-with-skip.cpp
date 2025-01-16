class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans;
        bool flag=true;
        for(int i=0;i<m;i++){
            if(i%2==0){
                //seedha
                for(int j=0;j<n;j++){
                    if(flag) {
                        ans.push_back(grid[i][j]);
                        flag = !flag;
                    }
                    else{
                        flag = !flag;
                    }
                }
                
            }
            else{
                //ulta
                for(int j=n-1;j>=0;j--){
                    if(flag){
                        ans.push_back(grid[i][j]);
                        flag = !flag;
                    }
                    else{
                        flag=!flag;
                    }
                }

            }
        }

        return ans;
    }
};