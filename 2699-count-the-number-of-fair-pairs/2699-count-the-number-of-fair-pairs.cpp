class Solution {
public:

    long long f(vector<int> &nums,long long limit){
        long long cnt=0;
        for(int i = 0, j = nums.size() - 1; i < j; i++){
            while(i<j && nums[i]+nums[j]>limit) j--;
            cnt+=(j-i);
        }
        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return f(nums,upper)-f(nums,lower-1);
    }
};