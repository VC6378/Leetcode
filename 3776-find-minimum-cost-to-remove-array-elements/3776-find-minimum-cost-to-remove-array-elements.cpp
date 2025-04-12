class Solution {
public:

    int f(int ind,int last,vector<vector<int>> &dp,vector<int> &nums){
        if(ind==nums.size()) return nums[last];
        if(ind==nums.size()-1) return max(nums[ind],nums[last]);
        if(dp[ind][last]!=-1) return dp[ind][last];

        int opt1 = max(nums[ind],nums[ind+1])+f(ind+2,last,dp,nums);
        int opt2 = max(nums[ind],nums[last])+f(ind+2,ind+1,dp,nums);
        int opt3 = max(nums[ind+1],nums[last])+f(ind+2,ind,dp,nums);
        return dp[ind][last] = min({opt1,opt2,opt3});
    }

    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,0,dp,nums);
    }
};