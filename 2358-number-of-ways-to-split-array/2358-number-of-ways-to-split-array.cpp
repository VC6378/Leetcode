class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        long long sum=nums[0];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(sum>=(totalsum-sum)) cnt++;
            sum+=nums[i];
        }
        return cnt;
    }
};