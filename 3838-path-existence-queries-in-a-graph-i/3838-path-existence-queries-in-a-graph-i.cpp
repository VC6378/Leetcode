class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> groups(n,0);
        for(int i=1;i<n;i++){
            groups[i] = groups[i-1]+((nums[i]-nums[i-1])>maxDiff ? 1 : 0);
        }

        for(auto it:queries){
            int u = it[0];
            int v = it[1];
            if(groups[u] == groups[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};