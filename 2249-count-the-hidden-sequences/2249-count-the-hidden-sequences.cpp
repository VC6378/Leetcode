class Solution {
public:
    int numberOfArrays(vector<int>& difference, int lower, int upper) {
        int n=difference.size();
        long sum=0;
        long mini = 0;
        long maxi = 0;
        for(auto it:difference){
            sum+=it;
            maxi = max(sum,maxi);
            mini = min(sum,mini);
        }
        return max(0L,upper-lower-maxi+mini+1);
    }
};