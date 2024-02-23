class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int dist=it[2];
            adj[u].push_back({v,dist});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            auto ptr=q.front();
            q.pop();
            int stops=ptr.first;
            int node=ptr.second.first;
            int distance=ptr.second.second;
            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjdis=it.second;
                if(distance+adjdis<dis[adjnode]){
                    dis[adjnode]=distance+adjdis;
                    q.push({stops+1,{adjnode,dis[adjnode]}});
                }
            }
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};