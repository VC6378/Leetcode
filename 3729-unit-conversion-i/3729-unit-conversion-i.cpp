class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conve) {
        int n = conve.size()+1;
        vector<int> ans(n);
        vector<vector<pair<int,int>>> vec(n);
        for(auto it:conve){
            vec[it[0]].push_back({it[1],it[2]});
        }
        int mod = 1e9+7;
        queue<int> q;
        q.push(0);
        ans[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:vec[node]){
                int adjnode = it.first;
                int cost = it.second;
                ans[adjnode] = (1ll*ans[node]*cost)%mod;
                q.push(adjnode);
            }
        }

        return ans;
    }
};