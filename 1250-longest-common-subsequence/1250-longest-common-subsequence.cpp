class Solution {
public:

    int f(string &one,string &two,vector<vector<int>> &dp,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(one[i]==two[j]){
            return dp[i][j]=1+f(one,two,dp,i-1,j-1);
        }
        else{
            return dp[i][j]=max(f(one,two,dp,i-1,j),f(one,two,dp,i,j-1));
        }
    }

    int longestCommonSubsequence(string one, string two) {
        int m=one.size();
        int n=two.size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(one,two,dp,m-1,n-1);
    }
};