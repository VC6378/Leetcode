class Solution {
public:
    bool canFinish(int nodes, vector<vector<int>>& pre) {
        int edges=pre.size();
        vector<int> adj[nodes];
        vector<int> indegree(nodes,0);
        for(int i=0;i<edges;i++){
            int a=pre[i][0];
            int b=pre[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i=0;i<nodes;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return ans.size()==nodes;
    }
};