class Solution {
public:
    long long solve(vector<int> &piles,int bananaperhr){
        long long hrs=0;
        for(int i=0;i<piles.size();i++){
            hrs+=ceil(piles[i]/(double)bananaperhr);
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int low=1;
        int ans=-1;
        int high=piles[n-1];
        while(low<=high){
            int mid = low+(high-low)/2;
            long long cnt = solve(piles,mid);
            if(cnt<=h){
                ans=cnt;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};