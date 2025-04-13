class Solution {
public:
    int mod = (int)(1e9+7);
    long long powcal(long long x,long long n){
        if(n==0){
            return 1;
        }
        long long ans = powcal(x,n/2);
        ans=ans*ans;
        ans=ans%mod;
        if(n&1){
            ans=ans*x;
            ans=ans%mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2+n%2;
        return (powcal(5,even)*powcal(4,odd))%mod;
    }
};