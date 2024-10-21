class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    bool valid(int i,int j,vector<vector<int>> &grid){
        int n=grid.size();
        if(i>=0 and i<n and j>=0 and j<n) return true;
        return false;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int ind=0;ind<4;ind++){
                    int newi=i+delrow[ind];
                    int newj=j+delcol[ind];
                    if(valid(newi,newj,grid) and grid[newi][newj]==1){
                        int node=i*n+j;
                        int adjnode=newi*n+newj;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> st;
                for(int ind=0;ind<4;ind++){
                    int newi=i+delrow[ind];
                    int newj=j+delcol[ind];

                    if(valid(newi,newj,grid)){
                        if(grid[newi][newj]==1){
                            st.insert(ds.findUPar(newi*n+newj));
                        }
                    }
                }

                int sum=0;
                for(auto it:st){
                    sum+=ds.size[it];
                }
                maxi=max(maxi,sum+1);
            }
        }

        for(int ind=0;ind<n*n;ind++){
            maxi=max(maxi,ds.size[ds.findUPar(ind)]);
        }
        return maxi;
    }
};