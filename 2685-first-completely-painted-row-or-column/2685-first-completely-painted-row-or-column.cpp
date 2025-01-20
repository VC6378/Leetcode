class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int si=arr.size();
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }

        vector<int> rowCount(m, n), colCount(n, m);

        for(int i=0;i<si;i++){
            int val=arr[i];
            int row = mp[val].first;
            int col = mp[val].second;
            rowCount[row]--;
            colCount[col]--;
            if(rowCount[row]==0 or colCount[col]==0) return i;
        }
        return -1;
    }
};