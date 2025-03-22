class Solution {
public:

    pair<int,int> dfs(vector<vector<int>> &adj,int node,vector<int> &vis){
        vis[node]=true;
        int nodecnt=1;
        int edgecnt = adj[node].size();
        for(auto it:adj[node]){
            if(!vis[it]){
                auto res = dfs(adj,it,vis);
                nodecnt+=res.first;
                edgecnt+=res.second;
            }
        }

        return {nodecnt,edgecnt};
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                auto result = dfs(adj,i,vis);
                ans+=(result.second == (result.first*(result.first-1)));
            }
        }
        return ans;
    }
};