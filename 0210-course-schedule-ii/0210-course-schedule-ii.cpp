class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int> adj[nc];
        vector<int> indegree(nc,0);
        for(auto it:pre){
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<nc;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size()==nc) return ans;
        return {};
    }
};