class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }
        for (auto &p : pos) {
            sort(p.second.begin(), p.second.end());
        }
        vector<int> ans;
        auto dist = [&](int i, int j) {
            int d = abs(i - j);
            return min(d, n - d);
        };
        for (int q : queries) {
            int val = nums[q];
            auto &v = pos[val];
            if (v.size() == 1) {
                ans.push_back(-1);
            } else {
                int cand = INT_MAX;
                int posIdx = lower_bound(v.begin(), v.end(), q) - v.begin();
                if (posIdx > 0) {
                    cand = min(cand, dist(q, v[posIdx - 1]));
                }
                if (posIdx + 1 < v.size()) {
                    cand = min(cand, dist(q, v[posIdx + 1]));
                }
                if (v.front() != q) {
                    cand = min(cand, dist(q, v.front()));
                }
                if (v.back() != q) {
                    cand = min(cand, dist(q, v.back()));
                }
                ans.push_back(cand);
            }
        }
        return ans;
    }
};