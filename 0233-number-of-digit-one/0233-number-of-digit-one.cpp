class Solution {
public:
    int dp[12][2][12];

    int solve(string s,int ind,int tight,int cnt){
        if(ind==s.size()){
            return cnt;
        }
        if(dp[ind][tight][cnt]!=-1) return dp[ind][tight][cnt];
        int limit = (tight==1? s[ind]-'0' : 9);
        int ans = 0;
        for(int i=0;i<=limit;i++){
            int updateCnt = (i==1 ? cnt+1 : cnt);
            ans+=solve(s,ind+1,(tight&(i==s[ind]-'0')),updateCnt);
        }
        return dp[ind][tight][cnt] = ans;
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(s,0,1,0);
    }
};