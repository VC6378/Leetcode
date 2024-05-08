class Solution {
public:
    
    int f(vector<int> &nums,vector<int> &dp,int ind,int n){
        if(ind>=n-1) return 0;
        if(nums[ind]==0) return 1e5;
        if(dp[ind]!=-1) return dp[ind];
        int ans=1e5;
        for(int i=1;i<=nums[ind];i++){
            ans=min(ans,f(nums,dp,i+ind,n)+1);
        }
        return dp[ind]=ans;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(nums,dp,0,n);
    }
};