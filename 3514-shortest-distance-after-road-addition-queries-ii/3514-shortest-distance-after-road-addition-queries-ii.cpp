class Solution {
public:

    void f(set<int> &st,int l,int r){
        auto it_start=st.lower_bound(l);
        auto it_end=st.upper_bound(r);
        st.erase(it_start,it_end);
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int si=queries.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(i);
        }
        vector<int> ans;
        for(auto it:queries){
            int u=it[0];
            int v=it[1];
            f(st,u+1,v-1);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};