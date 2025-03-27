class Solution {
    public:
        using ll = long long;
        
        ll computeSteps(ll l, ll r) {
            ll cnt = 0, low = 1;
            for (int k = 1; ; k++) {
                if (low > r) break;
                ll high = low * 4 - 1;
                ll left = max(l, low);
                ll right = min(r, high);
                if (left <= right) cnt += (right - left + 1) * k;
                low *= 4;
            }
            return cnt;
        }
        
        ll minOperations(vector<vector<int>>& queries) {
            ll ans = 0;
            for (auto &q : queries) {
                ll ops = computeSteps(q[0], q[1]);
                ans += (ops + 1) / 2;
            }
            return ans;
        }
    };