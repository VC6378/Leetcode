class Solution {
public:

    long long f(int ind,vector<long long> &dp,vector<vector<int>> &ques){
        int n=ques.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        long long take = ques[ind][0]+f(ind+ques[ind][1]+1,dp,ques);
        long long nottake = f(ind+1,dp,ques);
        return max(take,nottake);
    }

    long long mostPoints(vector<vector<int>>& ques) {
        int n=ques.size();
        vector<long long> dp(n,-1);
        return f(0,dp,ques);
    }
};