class Solution {
public:
    typedef pair<int,int> mpq;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<mpq,vector<mpq>,greater<mpq>> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};