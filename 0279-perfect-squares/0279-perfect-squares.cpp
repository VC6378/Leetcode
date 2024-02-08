class Solution {
public:

    int f(vector<int> &dp,int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int cnt=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            cnt=min(cnt,1+f(dp,n-(i*i)));
        }
        return dp[n]=cnt;
    }

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return f(dp,n);
    }
};