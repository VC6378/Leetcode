class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }

        sort(q.begin(),q.end());

        int dirx[]={0,+1,0,-1};
        int diry[]={+1,0,-1,0};
        vector<vector<int>> vis(m,vector<int>(n,false));

        vector<int> result(queries.size(),0);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=true;
        int point=0;
        for(int i=0;i<q.size();i++){
            int queryval = q[i].first;
            int ind = q[i].second;
            
            while(!pq.empty() && pq.top().first<queryval){
                auto ptr = pq.top();
                int pqval = ptr.first;
                int row=ptr.second.first;
                int col=ptr.second.second;
                point++;
                pq.pop();

                for(int j=0;j<4;j++){
                    int nrow = row+dirx[j];
                    int ncol=col+diry[j];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                        pq.push({grid[nrow][ncol],{nrow,ncol}});
                        vis[nrow][ncol]=true;
                    }
                }
            }

            result[ind]=point;
        }

        return result;
    }
};