class Solution {
public:
    int minDistance(string one, string two) {
        int m=one.size();
        int n=two.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(one[i-1]==two[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int len=dp[m][n];
        return (m+n-2*len);
    }
};