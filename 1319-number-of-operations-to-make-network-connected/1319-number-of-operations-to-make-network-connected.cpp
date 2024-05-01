
class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int upar=findUPar(u);
        int vpar=findUPar(v);
        if(upar==vpar) return;
        if(size[upar]<size[vpar]){
            size[vpar]+=size[upar];
            parent[upar]=vpar;
        }
        else{
            size[upar]+=size[vpar];
            parent[vpar]=upar;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        int cnt=0;
        DisjointSet ds(n);
        int extra=0;
        for(int i=0;i<con.size();i++){
            int a=con[i][0];
            int b=con[i][1];
            if(ds.findUPar(a)==ds.findUPar(b)) extra++;
            else{
                ds.unionBySize(a,b);
            }
        }
        int cntc=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i) cntc++;
        }
        int ans=cntc-1;
        if(extra>=ans) return ans;
        return -1;
    }
};