class Solution {
public:

    long long f(int ind,vector<vector<int>> &que,vector<long long> &dp){
        if(ind>=que.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long nottake=f(ind+1,que,dp);
        long long take=que[ind][0]+f(ind+que[ind][1]+1,que,dp);
        return dp[ind]=max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& que) {
        int n=que.size();
        vector<long long> dp(n,-1);
        return f(0,que,dp);
    }
};