class Solution {
public:
    long long maximumHappinessSum(vector<int>& happy, int k) {
        long long ans=0;
        sort(happy.begin(),happy.end());
        reverse(happy.begin(),happy.end());
        int cnt=0;
        int i=0;
        while(k>0){
            if(happy[i]-cnt>=0) ans+=(happy[i]-cnt);
            cnt++;
            i++;
            k--;
        }
        return ans;
    }
};