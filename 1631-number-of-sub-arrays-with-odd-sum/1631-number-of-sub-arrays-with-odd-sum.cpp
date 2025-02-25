class Solution {
public:
    int mod = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long cnt=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            cnt+=(sum%2);
        }
        cnt+=(n-cnt)*cnt;
        cnt = cnt%mod;
        return cnt;
    }
};