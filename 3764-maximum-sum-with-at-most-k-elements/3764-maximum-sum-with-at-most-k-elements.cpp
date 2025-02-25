class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back({grid[i][j],i});
            }
        }
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        vector<int> count(n,0);
        int selected=0;
        for(auto it:arr){
            int val = it.first;
            int row = it.second;
            if(count[row]<limits[row] && selected<k){
                ans+=val;
                count[row]++;
                selected++;
            }
            if(selected==k) break;
        }
        return ans;
    }
};