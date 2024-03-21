class Solution {
public:

    int f(int ind,vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1) return 0;
        if(nums[ind]==0) dp[ind] = 1e5;
        if(dp[ind]!=-1) return dp[ind];
        int ans = 1e5;
        for(int i=1;i<=nums[ind];i++){
            ans = min(ans,f(i+ind,nums,dp)+1);
        }
        return dp[ind]=ans;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};