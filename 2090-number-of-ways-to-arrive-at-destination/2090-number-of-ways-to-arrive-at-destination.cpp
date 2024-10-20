class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,1e15);
        vector<long long> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            auto ptr=pq.top();
            int distance=ptr.first;
            int node=ptr.second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjnode=it.first;
                long long edgewt=it.second;
                if(distance+edgewt<dist[adjnode]){
                    dist[adjnode]=distance+edgewt;
                    pq.push({distance+edgewt,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(distance+edgewt==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};