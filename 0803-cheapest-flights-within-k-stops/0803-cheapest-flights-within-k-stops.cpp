class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        int nn=flights.size();
        for(int i=0;i<nn;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto ptr=q.front();
            q.pop();
            int stops=ptr.first;
            int node=ptr.second.first;
            int wt=ptr.second.second;
            if(stops>k) continue;
            for(auto it:adj[node]){
                int v=it.first;
                int edgewt=it.second;
                if(wt+edgewt<dist[v]){
                    dist[v]=wt+edgewt;
                    q.push({stops+1,{v,wt+edgewt}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};