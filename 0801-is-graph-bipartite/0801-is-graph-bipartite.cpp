class Solution {
public:

    bool f(vector<vector<int>> &graph,vector<int> &vis,int node){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            vector<int> v = graph[q.front()];
            int val=q.front();
            q.pop();
            int si=v.size();
            for(int i=0;i<si;i++){
                if(vis[v[i]]==-1){
                    vis[v[i]]=!vis[val];
                    q.push(v[i]);
                }
                else{
                    if(vis[v[i]]==vis[val]) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,-1);
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(f(graph,vis,i)==false) return false;
            }
        }
        return true;
    }
};