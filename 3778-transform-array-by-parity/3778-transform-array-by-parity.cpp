class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            if(it&1){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};