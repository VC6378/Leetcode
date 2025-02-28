class Solution {
public:
    string shortestCommonSupersequence(string one, string two) {
        int m=one.size();
        int n=two.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(one[i-1]==two[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=m;
        int j=n;
        string ans = "";
        while(i>0 && j>0){
            if(one[i-1]==two[j-1]){
                ans+=one[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=one[i-1];
                i--;
            }
            else{
                ans+=two[j-1];
                j--;
            }
        }

        while(i>0){
            ans+=one[i-1];
            i--;
        }
        while(j>0){
            ans+=two[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};