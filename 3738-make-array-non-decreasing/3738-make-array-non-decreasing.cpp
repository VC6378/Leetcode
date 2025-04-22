class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        int prev = -1;
        for(auto it:nums){
            if(it>=prev){
                prev = it;
                ans++;
            }
        }
        return ans;
    }
};