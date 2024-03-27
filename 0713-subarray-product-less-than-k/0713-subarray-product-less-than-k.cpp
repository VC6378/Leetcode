class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s = 0, e = 0, prod = 1, ans = 0;
        while (e < nums.size()) {
            prod *= nums[e++];
            while (s < e && prod >= k) {
                prod /= nums[s++];
            }
            ans += e - s;
        }
        return ans;
    }
};