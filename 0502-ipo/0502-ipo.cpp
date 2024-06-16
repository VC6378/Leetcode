class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> projects;
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int> mxh;
        int i=0;
        while(k-->0){
            while(i<projects.size() && projects[i].first<=w){
                mxh.push(projects[i].second);
                i++;
            }
            if(mxh.empty()) break;
            w+=mxh.top();
            mxh.pop();
        }
        return w;
    }
};