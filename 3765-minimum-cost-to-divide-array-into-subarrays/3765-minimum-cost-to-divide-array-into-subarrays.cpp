class Solution {
public:
    long long solve(int start, int end, int k, vector<long long>& prefixNums, vector<long long>& prefixCosts, vector<vector<long long>>& dp) {
        int n = prefixNums.size();
        if (end == n) {
            return (start == n) ? 0 : LLONG_MAX;
        }
        
        if (dp[start][end] != -1) return dp[start][end];

        long long currentNumsSum = prefixNums[end], currentCostSum = prefixCosts[n - 1];

        if (start != 0) {
            currentNumsSum = prefixNums[end] - prefixNums[start - 1];
            currentCostSum = prefixCosts[n - 1] - prefixCosts[start - 1];
        }

        long long currentSubarrayCost = (currentNumsSum + k) * currentCostSum;

        long long costIfCutHere = currentSubarrayCost + solve(end + 1, end + 1, k, prefixNums, prefixCosts, dp);
        long long costIfExtend = solve(start, end + 1, k, prefixNums, prefixCosts, dp);

        return dp[start][end] = min(costIfCutHere, costIfExtend);
    }

    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n = nums.size();
        vector<long long> prefixNums(n), prefixCosts(n);
        prefixNums[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixNums[i] = prefixNums[i - 1] + nums[i];
        }

        prefixCosts[0] = cost[0];
        for (int i = 1; i < n; i++) {
            prefixCosts[i] = prefixCosts[i - 1] + cost[i];
        }

        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return solve(0, 0, k, prefixNums, prefixCosts, dp);
    }
};
