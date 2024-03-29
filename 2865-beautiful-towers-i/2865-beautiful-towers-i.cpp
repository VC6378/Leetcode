class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxh) {
        int n=maxh.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long sum=maxh[i];
            int peak=maxh[i];
            for(int j=i-1;j>=0;j--){
                peak=min(peak,maxh[j]);
                sum+=peak;
            }
            peak=maxh[i];
            for(int j=i+1;j<n;j++){
                peak=min(peak,maxh[j]);
                sum+=peak;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};