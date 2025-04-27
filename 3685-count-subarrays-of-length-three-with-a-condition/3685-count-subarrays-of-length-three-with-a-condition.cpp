class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++){
            int sum=0;
            int first = nums[i];
            int sec = nums[i+1];
            int third = nums[i+2];
            if(2*(first+third) == sec) cnt++;
        }
        return cnt;
    }
};