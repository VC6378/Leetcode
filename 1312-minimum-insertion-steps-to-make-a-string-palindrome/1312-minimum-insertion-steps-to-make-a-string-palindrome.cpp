class Solution {
public:
    
    int lcs(string one,string two){
        int n=one.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(one[i-1]==two[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    
    int maxi(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        return lcs(s,temp);
    }
    
    int minInsertions(string s) {
        int n=s.size();
        return n-maxi(s);
    }
};