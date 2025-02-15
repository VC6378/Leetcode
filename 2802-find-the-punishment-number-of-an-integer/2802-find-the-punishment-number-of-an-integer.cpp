class Solution {
public:
    bool isPunished(int n, int ogNum, int curNum, int mod) {
        if (curNum == ogNum and n == 0)
            return 1;
        if (curNum > ogNum || n == 0 || n * 10 < mod)
            return 0;
        if (isPunished(n / mod, ogNum, curNum + (n % mod), 10))
            return 1;
        if (isPunished(n, ogNum, curNum, mod * 10))
            return 1;
        return 0;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int num = 1; num <= n; ++num) {
            int sq = num * num * 1LL;
            if (isPunished(sq, num, 0, 10))
                res += sq;
        }
        return res;
    }
};