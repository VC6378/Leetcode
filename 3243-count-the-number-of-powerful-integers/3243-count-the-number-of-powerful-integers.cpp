class Solution {
public:
    long long dp[17][2];

    long long f(string &s,int ind,int tight,long long limit,string &suffix){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind][tight]!=-1) return dp[ind][tight];
        long long ans=0;
        int maxi = tight==1 ? s[ind]-'0':9;
        int suffstart = s.size()-suffix.size();
        if(ind>=suffstart){
            int pos = ind-suffstart;
            int digit = suffix[pos]-'0';
            if(digit<=maxi && digit<=limit){
                ans+=f(s,ind+1,(tight && (digit==maxi)),limit,suffix);
            }
        }
        else{
            for(int i=0;i<=maxi && i<=limit;i++){
                ans+=f(s,ind+1,(tight&&(i==maxi)),limit,suffix);
            }
        }

        return dp[ind][tight] = ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suffix) {
        string si = to_string(start-1);
        string fi = to_string(finish);
        long long suffnum = stoll(suffix);
        if(suffnum>finish) return 0;
        memset(dp,-1,sizeof(dp));
        long long cntToFinish = f(fi,0,1,limit,suffix);
        long long cntToStart = 0;
        memset(dp,-1,sizeof(dp));
        if(start>suffnum){
            cntToStart = f(si,0,1,limit,suffix);
        }

        return cntToFinish-cntToStart;
    }
};