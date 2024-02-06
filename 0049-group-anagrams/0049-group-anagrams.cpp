class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,string>> vec;
        for(int i=0;i<n;i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            vec.push_back({curr,strs[i]});
        }
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<vec.size();i++){
            mp[vec[i].first].push_back(vec[i].second);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};