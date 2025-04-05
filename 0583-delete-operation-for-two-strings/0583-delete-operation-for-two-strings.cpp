class Solution {
public:
    int minDistance(string one, string two) {
        int n=one.size();
        int m=two.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(one[i-1]==two[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int len = dp[n][m];
        return (n+m-2*len);
    }
};