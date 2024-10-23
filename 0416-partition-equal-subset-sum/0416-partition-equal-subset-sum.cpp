class Solution {
public:

    bool f(vector<vector<int>> &dp,int ind,int target,vector<int> &nums){
        if(target==0) return true;
        if(ind==0){
            if(target==0) return true;
            else return false;
        }

        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(nums[ind]<=target) take = f(dp,ind-1,target-nums[ind],nums);
        bool nottake = f(dp,ind-1,target,nums);
        return dp[ind][target]=take or nottake; 
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(dp,n-1,target,nums);
    }
};
