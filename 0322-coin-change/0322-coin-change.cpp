class Solution {
public:

    int f(vector<int> &coins,int target,int ind,vector<vector<int>> &dp){
        if(target==0) 1;
        if(ind==0){
            if(target%(coins[ind])==0) return target/coins[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=f(coins,target,ind-1,dp);
        int take=1e9;
        if(target>=coins[ind]){
            take=1+f(coins,target-coins[ind],ind,dp);
        }
        return dp[ind][target]=min(take,nottake);
    }

    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        int ans= f(coins,target,n-1,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};