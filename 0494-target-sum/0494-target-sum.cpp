class Solution {
public:
    
    int f(vector<int> &nums,int sum,int n){
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<sum+1;i++){
            dp[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(target>sum) return 0;
        if((target+sum)&1) return 0;
        sum=(sum-target)/2;
        return f(nums,sum,n);
    }
};