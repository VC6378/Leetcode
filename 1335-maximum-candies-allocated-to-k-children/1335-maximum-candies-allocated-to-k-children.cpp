class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long left = 1;
        long long right = *max_element(candies.begin(),candies.end());
        int result=0;
        while(left<=right){
            long long mid = left+(right-left)/2;
            long long childcnt=0;
            for(auto pile:candies){
                childcnt+=pile/mid;
            }
            if(childcnt>=k){
                result=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return result;
    }
};